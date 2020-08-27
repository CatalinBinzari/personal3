

/* 
  Name:     number.c                                                          

  Purpose:  Perform add operations on a natural given number                
*/

#include <stdio.h>
#include "number.h"

/*
  Name:        sum_of_first_with_for

  Purpose:     Compute the sum of the first N natural numbers using for

  Params:      IN    num - number

  Returns:     a variable int representing sum
*/
int sum_of_first_with_for(int num)
{
  int sum = 0;
  int i;

  for (i = 1; i <= num; ++i)
  {
    sum += i;
  }

  return sum;
} /* sum_of_first_with_for */

/*
  Name:        sum_of_first_with_while

  Purpose:     Compute the sum of the first N natural numbers using while

  Params:      IN    num - number

  Returns:     a variable int representing sum
*/
int sum_of_first_with_while(int num)
{
  int sum = 0;
  int i = 1;

  while (i <= num)
  {
    sum += i;
    ++i;
  }

  return sum;
} /* sum_of_first_with_while */

/*
  Name:        sum_of_first_even_with_for

  Purpose:     Compute the sum of the first N natural even numbers using for

  Params:      IN    num - number

  Returns:     a variable int representing sum of even numbers
*/
int sum_of_first_even_with_for(int num)
{
  int sum = 0;
  int i;

  for (i = 1; i <= num; ++i)
  {
    if (i % 2 == 0)
    {
      sum += i;
    }
  }

  return sum;
} /* sum_of_first_even_with_for */

/*
  Name:        sum_of_first_odd_with_while

  Purpose:     Compute the sum of the first N natural odd numbers using while

  Params:      IN    num - number

  Returns:     a variable int representing sum of odd numbers
*/
int sum_of_first_odd_with_while(int num)
{
  int sum = 0;
  int i = 1;

  while (i <= num)
  {
    if (i % 2 == 1)
    {
      sum += i;
    }
    ++i;
  }

  return sum;
} /* sum_of_first_odd_with_while */
