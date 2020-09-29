
/* 
  Name:      main.c                                                            

  Purpose:   TODO
*/

#include "../include/config.h"

int main(int argc, char **argv)
{
  char output[VALUE_LENGTH];
  int output_length;
  bool key_was_found;
  key_was_found = get_config_value(PATH, "age", output, &output_length);
  printf("value:%s, %d, %d\n", output, output_length, key_was_found);

  return 0;
} /* main */
