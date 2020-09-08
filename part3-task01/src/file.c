
/* 
  Name:      file.c 

  Purpose:   File manipulation
*/

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include <stdbool.h>
#include <string.h>

/*
  Name:        replaceAll

  Purpose:     Replace char/strings with the given from user one

  Params:      IN str - a row from a file
               IN oldWord - string to be replaced
               IN newWord - string to replace with
               IN/OUT counter - number of replacement times             

  Returns:     Nothing
*/
void replace_all(char *str, const char *old_word, const char *new_word, int *counter)
{
  char *pos, temp[BUFFER_SIZE];
  int index = 0;
  int owlen;

  owlen = strlen(old_word);

  while ((pos = strstr(str, old_word)) != NULL)
  {
    strcpy(temp, str);
    index = pos - str;
    str[index] = '\0';
    strcat(str, new_word);
    strcat(str, temp + index + owlen);

    ++*counter;
  }
} /* replaceAll */

/*
  Name:        replaceAll

  Purpose:     Conact 3 strings

  Params:      IN str - a row from a file
               IN str - a row from a file
               IN str - a row from a file

  Returns:     Char pointer, meaning the concatenated string
*/
char* concat(const char *s1, const char *s2, const char *s3)
{
    char *result = malloc(strlen(s1) + strlen(s2) + strlen(s3) + 1);
    if (result == NULL){
      printf("Not enought memory.\n");
      exit(EXIT_SUCCESS);
    }

    strcpy(result, s1);
    strcat(result, s2);
    strcat(result, s3);
    
    return result;
} /* concat */
