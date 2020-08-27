
/* 
  Name:   number.c                                                            

  Purpose:  Determines whether the number is positive, negative or zero 
            with if statement and switch statement                          
*/

#include <stdio.h>
#include "number.h"

/*
  Name:        number_state_with_if_stmt

  Purpose:     Determines whether the number is positive, negative or zero
               with if statement 

  Params:      IN    number - double type

  Returns:     -1 if negativie, 1 if positive, zero if zero
*/
int number_state_with_if_stmt(double number)
{
  int num_sign;

  if (number > 0)
  {
    num_sign = 1;
  }
  else if (number < 0)
  {
    num_sign = -1;
  }
  else
  {
    num_sign = 0;
  }

  return num_sign;

} /* number_state_with_if_stmt */

/*
  Name:        number_state_with_switch_stmt

  Purpose:     Determines whether the number is positive, negative or zero 
               with switch statement

  Params:      IN    number - double type

  Returns:     -1 if negativie, 1 if positive, zero if zero
*/
int number_state_with_switch_stmt(double number)
{
  int num_sign;

  switch (number > 0)
  {
  case 1:
    num_sign = 1;
    break;

  case 0:
    switch (number < 0)
    {
    case 1:
      num_sign = -1;
      break;
    case 0:
      num_sign = 0;
      break;
    }
    break;
  }

  return num_sign;

} /* number_state_with_switch_stmt */
