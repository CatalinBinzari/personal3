
/* 
  Name:      main.c   

  Purpose:   A program that accepts 1 integer representing number 
              of minutes used by an user and computes 
              the total amount (in cents) to pay.                            
*/

#include <stdio.h>
#include <stdlib.h>
#include "number.h"

int main(int argc, char **argv)
{
  int minutes;

  printf("Enter number of minutes: ");
  scanf("%d", &minutes);

  printf("Result fee: %d\n", pay_charge(minutes));
  
  return 0;
} /* main */
