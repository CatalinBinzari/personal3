
/*****************************************************************************/
/* Name:   main.c                                                            */
/*                                                                           */
/* Purpose:  Perform  math operations on 2 numbers                           */
/*                                                                           */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main(int argc, char **argv)
{
  double num1;
  double num2;

  printf("Enter the first number: ");
  scanf("%lf", &num1);
  printf("Enter the second number: ");
  scanf("%lf", &num2);

  printf("Sum: %f\n", sum(num1, num2));
  printf("Difference: %f\n", difference(num1, num2));
  printf("Product: %f\n", product(num1, num2));
  printf("Division: %f\n", division(num1, num2));
  printf("Modulus: %f\n", modulus(num1, num2));
  printf("Average: %f\n", average(num1, num2));
  printf("Minimum: %f\n", minimum(num1, num2));
  printf("Maximum: %f\n", maximum(num1, num2));
  return 0;
} /* main */
