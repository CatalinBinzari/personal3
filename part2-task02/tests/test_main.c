
/*
  Name:        test_main.c

  Purpose:     This file contains tests converting a string to uppercase
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/string.h"
void to_upper_all_lowercase(void **state);
void to_upper_all_uppercase(void **state);
void to_upper_mixed(void **state);
void to_upper_mixed_with_symbols(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(to_upper_all_lowercase),
      cmocka_unit_test(to_upper_all_uppercase),
      cmocka_unit_test(to_upper_mixed),
      cmocka_unit_test(to_upper_mixed_with_symbols),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        to_upper_all_lowercase

  Purpose:     Test function to_upper with input string: lowercase

  Params:      IN    state
              
  Returns:     Nothing

*/
void to_upper_all_lowercase(void **state)
{
  char str[] = "test";
  to_upper(str);

  assert_string_equal(str, "TEST");
} /* to_upper_all_lowercase */

/*
  Name:        to_upper_all_uppercase

  Purpose:     Test function to_upper with input string: uppercase

  Params:      IN    state
              
  Returns:     Nothing

*/
void to_upper_all_uppercase(void **state)
{
  char str[] = "TEST";
  to_upper(str);

  assert_string_equal(str, "TEST");
} /* to_upper_all_uppercase */

/*
  Name:        to_upper_mixed

  Purpose:     Test function to_upper with input string: lowercase and uppercase

  Params:      IN    state
              
  Returns:     Nothing

*/
void to_upper_mixed(void **state)
{
  char str[] = "TeSt";
  to_upper(str);

  assert_string_equal(str, "TEST");
}
/*

  Params:      IN    state
              
  Returns:     Nothing

*/
void to_upper_mixed_with_symbols(void **state)
{

  char str[] = "TeSt55!/";
  to_upper(str);

  assert_string_equal(str, "TEST55!/");
} /* to_upper_mixed_with_symbols */
