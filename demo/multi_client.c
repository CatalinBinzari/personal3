#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>

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

/*
  Name:    read_line

  Purpose: read a null terminated line from the file. The output will be 
           truncated if the input length is greated than the output_length.
           This is a non-blocking function.
  
  Params:  IN output        - the destination buffer for the line
           IN output_length - the max length of the destination buffer
           IN file          - the source file to be read

  Returns: number of characters read
*/
unsigned int read_line(char* output, unsigned int output_length, FILE* file)
{
  int c;
  int length = 0;

  if (socket_pending_data(fileno(file)) == 0)
  {
    return length;
  }

  for (length = 0; length < output_length - 1; ++length)
  {
    c = fgetc(file);
    switch (c)
    {
      case '\0' :
      case '\n' :
      case EOF  :
        output[length] = '\0';
        return length;
      default :
        output[length] = (char)c;
        break;
    }
  }
  output[length] = '\0';
  return length;
} /* read_line */

#define PORT_NO 0xDEAD

typedef struct client_data
{
  int socket_fd;
  struct sockaddr_in address;
  unsigned int address_length;
  int active;
} CLIENT_DATA;

/*
  Name:    server_main

  Purpose: runs the server application
  
  Params:  None

  Returns: Nothing
*/
void server_main()
{
  int server_fd;
  struct sockaddr_in server_address;
  unsigned int server_address_length = sizeof(server_address);
  const char* server_message = "Hello friend!";
  const unsigned int server_message_length = strlen(server_message) + 1;
  int status; 
  int option_value;
  int running = 1;

  // Support up to 8 clients
  CLIENT_DATA clients[8];
  unsigned int client_count = 0;
  char receive_buffer[256];
  char send_buffer[256];
  unsigned int send_buffer_length;

  // Create the socket handle
  printf("[INFO] Create the server socket file descriptor\n");
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == -1)
  {
    print_socket_error("socket");
    return;
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
    return;
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
    return;
  }

  // Listen for new connections
  printf("[INFO] Start listening for new connections\n");
  status = listen(server_fd, 8);
  if (status == -1)
  {
    print_socket_error("listen");
    return;
  }

  printf("[INFO] Listening for new connections\n");

  memset(clients, 0, sizeof(CLIENT_DATA) * 8);

  // Main loop
  while (running == 1)
  {
    // Check if there is any incoming data on the server's listening socket
    if (socket_pending_data(server_fd) == 1)
    {
      // Check that we can accept more clients
      if (client_count < 8)
      {
        // Accept the new connection and store it's socket and address
        clients[client_count].socket_fd = accept(
                              server_fd, 
                              (struct sockaddr*)&clients[client_count].address, 
                              &clients[client_count].address_length);
        clients[client_count].active = 1;
        printf("Client %u has connected.\n", client_count);
        ++client_count;
      }
    }

    // Check incomming messages from active clients
    for (unsigned int index = 0; index < client_count; ++index)
    {
      // Check if there is any incoming data from the clients[index]
      if ((socket_pending_data(clients[index].socket_fd) == 1) && (clients[index].active == 1))
      {
        status = recv(clients[index].socket_fd, receive_buffer, sizeof(receive_buffer), 0);
        if (status < 0)
        {
          print_socket_error("recv");
          clients[index].active = 0;
        }
        else if (status > 0)
        {
          printf("Received %d bytes from client %u: %s\n", index, status, receive_buffer);

          // Redirect message to all clients
          for (unsigned int index2 = 0; index2 < client_count; ++index2)
          {
            // Append client id to the message
            send_buffer_length = sprintf(send_buffer, "Client %d: %s", index, receive_buffer);
            send(clients[index2].socket_fd, send_buffer, send_buffer_length + 1, 0);
          }
        }
        else
        {
          printf("Client %u has disconnected.\n", index);
          clients[index].active = 0;
        }
      }
    }
  }
} /* server_main */

/*
  Name:    client_main

  Purpose: runs the client application
  
  Params:  None

  Returns: Nothing
*/
void client_main()
{
  int client_fd;
  struct sockaddr_in server_address;
  unsigned int server_address_length = sizeof(server_address);
  char buffer[256];
  unsigned int buffer_length;
  int status;

  // Create the socket handle
  printf("[INFO] Create the client socket file descriptor\n");
  client_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (client_fd == -1)
  {
    print_socket_error("socket");
    return;
  }

  // Setup server address
  memset(&server_address, 0, server_address_length);
  server_address.sin_family = AF_INET;  // IPv4
  server_address.sin_port = htons(PORT_NO);
  if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) != 1) {
    print_socket_error("inet_pton");
    return;
  }

  // Connect to the server
  printf("[INFO] Connect to the server's address\n");
  status = connect(client_fd, 
                   (struct sockaddr*)&server_address, 
                   server_address_length);
  if (status == -1)
  {
    print_socket_error("connect");
    return;
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
        return;
      }
      else if (status > 0)
      {
        printf("%s\n", buffer);
      }
      else
      {
        printf("[INFO] Connection closed by the served\n");
        return;
      }
    }

    buffer_length = read_line(buffer, sizeof(buffer), stdin);
    if (buffer_length > 0)
    {
      send(client_fd, buffer, buffer_length + 1, 0);
    }
  }
} /* client_main */

int main()
{
  int input;
  printf("Select the application type:\n  1 - server\n  2 - client\n");
  scanf("%d", &input);

  switch(input)
  {
    case 1 :
      server_main();
      break;
    case 2 :
      client_main();
      break;
  }

  return 0;
}
