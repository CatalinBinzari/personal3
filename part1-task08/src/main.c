
/* 
  Name:   main.c    

  Purpose:  Accepts a number and determines whether
            the number is positive, negative or zero 
*/

#include <stdio.h>
#include <stdlib.h>
#include "number.h"

int main(int argc, char **argv)
{
  int number;

  printf("Enter the number: ");
  scanf("%d", &number);

  printf("With if statement: %d\n", number_state_with_if_stmt(number));
  printf("With switch statement: %d\n", number_state_with_switch_stmt(number));

  return 0;
} /* main */
