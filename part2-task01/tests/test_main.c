
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

void find_largest_valid(void **state);
void find_largest_valid_from_minus_values(void **state);
void contains_digit_near_digit_middle(void **state);
void contains_digit_near_digit_beginning(void **state);
void contains_digit_near_digit_end(void **state);
void contains_digit_near_digit_false(void **state);
void min_and_max_valid(void **state);
void display_unique_valid(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{

  const struct CMUnitTest tests[] = {
      cmocka_unit_test(find_largest_valid),
      cmocka_unit_test(find_largest_valid_from_minus_values),
      cmocka_unit_test(contains_digit_near_digit_middle),
      cmocka_unit_test(contains_digit_near_digit_beginning),
      cmocka_unit_test(contains_digit_near_digit_end),
      cmocka_unit_test(contains_digit_near_digit_false),
      cmocka_unit_test(min_and_max_valid),
      cmocka_unit_test(display_unique_valid),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        find_largest_valid

  Purpose:     tested function find_largest_valid for  valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void find_largest_valid(void **state)
{
  int arr[] = {1, 2, 3, 4};
  int result = find_largest(arr, 4);

  assert_int_equal(result, 4);
} /* find_largest_valid */

/*
  Name:        find_largest_valid_from_minus_values

  Purpose:     tested function find_largest_valid with array with minus values

  Params:      IN    state
              
  Returns:     Nothing
*/
void find_largest_valid_from_minus_values(void **state)
{
  int arr[] = {-1, -2, -3, -4};
  int result = find_largest(arr, 4);

  assert_int_equal(result, -1);
} /* find_largest_valid_from_minus_values */

/*
  Name:        contains_digit_near_digit_middle

  Purpose:     tested function contains_digit_near_digit with DIGIT and DIGIT in the middle 

  Params:      IN    state
              
  Returns:     Nothing
*/
void contains_digit_near_digit_middle(void **state)
{
  int arr[] = {-1, 3, 3, -4};
  bool result = contains_digit_near_digit(arr, 4);

  assert_true(result);
} /* contains_digit_near_digit_middle */

/*
  Name:        contains_digit_near_digit_beginning

  Purpose:     tested function contains_digit_near_digit with DIGIT and DIGIT in the beginning

  Params:      IN    state
              
  Returns:     Nothing
*/
void contains_digit_near_digit_beginning(void **state)
{
  int arr[] = {3, 3, -1, -4};
  bool result = contains_digit_near_digit(arr, 4);

  assert_true(result);
} /* contains_digit_near_digit_beginning */

/*
  Name:        contains_digit_near_digit_end

  Purpose:     tested function contains_digit_near_digit with DIGIT and DIGIT in the end

  Params:      IN    state
              
  Returns:     Nothing
*/
void contains_digit_near_digit_end(void **state)
{
  int arr[] = {1, 3, 3, 3};
  bool result = contains_digit_near_digit(arr, 4);

  assert_true(result);
} /* contains_digit_near_digit_end*/

/*
  Name:        contains_digit_near_digit_false

  Purpose:     tested function contains_digit_near_digit without 3 near 3

  Params:      IN    state
              
  Returns:     Nothing
*/
void contains_digit_near_digit_false(void **state)
{
  int arr[] = {1, 2, 3, 4};
  bool result = contains_digit_near_digit(arr, 4);

  assert_false(result);
} /* contains_digit_near_digit_false*/

/*
  Name:        min_and_max_valid

  Purpose:     Tested function min_and_max with a valid input

  Params:      IN    state
              
  Returns:     Nothing
*/
void min_and_max_valid(void **state)
{
  int arr[] = {1, 2, 3, 4};

  struct min_max mm = min_and_max(arr, 4);

  assert_int_equal(mm.min, 1);
  assert_int_equal(mm.max, 4);
} /* min_and_max */

/*
  Name:        display_unique_valid

  Purpose:     Tested function display_unique

  Params:      IN    state
              
  Returns:     Nothing
*/
void display_unique_valid(void **state)
{
  int array[MAX_SIZE] = {0, 3, 3, 9, 0, 6};
  int size = 6;

  display_unique(array, size);
} /* display_unique_valid */
