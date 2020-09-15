
/* 
  Name:     client.c   

  Purpose:  Conains fuctions which make main file more readable
*/

#include "client.h"
#include <stdio.h>

/*
  Name:        get_value

  Purpose:     Get data from user and store to struct field

  Params:      IN  mess - pointer to message struct

  Returns:     Nothing
*/
void get_value(message *mess)
{
  printf("Enter text message:\n");
  scanf("%s", mess->value);
  mess->type = TO_UPPER;
} /* get_value */
