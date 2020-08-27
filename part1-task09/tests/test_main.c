
/*
  Name:        test_main.c

  Purpose:     This file contains tests for converting a number to day 
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/number.h"
void number_to_day_valid(void **state);
void number_to_day_invalid(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(number_to_day_valid),
      cmocka_unit_test(number_to_day_invalid),

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        number_to_day_valid

  Purpose:     Test that number_to_day working correctly with a valid value

  Params:      IN    state
              
  Returns:     Nothing

*/
void number_to_day_valid(void **state)
{
  const char *name = number_to_day(3);

  assert_string_equal("Wednesday", name);
} /* number_to_day_valid */

/*
  Name:        number_to_day_invalid

  Purpose:     Test that number_to_day working correctly with a invalid value

  Params:      IN    state
              
  Returns:     Nothing

*/
void number_to_day_invalid(void **state)
{
  const char *name = number_to_day(343);

  assert_string_equal("Not a week day", name);
} /* number_to_day_invalid */
