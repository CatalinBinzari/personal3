
/* 
  Name:      main.c                                                            

  Purpose:   String manipulation using pointer arithmetics.
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <string.h>

int main(int argc, char **argv)
{

  int i = s_len("test");
  printf("%d\n", i);
  char *var = "esattyre";
  char *t = find_char("r", var);
  int index = get_index(t, var);
  printf("index: %d\n", index);

  char *out = malloc(strlen(var));
  trim_vowel(var, out);
  printf("out: %s", out);
  free(out);
  return 0;
} /* main */
