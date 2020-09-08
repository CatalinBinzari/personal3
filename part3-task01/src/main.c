
/* 
  Name:      main.c                                                            

  Purpose:   Replaace chars of words in the file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
int main()
{
  FILE *f_ptr;
  FILE *f_temp;
  char path[100];
  int counter = 0;

  char buffer[BUFFER_SIZE];
  char old_word[100], new_word[100];

  printf("Enter path of source file: ");
  scanf("%s", path);

  printf("Enter word to replace: ");
  scanf("%s", old_word);

  printf("Replace '%s' with: ", old_word);
  scanf("%s", new_word);

  f_ptr = fopen(path, "r");
  f_temp = fopen("replace.tmp", "w");

  if (f_ptr == NULL)
  {
    strcpy(path, "/home/user/workspace/part3-task01/src/in.txt");
    f_ptr = fopen(path, "r");
    printf("Source file not found, default source file is used!\n");
  }

  if (f_ptr == NULL || f_temp == NULL)
  {
    printf("\nUnable to open file.\n");
    printf("Please check whether file exists and you have read/write privilege.\n");
    exit(EXIT_SUCCESS);
  }

  while ((fgets(buffer, BUFFER_SIZE, f_ptr)) != NULL)
  {
    replace_all(buffer, old_word, new_word, &counter);
    fputs(buffer, f_temp);
  }

  if (counter == 0)
  {
    char *last_row = concat("<'", old_word, "'> added at the end of file.>");
    fputs(last_row, f_temp);
    free(last_row);
  }

  fclose(f_ptr);
  fclose(f_temp);
  remove(path);
  rename("replace.tmp", path);
  printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.\n", old_word, new_word);

  return 0;
} /* main */
