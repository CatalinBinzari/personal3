
/*****************************************************************************/
/* Name:   main.c                                                            */
/*                                                                           */
/* Purpose:  Get a value of minutes and returns the number of years and days */
/*                                                                           */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"


int main(int argc, char **argv)
{
  int minutes;

  printf("Enter number of the minutes: ");
  scanf("%d", &minutes);

  print_time_struct(minutes_to_years_and_days(minutes));
  return 0;
} /* main */
