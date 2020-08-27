
/* 
  Name:     main.c                                                            
  
  Purpose:  Get a value of minutes and returns number of years and days  
*/


#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include <limits.h>

int main(int argc, char **argv)
{
  long lval;

  printf("Enter the first number: ");
  scanf("%ld", &lval);

  printf("Sum: %d\n", sum_of_digits(lval));
  return 0;
} /* main */
