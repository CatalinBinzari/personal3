
/*
  Header:  time.h

  Purpose: Contain functions for time convertion from time.c
           Implement structures from time_struct.h
*/


#ifndef TIME_H
#define TIME_H

#include "time_struct.h"

#define TRUE  1
#define FALSE 0

#define minutes_to_days(h) h / 1440
#define days_to_years(d) d / 365
#define remaining_days(d) d % 365

struct Time minutes_to_years_and_days(int minutes);
int count_years(int minutes);
int count_days(int minutes);
void print_time_struct(struct Time st);

#endif /* TIME_H */
