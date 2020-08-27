
/*
  Name:        test_main.c

  Purpose:     This file contains tests for add natural numbers functions 
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/number.h"
void sum_of_first_with_for_valid(void **state);
void sum_of_first_with_while_valid(void **state);
void sum_of_first_even_with_for_valid(void **state);
void sum_of_first_odd_with_while_valid(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(sum_of_first_with_for_valid),
      cmocka_unit_test(sum_of_first_with_while_valid),
      cmocka_unit_test(sum_of_first_even_with_for_valid),
      cmocka_unit_test(sum_of_first_odd_with_while_valid),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        sum_of_first_with_for_valid

  Purpose:     Test that sum_of_first_with_for gives valid result

  Params:      IN    state
              
  Returns:     Nothing

*/
void sum_of_first_with_for_valid(void **state)
{
  int sum = sum_of_first_with_for(5);
  assert_int_equal(sum, 15);
} /* sum_of_first_with_for_valid */

/*
  Name:        sum_of_first_with_while_valid

  Purpose:     Test that sum_of_first_with_while_valid gives valid result

  Params:      IN    state
              
  Returns:     Nothing

*/
void sum_of_first_with_while_valid(void **state)
{
  int sum = sum_of_first_with_while(5);
  assert_int_equal(sum, 15);
} /* sum_of_first_with_while_valid */

/*
  Name:        sum_of_first_even_with_for_valid

  Purpose:     Test that sum_of_first_even_with_for_valid gives valid result

  Params:      IN    state
              
  Returns:     Nothing

*/
void sum_of_first_even_with_for_valid(void **state)
{
  int sum = sum_of_first_even_with_for(5);
  assert_int_equal(sum, 6);
} /* sum_of_first_even_with_for_valid */

/*
  Name:        sum_of_first_odd_with_while_valid

  Purpose:     Test that sum_of_first_odd_with_while_valid gives valid result

  Params:      IN    state
              
  Returns:     Nothing

*/
void sum_of_first_odd_with_while_valid(void **state)
{
  int sum = sum_of_first_odd_with_while(5);
  assert_int_equal(sum, 9);
} /* sum_of_first_odd_with_while_valid */
