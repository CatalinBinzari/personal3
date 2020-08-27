
/*****************************************************************************/
/* Name:   main.c                                                            */
/*                                                                           */
/* Purpose:  Find the maximum and the minimum of 3 integers                  */
/*                                                                           */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main(int argc, char **argv)
{
  double num1;
  double num2;
  double num3;

  printf("Enter the first number: ");
  scanf("%lf", &num1);
  printf("Enter the second number: ");
  scanf("%lf", &num2);
  printf("Enter the third number: ");
  scanf("%lf", &num3);

  printf("Maximum: %d\n", maximum(num1, num2, num3));
  printf("Minimum: %d\n", minimum(num1, num2, num3));
  return 0;
} /* main */
