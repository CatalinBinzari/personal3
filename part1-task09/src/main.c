

/* 
  Name:      main.c                                                            
  
  Purpose:   This is a C program to print the name for the day, 
             based on number of the day in a week                     
*/


#include <stdio.h>
#include <stdlib.h>
#include "number.h"

int main(int argc, char **argv)
{
  int day_number;

  printf("Enter the day number: ");
  scanf("%d", &day_number);

  printf("Day: %s\n", number_to_day(day_number));

  return 0;
} /* main */
