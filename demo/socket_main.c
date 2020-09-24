#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>

/*
Summary:

  Documentation:
    errno       https://en.cppreference.com/w/cpp/error/errno
    strerror    http://www.cplusplus.com/reference/cstring/strerror/

    socket      https://man7.org/linux/man-pages/man7/socket.7.html
    setsockopt  https://man7.org/linux/man-pages/man2/setsockopt.2.html
    bind        https://man7.org/linux/man-pages/man2/bind.2.html
    listen      https://man7.org/linux/man-pages/man2/listen.2.html
    connect     https://man7.org/linux/man-pages/man2/connect.2.html
    accept      https://man7.org/linux/man-pages/man2/accept.2.html
    send        https://man7.org/linux/man-pages/man2/send.2.html
    recv        https://man7.org/linux/man-pages/man2/recv.2.html

    select      https://man7.org/linux/man-pages/man2/select.2.html
    htons       https://linux.die.net/man/3/htons
    inet_pton   https://www.man7.org/linux/man-pages/man3/inet_pton.3.html
    inet_ntop   https://www.man7.org/linux/man-pages/man3/inet_ntop.3.html

  General overview:
     +--------+             +--------+
     | Server |             | Client |
     +--------+             +--------+
      socket                 socket
      setsockopt             
      bind
      listen <-+    <==      connect             
               |
      accept --+
      send/receive  <==>     send/receive

  More details / examples: https://www.geeksforgeeks.org/socket-programming-cc/
*/

/*
  Name:    print_socket_error

  Purpose: prints the error message in stderr based on errno
  
  Params:  IN function_name - indicates which function has thrown the error

  Returns: Nothing
*/
void print_socket_error(const char* function_name)
{
  fprintf(stderr, "[ERROR] %s::%s\n", function_name, strerror(errno));
} /* print_socket_error */

/*
  Name:    socket_pending_data

  Purpose: checks if there is any pending data on the socket fd
  
  Params:  IN socket_fd - the socket fd to be checked

  Returns: 1 if there is pending data
           0 if there is no pending data
*/
int socket_pending_data(int socket_fd)
{
  fd_set set;
  FD_ZERO(&set);
  FD_SET(socket_fd, &set);

  struct timeval tv;
  tv.tv_sec = 0;
  tv.tv_usec = 0;

  return (select(socket_fd + 1, &set, NULL, NULL, &tv) > 0);
} /* socket_pending_data */

#define PORT_NO 0xDEAD

int main() {
  int server_fd;
  struct sockaddr_in server_address;
  unsigned int server_address_length = sizeof(server_address);
  const char* server_message = "Hello friend!";
  // include the '\0'
  const unsigned int server_message_length = strlen(server_message) + 1;
  int client_fd;
  struct sockaddr_in client_address;
  unsigned int client_address_length = sizeof(client_address);
  char buffer[256];
  // Temporary value used for function return codes
  int status; 
  int option_value;

  printf("Select the application type:\n  1 - Server\n  2 - Client\n");
  scanf("%d", &status);

  if (status == 1)
  {
    // Create the socket handle
    printf("[INFO] Create the server socket file descriptor\n");
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
      print_socket_error("socket");
      return 1;
    }

    // Set socket options
    printf("[INFO] Set the socket options\n");
    option_value = 1;
    status = setsockopt(server_fd, 
                        SOL_SOCKET, 
                        SO_REUSEADDR | SO_REUSEPORT, 
                        &option_value, 
                        sizeof(option_value));
    if (status != 0)
    {
      print_socket_error("setsockopt");
      return 1;
    }

    memset(&server_address, 0, server_address_length);
    server_address.sin_family = AF_INET;  // IPv4
    server_address.sin_port = htons(PORT_NO);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to the address
    printf("[INFO] Bind the socket to the address\n");
    status = bind(server_fd, 
                  (struct sockaddr*)&server_address, 
                  server_address_length);
    if (status < 0)
    {
      print_socket_error("bind");
      return 1;
    }

    // Listen for new connections
    printf("[INFO] Start listening for new connections\n");
    status = listen(server_fd, 8);
    if (status == -1)
    {
      print_socket_error("listen");
      return 1;
    }

    printf("[INFO] Listening for new connections\n");

    // Accept new connections
    memset(&client_address, 0, client_address_length);
    client_fd = accept(server_fd, 
                       (struct sockaddr*)&client_address, 
                       &client_address_length);
    if ((client_fd == -1) || (client_address_length == 0))
    {
      print_socket_error("accept");
      return 1;
    }

    printf("[INFO] Accepted new connection\n");

    // Send message
    status = send(client_fd, server_message, server_message_length, 0);
    if (status != server_message_length)
    {
      print_socket_error("send");
      return 1;
    }

    printf("Sent %d bytes: \"%s\"\n", server_message_length, server_message);
  }
  else if (status == 2)
  {
    // Create the socket handle
    printf("[INFO] Create the client socket file descriptor\n");
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1)
    {
      print_socket_error("socket");
      return 1;
    }

    // Setup server address
    memset(&server_address, 0, server_address_length);
    server_address.sin_family = AF_INET;  // IPv4
    server_address.sin_port = htons(PORT_NO);
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) != 1) {
      print_socket_error("inet_pton");
      return 1;
    }

    // Connect to the server
    printf("[INFO] Connect to the server's address\n");
    status = connect(client_fd, 
                     (struct sockaddr*)&server_address, 
                     server_address_length);
    if (status == -1)
    {
      print_socket_error("connect");
      return 1;
    }

    printf("[INFO] Connected to the server.\n");

    // Receive messages until error or connection close by server
    while (1)
    {
      // Check if there is any pending data for the client_fd
      if (socket_pending_data(client_fd) == 1)
      {
        // Receive the message and check the returned value as per the documents
        status = recv(client_fd, buffer, sizeof(buffer), 0);
        if (status < 0)
        {
          print_socket_error("recv");
          return 1;
        }
        else if (status > 0)
        {
          printf("Received %d bytes: \"%s\"\n", status, buffer);
        }
        else
        {
          printf("[INFO] Connection closed by the served\n");
          return 0;
        }
      }
    }
  }
  else
  {
    printf("Invalid input\n");
  }

  printf("[INFO] Exit program\n");

  return 0;
} /* main */
