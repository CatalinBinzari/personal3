
/* 
  Name:     server.c

  Purpose:  Conains fuctions which make main file more readable
*/

#include "server.h"
#include <stdio.h>

/*
  Name:        to_upper

  Purpose:     Convert string to uppercse

  Params:      IN  mess_value - string value from message struct

  Returns:     Nothing
*/
void to_upper(char *mess_value)
{
  for (int i = 0; mess_value[i] != '\0'; i++)
  {
    if (mess_value[i] >= 'a' && mess_value[i] <= 'z')
    {
      mess_value[i] = mess_value[i] - UPPER_TO_LOWER;
    }
  }
} /* to_upper */

/*
  Name:        double_number

  Purpose:     Get number as string, double it and store back as string

  Params:      IN  mess_value - string value from message struct

  Returns:     Nothing
*/
void double_number(char *mess_value)
{
  double input_number;
  sscanf(mess_value, "%lf", &input_number);
  input_number *= 2;
  snprintf(mess_value, 1024, "%f", input_number);
} /* double_number */
