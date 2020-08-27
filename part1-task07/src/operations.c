
/*
  Name:     operations.c                                                      
  
  Purpose:  Contain algorithm to calculat the sum of digits                
*/


#include "operations.h"

/*
  Name:        sum_of_digits

  Purpose:     Calculate the sum of digits from a long number

  Params:      IN    lnum - long number

  Returns:     an integer representing the sum of the digits
*/
int sum_of_digits(long lnum)
{
  int sign = lnum >= 0 ? 1 : -1;
  int sum = 0;
  int rem_val;

  while(lnum != 0)
  {
    rem_val = lnum % 10;
    sum += rem_val;
    lnum = lnum / 10;
  }

  return (sum * sign);
} /* sum_of_digits */
