
/* 
  Name:      main.c                                                            

  Purpose:   Print all 'key-value' pairs from 'values.ini' file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

int main()
{
  dict_t **dict = dict_alloc();
  parse_file(PATH, dict);

  printf("\nDictionary items:\n");
  print_all(*dict);
  dict_dealloc(dict);
  return 0;
} /* main */
