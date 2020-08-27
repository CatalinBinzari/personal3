
/*
  Name:        test_main.c

  Purpose:     This file contains tests for rectangle aria and perimeter
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/rectangle.h"

void test_rectangle_aria_valid(void **state);
void test_rectangle_aria_zero_length(void **state);
void test_rectangle_aria_zero_width(void **state);
void test_rectangle_perimeter_valid(void **state);
void test_rectangle_perimeter_zero_length(void **state);
void test_rectangle_perimeter_zero_width(void **state);
void test_rectangle_perimeter_zero_width_zero_length(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_rectangle_aria_valid),
      cmocka_unit_test(test_rectangle_aria_zero_length),
      cmocka_unit_test(test_rectangle_aria_zero_width),
      cmocka_unit_test(test_rectangle_perimeter_valid),
      cmocka_unit_test(test_rectangle_perimeter_zero_length),
      cmocka_unit_test(test_rectangle_perimeter_zero_width),
      cmocka_unit_test(test_rectangle_perimeter_zero_width_zero_length)

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        test_rectangle_aria_valid

  Purpose:     testing if the rectangle_aria function gives valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void test_rectangle_aria_valid(void **state)
{
  int result = rectangle_area(100, 200);

  assert_int_equal(result, 20000);
} /* test_rectangle_aria_valid */

/*
  Name:        test_rectangle_aria_zero_length

  Purpose:     Test that rectangle_area fails when the length is 0.

  Params:      IN    state
              
  Returns:     Nothing
*/
void test_rectangle_aria_zero_length(void **state)
{
  int result = rectangle_area(0, 200);

  assert_int_equal(result, -1);
} /* test_rectangle_aria_zero_length */

/*
  Name:        test_rectangle_aria_zero_width

  Purpose:     Test that rectangle_area fails when the width is 0.

  Params:      IN    state
              
  Returns:     Nothing
*/
void test_rectangle_aria_zero_width(void **state)
{
  int result = rectangle_area(100, 0);

  assert_int_equal(result, -1);
} /* test_rectangle_aria_zero_width */

/*
  Name:        test_rectangle_perimeter_valid

  Purpose:     testing if rectangle_perimeter is valid

  Params:      IN    state
              
  Returns:     Nothing
*/
void test_rectangle_perimeter_valid(void **state)
{
  int result = rectangle_perimeter(10, 20);

  assert_int_equal(result, 60);
} /* test_rectangle_perimeter_valid */

/*
  Name:        test_rectangle_perimeter_zero_length

  Purpose:     Test that rectangle_perimeter fails when the length is 0.

  Params:      IN    state
              
  Returns:     Nothing
*/
void test_rectangle_perimeter_zero_length(void **state)
{
  int result = rectangle_perimeter(0, 200);

  assert_int_equal(result, -1);
} /* test_rectangle_perimeter_zero_length */

/*
  Name:        test_rectangle_perimeter_zero_width

  Purpose:     Test that rectangle_perimeter fails when the width is 0.

  Params:      IN    state
              
  Returns:     Nothing
*/
void test_rectangle_perimeter_zero_width(void **state)
{
  int result = rectangle_perimeter(100, 0);

  assert_int_equal(result, -1);
} /* test_rectangle_perimeter_zero_width */

/*
  Name:        test_rectangle_perimeter_zero_width_zero_length

  Purpose:     Test that rectangle_perimeter fails when the width is 0 and length is 0.

  Params:      IN    state
              
  Returns:     Nothing
*/
void test_rectangle_perimeter_zero_width_zero_length(void **state)
{
  int result = rectangle_perimeter(0, 0);

  assert_int_equal(result, -1);
} /* test_rectangle_perimeter_zero_width_zero_length */
