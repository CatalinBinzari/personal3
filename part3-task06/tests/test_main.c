
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

#include "../src/file.h"
#define TEST_PATH "tests/test_values.ini"
void is_valid_key_valid(void **state);
void is_valid_value_valid(void **state);
void valid_valid(void **state);
void add_value_valid(void **state);
void get_value_valid(void **state);
void get_value_when_key_not_found(void **state);
void rem_value_valid(void **state);
void rem_value_when_key_not_found(void **state);
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(is_valid_key_valid),
      cmocka_unit_test(is_valid_value_valid),
      cmocka_unit_test(valid_valid),
      cmocka_unit_test(add_value_valid),
      cmocka_unit_test(get_value_valid),
      cmocka_unit_test(get_value_when_key_not_found),
      cmocka_unit_test(rem_value_valid),
      cmocka_unit_test(rem_value_when_key_not_found),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        is_valid_key_valid

  Purpose:     Test function is_valid_key with valid or invalid input parameters 

  Params:      IN    state
              
  Returns:     Nothing
*/
void is_valid_key_valid(void **state)
{
  char *key = "key4";
  bool valid = is_valid_key(key);
  assert_true(valid);

  char *key1 = "_key4";
  valid = is_valid_key(key1);
  assert_true(valid);

  char *key2 = "9_key4";
  valid = is_valid_key(key2);
  assert_false(valid);

  char *key3 = "_\nkey4";
  valid = is_valid_key(key3);
  assert_false(valid);
} /* is_valid_key_valid */

/*
  Name:        is_valid_value_valid

  Purpose:     Test function is_valid_key with valid or invalid input parameters 

  Params:      IN    state
              
  Returns:     Nothing
*/
void is_valid_value_valid(void **state)
{
  char *value = "valll4";
  bool valid = is_valid_value(value);
  assert_true(valid);

  char *value1 = "vall\"4";
  valid = is_valid_value(value1);
  assert_false(valid);

  char *value2 = "vall\n4";
  valid = is_valid_value(value2);
  assert_false(valid);
} /* is_valid_value_valid */

/*
  Name:        valid_valid

  Purpose:     Test function valid with accepted or inaccepted input parameters 

  Params:      IN    state
              
  Returns:     Nothing
*/
void valid_valid(void **state)
{
  char *key = "valll4";
  char *value = "valll4";
  bool accepted = valid(key, value);
  assert_true(accepted);

  char *key1 = "valll4";
  char *value1 = "";
  accepted = valid(key1, value1);
  assert_true(accepted);

  char *key2 = "";
  char *value2 = "valid";
  accepted = valid(key2, value2);
  assert_false(accepted);

  char *key3 = "qwertyuiopasdfghjklzxcvbnmqwertt"; //len = 32
  char *value3 = "valid";
  accepted = valid(key3, value3);
  assert_false(accepted);

  char *key4 = "wertyuiopasdfghjklzxcvbnmqwertt"; //len = 31
  char *value4 = "valid";
  accepted = valid(key4, value4);
  assert_true(accepted);

  char *key5 = "valid";
  char *value5 = "qwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiopqwertyuiop123456"; //len = 96
  accepted = valid(key5, value5);
  assert_false(accepted);
} /* valid_valid */

/*
  Name:        add_value_valid

  Purpose:     Test function add_value with accepted and inaccepted input parameters 

  Params:      IN    state
              
  Returns:     Nothing
*/
void add_value_valid(void **state)
{
  dict_t **dict = dict_alloc();

  int ret_code = add_value(dict, "key", "value");
  assert_int_equal(ret_code, SUCCESS);

  ret_code = add_value(dict, "1invalid_key", "value");
  assert_int_equal(ret_code, INVALID);

  ret_code = add_value(dict, "valid_key", "");
  assert_int_equal(ret_code, EMPTY_VALUE);

  dict_dealloc(dict);
} /* add_value_valid */

/*
  Name:        get_value_valid

  Purpose:     Test function get_value with accepted input parameters 

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_value_valid(void **state)
{
  dict_t **dict = dict_alloc();

  int ret_code = add_value(dict, "key", "value");
  char *value = get_value(*dict, "key");

  assert_int_equal(ret_code, SUCCESS);
  assert_string_equal(value, "value");

  dict_dealloc(dict);
} /* get_value_valid */

/*
  Name:        get_value_when_key_not_found

  Purpose:     Test function get_value when key is not found

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_value_when_key_not_found(void **state)
{
  dict_t **dict = dict_alloc();

  int ret_code = add_value(dict, "key", "value");
  char *value = get_value(*dict, "notfoundkey");

  assert_int_equal(ret_code, SUCCESS);
  assert_string_equal(value, "");

  dict_dealloc(dict);
} /* get_value_when_key_not_found */

/*
  Name:        rem_value_valid

  Purpose:     Test function rem_value with accepted input parameters 

  Params:      IN    state
              
  Returns:     Nothing
*/
void rem_value_valid(void **state)
{
  dict_t **dict = dict_alloc();

  int ret_code = add_value(dict, "key", "value");
  int removed_code = rem_value(dict, "key");

  assert_int_equal(ret_code, SUCCESS);
  assert_int_equal(removed_code, SUCCESS);

  dict_dealloc(dict);
} /* rem_value_valid */

/*
  Name:        rem_value_when_key_not_found

  Purpose:     Test function rem_value when key not found

  Params:      IN    state
              
  Returns:     Nothing
*/
void rem_value_when_key_not_found(void **state)
{
  dict_t **dict = dict_alloc();

  int ret_code = add_value(dict, "key", "value");
  ret_code = add_value(dict, "key1", "value");
  ret_code = add_value(dict, "key2", "value");
  int removed_code = rem_value(dict, "key1");

  assert_int_equal(ret_code, SUCCESS);
  assert_int_equal(removed_code, KEY_NOT_FOUND);

  dict_dealloc(dict);
} /* rem_value_when_key_not_found */