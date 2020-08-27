

/* 
  Name:      string.c   

  Purpose:   Containt functions which counts elements of a string  
*/

#include <stdio.h>
#include "string.h"

/*
  Name:        count_elements

  Purpose:     Count alphabets, special characters and digits 

  Params:      IN  str - string 

  Returns:     a struct with 3 integers 
*/

struct string_elements count_elements(char *str)
{
  int i;
  struct string_elements elements;
  elements.alphabets = 0;
  elements.special_chars = 0;
  elements.digits = 0;

  for (i = 0; str[i] != '\0'; ++i)
  {
    if (((str[i] >= 'a') && (str[i] <= 'z')) || 
        ((str[i] >= 'A') && (str[i] <= 'Z')))
    {
      ++elements.alphabets;
    }
    else if ((str[i] >= '0') &&
             (str[i] <= '9'))
    {
      ++elements.digits;
    }
    else
    {
      ++elements.special_chars;
    }
  }

  return elements;
} /* count_elements */
