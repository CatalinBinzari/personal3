
/* 
  Name:      main.c                                                            

  Purpose:   Add two fractions and display the resulting fraction  
*/

#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"

int main(int argc, char **argv)
{
  struct fraction frac1;
  struct fraction frac2;

  printf("Enter first fraction: \n");
  printf("Numerator: ");
  scanf("%d", &frac1.numerator);
  printf("Denominator: ");
  scanf("%d", &frac1.denominator);

  printf("\nEnter the second fraction: \n");
  printf("Numerator: ");
  scanf("%d", &frac2.numerator);
  printf("Denominator: ");
  scanf("%d", &frac2.denominator);

  struct fraction res;
  res = add(frac1, frac2);

  display(res);
  return 0;
} /* main */
