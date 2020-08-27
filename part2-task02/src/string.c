
/* 
  Name:      string.c   

  Purpose:   Contains functions for converting a string to uppercase   
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/*
  Name:        to_upper

  Purpose:     Convert string to uppercase

  Params:      IN/OUT  lowercase_str - pointer to char array

  Returns:     Nothing
*/
void to_upper(char *lowercase_str)
{
  int i;

  for (i = 0; lowercase_str[i] != '\0'; i++)
  {
    if (lowercase_str[i] >= 'a' && lowercase_str[i] <= 'z')
    {
      lowercase_str[i] -= 32;
    }
  }

} /* to_upper */
