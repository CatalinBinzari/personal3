
/*
  Name:        test_main.c

  Purpose:     Tests products management functions
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

#include "../include/config.h"
#define TEST_FILE_PATH "tests/test_config.ini"

void get_config_value_valid(void **state);
void get_config_value_valid_2(void **state);
void my_strcpy_valid(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(get_config_value_valid),
      cmocka_unit_test(get_config_value_valid_2),
      cmocka_unit_test(my_strcpy_valid)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        get_config_value_valid

  Purpose:     Test function is_valid_key with valid or invalid input parameters 

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_config_value_valid(void **state)
{
  char value[VALUE_LENGTH];
  int value_length;
  bool key_was_found = false;
  key_was_found = get_config_value(TEST_FILE_PATH, "age", value, &value_length);

  assert_string_equal("55", value);
  assert_true(key_was_found);
  assert_int_equal(value_length, 2);
} /* get_config_value_valid */

/*
  Name:        get_config_value_valid_2

  Purpose:     Test function is_valid_key with valid or invalid input parameters 

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_config_value_valid_2(void **state)
{
  char value[VALUE_LENGTH];
  int value_length;
  bool key_was_found = false;
  key_was_found = get_config_value(TEST_FILE_PATH, "ag66e", value, &value_length);

  assert_string_equal("string&^%$*$5   6546%65", value);
  assert_true(key_was_found);
  assert_int_equal(value_length, 23);
} /* get_config_value_valid_2 */

/*
  Name:        my_strcpy_valid

  Purpose:     Tests my_strcpy for valid result 

  Params:      IN    state
              
  Returns:     Nothing
*/
void my_strcpy_valid(void **state)
{
  char dest[20];
  char src[20]="str%^&#345667";
  int length = my_strcpy(dest, src);

  assert_int_equal(length, 13);
  assert_string_equal(dest, "str%^&#345667");
  assert_string_equal(src, "str%^&#345667");
} /* my_strcpy_valid */
