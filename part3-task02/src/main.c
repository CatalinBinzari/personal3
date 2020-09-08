
/* 
  Name:      main.c                                                            

  Purpose:   Diplay number of words, characters, number of lines, number of digits from a file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

int main()
{
  FILE *f_ptr;
  statistic stats = {0};
  char path[100];

  printf("Enter path of source file: ");
  scanf("%s", path);

  f_ptr = fopen(path, "r");

  if (f_ptr == NULL)
  {
    strcpy(path, "/home/user/workspace/part3-task02/src/in.txt");
    f_ptr = fopen(path, "r");
    printf("Source file not found, default source file is used!\n");
  }

  if (f_ptr == NULL)
  {
    printf("\nUnable to open file.\n");
    printf("Please check whether file exists and you have read/write privilege.\n");
    exit(EXIT_SUCCESS);
  }

  parse_file(f_ptr, &stats);

  display_stats(&stats);

  fclose(f_ptr);

  printf("\nSuccessfully displayed all occurrences.\n");

  return 0;
} /* main */
