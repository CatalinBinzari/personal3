
/* 
  Name:      main.c                                                            

  Purpose:   Get pecific data in specific format from config.ini file
*/

#include "config.h"

int main(int argc, char **argv)
{
  int output_length = 200;
  char output[output_length + 1];
  char ip[20];
  unsigned short port;
  bool key_was_found;

  key_was_found = get_config_value(PATH, "age", output, output_length);
  printf("value: %s, length: %d, found: %d\n", output, output_length, key_was_found);

  key_was_found = get_server_address(PATH, "addr", ip, &port);
  printf("\nvalue: %s, %d\n", ip, port);

  return 0;
} /* main */
