

/* 
  Name:     number.c                                                         

  Purpose:  Calculate the day of the week based 
            on the number we get from user   
*/

#include <stdio.h>
#include "number.h"

/*
  Name:        number_to_day

  Purpose:     Calculate the day of the week based 
               on the number we get from user with switch statement 

  Params:      IN    number - double type

  Returns:     a variable string representing the day of the week, ex: Monday
*/
const char *number_to_day(int day_number)
{
  char *day;

  switch (day_number)
  {
  case MONDAY:
    day = "Monday";
    break;
  case TUESDAY:
    day = "Tuesday";
    break;
  case WEDNESDAY:
    day = "Wednesday";
    break;
  case THURSDAY:
    day = "Thursday";
    break;
  case FRIDAY:
    day = "Friday";
    break;
  case SATURDAY:
    day = "Saturday";
    break;
  case SUNDAY:
    day = "Sunday";
    break;
  default:
    day = "Not a week day";
    break;
  }

  return day;

} /* number_to_day */
