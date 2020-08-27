
/*
  Name:        test_main.c

  Purpose:     This file contains tests for finding type of chars in a string
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/string.h"
void count_elements_valid(void **state);
void count_elements_alphabets(void **state);
void count_elements_mixed(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(count_elements_valid),
      cmocka_unit_test(count_elements_alphabets),
      cmocka_unit_test(count_elements_mixed),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        count_elements_v

  Purpose:     Test function count_elements to give us a valid result

  Params:      IN    state
              
  Returns:     Nothing

*/
void count_elements_valid(void **state)
{
  struct string_elements elem = count_elements("55, 55, 65");
  assert_int_equal(elem.alphabets, 0);
  assert_int_equal(elem.digits, 6);
  assert_int_equal(elem.special_chars, 4);
} /* admission_valid_not_admitted */

/*
  Name:        count_elements_alphabets

  Purpose:     Test function count_elements to give us a valid result
               with uppercase, lowercase letters

  Params:      IN    state
              
  Returns:     Nothing

*/
void count_elements_alphabets(void **state)
{
  struct string_elements elem = count_elements("This is a TEST");
  assert_int_equal(elem.alphabets, 11);
  assert_int_equal(elem.digits, 0);
  assert_int_equal(elem.special_chars, 3);
} /* count_elements_alphabets */

/*
  Name:        count_elements_mixed

  Purpose:     Test function count_elements to give us a valid result
               with mixed elements

  Params:      IN    state
              
  Returns:     Nothing

*/
void count_elements_mixed(void **state)
{
  struct string_elements elem = count_elements("&& contains %^&* and 0.4568798");
  assert_int_equal(elem.alphabets, 11);
  assert_int_equal(elem.digits, 8);
  assert_int_equal(elem.special_chars, 11);
} /* count_elements_mixed */
