
/*
  Name:        test_main.c

  Purpose:     This file contains tests for time conversion functions
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/time.h"
void count_years_valid(void **state);
void count_days_valid(void **state);
void minutes_to_years_and_days_valid(void **state);
void minutes_to_years_and_days_minus(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(count_years_valid),
      cmocka_unit_test(count_days_valid),
      cmocka_unit_test(minutes_to_years_and_days_valid),
      cmocka_unit_test(minutes_to_years_and_days_minus),

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        count_years_valid

  Purpose:     Test function count_years with valid input

  Params:      IN    state
              
  Returns:     Nothing

*/
void count_years_valid(void **state)
{
  int result = count_years(1095);

  assert_int_equal(result, 3);
} /* count_years_valid */

/*
  Name:        count_days_valid

  Purpose:     Test function count_days with valid input

  Params:      IN    state
              
  Returns:     Nothing

*/
void count_days_valid(void **state)
{
  int result = count_days(1075);

  assert_int_equal(result, 345);
} /* count_days_valid */

/*
  Name:        minutes_to_years_and_days_valid

  Purpose:     Test function minutes_to_years_and_days with valid input

  Params:      IN    state
              
  Returns:     Nothing

*/
void minutes_to_years_and_days_valid( void **state)
{
  struct Time st = minutes_to_years_and_days(527600);

  assert_int_equal(st.years, 1);
  assert_int_equal(st.days, 1);
} /* minutes_to_years_and_days_valid */

/*
  Name:        minutes_to_years_and_days_minus

  Purpose:     Test function minutes_to_years_and_days_minus when minutes are < 0 

  Params:      IN    state
              
  Returns:     Nothing

*/
void minutes_to_years_and_days_minus( void **state)
{
  struct Time st = minutes_to_years_and_days(-5);

  assert_int_equal(st.years, -1);
  assert_int_equal(st.days, -1);
} /* minutes_to_years_and_days_minus */

