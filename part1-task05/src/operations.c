
/*****************************************************************************/
/* Name:   operations.c                                                      */
/*                                                                           */
/* Purpose:  Find the maximum and the minimum of 3 integers                  */
/*                                                                           */
/*****************************************************************************/

#include "operations.h"

/*
  Name:        maximum

  Purpose:     return maximum from 3 input numbers

  Params:      IN    num1  - integer
               IN    num2  - integer
               IN    num3  - integer

  Returns:  a variable value
*/
int maximum(int num1, int num2, int num3)
{
  return ((num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3));
} /* maximum */

/*
  Name:        minimum

  Purpose:     return minimum from 3 input numbers

  Params:      IN    num1  - integer
               IN    num2  - integer
               IN    num3  - integer

  Returns:  a variable value
*/
int minimum(int num1, int num2, int num3)
{
  return ((num1 < num2) ? ((num1 < num3) ? num1 : num3) : ((num2 < num3) ? num2 : num3));
} /* minimum */
