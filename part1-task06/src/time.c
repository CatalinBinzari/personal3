
/*****************************************************************************/
/* Name:   time.c                                                            */
/*                                                                           */
/* Purpose:  Calculate the numbers of years and days,
             based on number of minutes                                      */
/*                                                                           */
/*****************************************************************************/

#include <stdio.h> 
#include "time.h"


/*
  Name:        minutes_to_years_and_days

  Purpose:     Convert minutes to years and days

  Params:      IN    minutes - number of minutes

  Returns:   a structure=(1, -1) if invalid, else a structure=(years, days)
*/
struct Time minutes_to_years_and_days(int minutes)
{
  struct Time st;
  int tmp_days;

  if (minutes < 0)
  {
    st.years = -1;
    st.days = -1;

    return st;
  }
  tmp_days = minutes_to_days(minutes);
  st.years= count_years(tmp_days);
  st.days = count_days(tmp_days);
   
  return (st);
} /* minutes_to_years_and_days */

/*
  Name:        count_years

  Purpose:     Convert days to years

  Params:      IN    days - number of days

  Returns:   a variable value
*/
int count_years(int days)
{
  return days_to_years(days);
} /* counte_years */

/*
  Name:        count_days

  Purpose:     Calculate remaining days in a year

  Params:      IN    days - number of days

  Returns:   a variable value
*/
int count_days(int days)
{
  return remaining_days(days);
} /* count_days */

/*
  Name:        print_time_struct

  Purpose:     prints Time structure

  Params:      IN    st - Time structure

  Returns:     Nothing
*/
void print_time_struct(struct Time st)
{
  printf("Years: %d\n", st.years);
  printf("Days: %d\n", st.days);
} /* print_time_struct */