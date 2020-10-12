
/* 
  Name:      main.c                                                            

  Purpose:   Makes connection with server and gives ability to join channels, send messages,
             and use this program as a simple client
*/

#include "connection.h"

int main()
{
  connection conn;
  int buf_len;
  char msg[1024];
  bool key_was_found;
  char server_name[30];
  char pong_to_send[40] = "PONG :";
  int bytes_read;
  char hostname[20] = "catalin199";
  char realname[20] = "catalinbinzari";
  fd_set readfd;

  printf("Enter server name: ");
  scanf("%s", server_name);

  conn.sts = DISCONNECTED;
  strcpy(conn.nick, "catalin199");
  strcpy(conn.username, "catalin199");

  key_was_found = get_server_address(PATH, server_name, &conn.address);
  if (key_was_found)
  {
    printf("\nServer found: IP ADDRESS: %s, PORT %d\n", inet_ntoa(conn.address.sin_addr), ntohs(conn.address.sin_port));
  }
  else
  {
    printf("\nServer not found! Try to insert another server name or verify the previous.\n");
    exit(EXIT_FAILURE);
  }

  if ((conn.socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    printf("\n Socket creation error \n");
    return -1;
  }

  if (inet_pton(AF_INET, inet_ntoa(conn.address.sin_addr), &conn.address.sin_addr) <= 0)
  {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }

  if (connect(conn.socket_fd, (struct sockaddr *)&conn.address, sizeof(conn.address)) < 0)
  {
    printf("\nConnection Failed \nPlease verify if server is running\n");
    return -1;
  }

  snprintf(msg, sizeof(msg), "NICK %s\r\n", conn.nick);
  send(conn.socket_fd, msg, strlen(msg), 0);

  snprintf(msg, sizeof(msg), "USER %s %s %s :%s\r\n", conn.nick, hostname, server_name, realname);
  send(conn.socket_fd, msg, strlen(msg), 0);

  while (1)
  {
    FD_ZERO(&readfd);
    FD_SET(conn.socket_fd, &readfd);
    FD_SET(0, &readfd);

    select(conn.socket_fd + 1, &readfd, NULL, NULL, NULL);
    if (FD_ISSET(conn.socket_fd, &readfd))
    {
      bytes_read = read(conn.socket_fd, &msg, sizeof(msg));
      msg[bytes_read] = '\0';

      char *ptr_ping = strstr(msg, "PING :");
      if (ptr_ping != NULL)
      {
        /*send PONG if PING was recieved from server */
        snprintf(pong_to_send, sizeof(pong_to_send), "PONG :%s", ptr_ping + 6);
        send(conn.socket_fd, pong_to_send, strlen(pong_to_send), 0);
        conn.sts = REGISTERED;
        continue;
      }

      char *ptr_err = strstr(msg, "ERROR :");
      if (ptr_err != NULL)
      {
        /*print ERROR if ERROR was recieved from server */
        printf("[ERROR]\n%s\n", ptr_err + 7);
        exit(EXIT_FAILURE);
      }
      
      if (bytes_read == 0)
      {
        printf("Zero bytes has been read from server\nClosing client...\n");
        exit(EXIT_SUCCESS);
      }

      printf("%s\n", msg);
    }
    else if (FD_ISSET(STDIN_FILENO, &readfd))
    {
      if ((buf_len = read(STDIN_FILENO, msg, sizeof(msg))))
      {
        msg[buf_len] = '\r';
        msg[buf_len + 1] = '\n';
        msg[buf_len + 2] = '\0';

        send(conn.socket_fd, msg, strlen(msg), 0);
      }
    }
  }
  return 0;
} /* main */
