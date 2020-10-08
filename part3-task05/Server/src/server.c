
/* 
  Name:     server.c

  Purpose:  Contains fuctions which make main file more readable
*/

#include "server.h"
#include <stdio.h>

/*
  Name:        to_upper

  Purpose:     Convert string to uppercse

  Params:      IN/OUT msg_value - string value from message struct

  Returns:     Nothing
*/
void to_upper(char *msg_value)
{
  for (int i = 0; msg_value[i] != '\0'; i++)
  { 
    if (msg_value[i] >= 'a' && msg_value[i] <= 'z')
    {
      msg_value[i] -= UPPER_TO_LOWER;
    }
  }
} /* to_upper */

/*
  Name:        double_number

  Purpose:     Get number as string, double it and store back as string

  Params:      IN/OUT  msg_value - string value from message struct

  Returns:     Nothing
*/
void double_number(char *msg_value)
{
  double input_number;
  sscanf(msg_value, "%lf", &input_number);
  input_number *= 2;
  sprintf(msg_value, "%.2f", input_number);
} /* double_number */
