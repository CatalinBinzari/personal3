
/* 
  Name:     main.c   

  Purpose:  Client will send a text to the server process. 
            The server will convert the characters to uppercase and send the result to Client.
            Client prints the text it receives and then the process terminates.
*/

#include "client.h"

int main(int argc, char const *argv[])
{
  int len;
  char msg[1024];
  int sock = 0;
  int client;
  struct sockaddr_in serv_addr;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    printf("\n Socket creation error \n");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY; 
  serv_addr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
  {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    printf("\nConnection Failed \nPlease verify if server is running\n");
    return -1;
  }

  client = select_action();
  len = get_value(msg);

  char msg_text[len+=3];
  snprintf(msg_text, len, "%d:%s", client, msg);

  send(sock, msg_text, sizeof(msg_text), 0);
  printf("To server was send message: %s with size of %ld\n", msg_text, sizeof(msg_text));
  read(sock, msg, sizeof(msg));
  printf("From server was recieved message: %s with length of %ld\n", msg, strlen(msg));
  printf("%s\n", msg);

  return 0;
} /* main */
