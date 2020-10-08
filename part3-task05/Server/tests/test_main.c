
/*
  Name:        test_main.c

  Purpose:     Test functions from server.c file
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../src/server.h"

void to_upper_valid(void **state);
void double_number_valid(void **state);
void double_number_valid_with_strings(void **state);
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(to_upper_valid),
    cmocka_unit_test(double_number_valid),
    cmocka_unit_test(double_number_valid_with_strings),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        to_upper_valid

  Purpose:     Tests function to_upper using strigs with digits, letters, symbols.

  Params:      IN    state
              
  Returns:     Nothing
*/
void to_upper_valid(void **state)
{
  char msg_text[1024];
  strcpy(msg_text, "00thisstringshouldbemakeuppercase%%");
  to_upper(msg_text);
  assert_string_equal("00THISSTRINGSHOULDBEMAKEUPPERCASE%%", msg_text);
} /* to_upper_valid */

/*
  Name:        double_number_valid

  Purpose:     Tests function double_numbers, with a valid number

  Params:      IN    state
              
  Returns:     Nothing
*/
void double_number_valid(void **state)
{
  char msg_text[1024];
  strcpy(msg_text, "66.9");
  double_number(msg_text);
  assert_string_equal("133.80", msg_text);
} /* double_number_valid */

/*
  Name:        double_number_valid_with_strings

  Purpose:     Tests function double_number with invalid input

  Params:      IN    state
              
  Returns:     Nothing
*/
void double_number_valid_with_strings(void **state)
{
  char msg_text[1024];
  strcpy(msg_text, "string%%9");
  double_number(msg_text);
  assert_string_equal("0.00", msg_text);
} /* double_number_valid_with_strings */
