
/*
  Name:        test_main.c

  Purpose:     in this file are tested functions from operations.c
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>

#include "../src/operations.h"

void sum_of_elements_valid_int(void **state);
void sum_of_elements_valid_max_long(void **state);
void sum_of_elements_valid_min_long(void **state);
void sum_of_elements_valid_zero(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{

  const struct CMUnitTest tests[] = {
      cmocka_unit_test(sum_of_elements_valid_int),
      cmocka_unit_test(sum_of_elements_valid_max_long),
      cmocka_unit_test(sum_of_elements_valid_min_long),
      cmocka_unit_test(sum_of_elements_valid_zero),

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        sum_of_elements_valid_int

  Purpose:     tested function sum_of_elements with valid int
*/
void sum_of_elements_valid_int(void **state)
{
  int result = sum_of_digits(1001);

  assert_int_equal(result, 2);
} /* sum_of_elements_valid_int */

/*
  Name:        sum_of_elements_valid_max_long

  Purpose:     tested function sum_of_elements with valid max long
*/
void sum_of_elements_valid_max_long(void **state)
{
  int result = sum_of_digits(9223372036854775807);

  assert_int_equal(result, 88);
} /* sum_of_elements_valid_max_long */

/*
  Name:        sum_of_elements_valid_min_long

  Purpose:     tested function sum_of_elements with valid min long
*/
void sum_of_elements_valid_min_long(void **state)
{
  int result = sum_of_digits(-9223372036854775807);

  assert_int_equal(result, 88);
} /* sum_of_elements_valid_min_long */

/*
  Name:        sum_of_elements_valid_zero

  Purpose:     tested function sum_of_elements with zero value
*/
void sum_of_elements_valid_zero(void **state)
{
  int result = sum_of_digits(0);

  assert_int_equal(result, 0);
} /* sum_of_elements_valid_zero */
