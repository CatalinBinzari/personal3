
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
void rem_value_when_key_not_found(void **state);
void rem_value_valid(void **state);
void has_value_valid(void **state);
void has_value_with_inexistent_key(void **state);
void parse_comments_valid(void **state);
void parse_comments_stop_ignoring(void **state);
void parse_file_valid(void **state);
void is_front_part_of_key_valid(void **state);
void parse_key_value_valid_when_starts_key_parse(void **state);
void parse_key_value_valid_when_starts_value_parse(void **state);
void parse_key_value_valid_when_stops_key_parse(void **state);
void parse_key_value_valid_when_stops_key_parse_with_equal(void **state);
void parse_key_value_valid_when_stops_value_parse(void **state);

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
      cmocka_unit_test(rem_value_when_key_not_found),
      cmocka_unit_test(rem_value_valid),
      cmocka_unit_test(has_value_valid),
      cmocka_unit_test(has_value_with_inexistent_key),
      cmocka_unit_test(parse_comments_valid),
      cmocka_unit_test(parse_comments_stop_ignoring),
      cmocka_unit_test(parse_file_valid),
      cmocka_unit_test(is_front_part_of_key_valid),
      cmocka_unit_test(parse_key_value_valid_when_starts_key_parse),
      cmocka_unit_test(parse_key_value_valid_when_starts_value_parse),
      cmocka_unit_test(parse_key_value_valid_when_stops_key_parse),
      cmocka_unit_test(parse_key_value_valid_when_stops_key_parse_with_equal),
      cmocka_unit_test(parse_key_value_valid_when_stops_value_parse),
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
  ret_code = add_value(dict, "key1", "value");
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
  int removed_code = rem_value(dict, "undeclared_key");

  assert_int_equal(ret_code, SUCCESS);
  assert_int_equal(removed_code, KEY_NOT_FOUND);

  dict_dealloc(dict);
} /* rem_value_when_key_not_found */

/*
  Name:        has_value_valid

  Purpose:     Test function has_value when key exist

  Params:      IN    state
              
  Returns:     Nothing
*/
void has_value_valid(void **state)
{
  dict_t **dict = dict_alloc();

  int ret_code = add_value(dict, "key1", "value");
  bool has_val = has_value(*dict, "key1");

  assert_int_equal(ret_code, SUCCESS);
  assert_true(has_val);

  dict_dealloc(dict);
} /* has_value_valid */

/*
  Name:        has_value_with_inexistent_key

  Purpose:     Test function has_value when key exist

  Params:      IN    state
              
  Returns:     Nothing
*/
void has_value_with_inexistent_key(void **state)
{
  dict_t **dict = dict_alloc();

  int ret_code = add_value(dict, "key1", "value");
  bool has_val = has_value(*dict, "key66");

  assert_int_equal(ret_code, SUCCESS);
  assert_false(has_val);

  dict_dealloc(dict);
} /* has_value_with_inexistent_key */

/*
  Name:        parse_comments_valid

  Purpose:     Test function parse_comments with '#' as parameter

  Params:      IN    state
              
  Returns:     Nothing
*/
void parse_comments_valid(void **state)
{
  bool ignoring = false;

  ignoring = parse_comments('#', ignoring);

  assert_true(ignoring);
} /* parse_comments_valid */

/*
  Name:        parse_comments_stop_ignoring

  Purpose:     Test function parse_comments with '#' as parameter

  Params:      IN    state
              
  Returns:     Nothing
*/
void parse_comments_stop_ignoring(void **state)
{
  bool ignoring = true;

  ignoring = parse_comments('\n', ignoring);

  assert_false(ignoring);
} /* parse_comments_stop_ignoring */

/*
  Name:        parse_file_valid

  Purpose:     Parse test file and verify if was parsed correctly

  Params:      IN    state
              
  Returns:     Nothing
*/
void parse_file_valid(void **state)
{
  dict_t **dict = dict_alloc();
  parse_file(TEST_PATH, dict);

  char *value1 = get_value(*dict, "key2");
  char *value2 = get_value(*dict, "key3");
  char *value3 = get_value(*dict, "key6");
  char *value4 = get_value(*dict, "_g");
  assert_string_equal(value1, "value2");
  assert_string_equal(value2, "val to be  removed");
  assert_string_equal(value3, "value6");
  assert_string_equal(value4, "");

  dict_dealloc(dict);
} /* parse_file_valid */

/*
  Name:        is_front_part_of_key_valid

  Purpose:     Verify function is_front_part_of_key with multiple inputs

  Params:      IN    state
              
  Returns:     Nothing
*/
void is_front_part_of_key_valid(void **state)
{
  bool is_front = is_front_part_of_key('A');
  assert_true(is_front);

  is_front = is_front_part_of_key('g');
  assert_true(is_front);

  is_front = is_front_part_of_key('y');
  assert_true(is_front);

  is_front = is_front_part_of_key('%');
  assert_false(is_front);

  is_front = is_front_part_of_key('_');
  assert_true(is_front);

  is_front = is_front_part_of_key('7');
  assert_false(is_front);
} /* is_front_part_of_key_valid */

/*
  Name:        parse_key_value_valid_when_starts_key_parse

  Purpose:     Verify function parse_key_value when is starting key parsing

  Params:      IN    state
              
  Returns:     Nothing
*/
void parse_key_value_valid_when_starts_key_parse(void **state)
{
  bool parse_key = false;
  bool parse_value = false;
  bool was_equal = false;
  bool waiting_for_equal = false;
  char key_tmp[KEY_LENGTH];
  char value_tmp[VALUE_LENGTH];
  char ch = '_';
  int index = 0;

  int status = parse_key_value(ch, &parse_key, &parse_value, &was_equal, &waiting_for_equal, key_tmp, value_tmp, &index);

  assert_false(status);
  assert_string_equal(key_tmp, "_");
  assert_string_equal(value_tmp, "");
  assert_true(parse_key);
  assert_false(parse_value);
  assert_false(waiting_for_equal);
  assert_false(was_equal);
  assert_int_equal(index, 1);

} /* parse_key_value_valid_when_starts_key_parse */

/*
  Name:        parse_key_value_valid_when_starts_value_parse

  Purpose:     Verify function parse_key_value when is starting value parsing

  Params:      IN    state
              
  Returns:     Nothing
*/
void parse_key_value_valid_when_starts_value_parse(void **state)
{
  bool parse_key = false;
  bool parse_value = false;
  bool was_equal = true;
  bool waiting_for_equal = false;
  char key_tmp[KEY_LENGTH];
  char value_tmp[VALUE_LENGTH];
  char ch = '"';
  int index = 0;

  int status = parse_key_value(ch, &parse_key, &parse_value, &was_equal, &waiting_for_equal, key_tmp, value_tmp, &index);

  assert_false(status);
  assert_string_equal(key_tmp, "");
  assert_string_equal(value_tmp, "");
  assert_false(parse_key);
  assert_true(parse_value);
  assert_false(waiting_for_equal);
  assert_false(was_equal);
  assert_int_equal(index, 0);

} /* parse_key_value_valid_when_starts_value_parse */

/*
  Name:        parse_key_value_valid_when_stops_key_parse

  Purpose:     Verify function parse_key_value when stops key parsing

  Params:      IN    state
              
  Returns:     Nothing
*/
void parse_key_value_valid_when_stops_key_parse(void **state)
{
  bool parse_key = true;
  bool parse_value = false;
  bool was_equal = false;
  bool waiting_for_equal = false;
  char key_tmp[KEY_LENGTH];
  char value_tmp[VALUE_LENGTH];
  char ch = ' ';
  int index = 0;

  int status = parse_key_value(ch, &parse_key, &parse_value, &was_equal, &waiting_for_equal, key_tmp, value_tmp, &index);

  assert_false(status);
  assert_string_equal(key_tmp, "");
  assert_string_equal(value_tmp, "");
  assert_false(parse_key);
  assert_false(parse_value);
  assert_true(waiting_for_equal);
  assert_false(was_equal);
  assert_int_equal(index, 0);

} /* parse_key_value_valid_when_stops_key_parse */

/*
  Name:        parse_key_value_valid_when_stops_key_parse_with_equal

  Purpose:     Verify function parse_key_value when stops key parsing

  Params:      IN    state
              
  Returns:     Nothing
*/
void parse_key_value_valid_when_stops_key_parse_with_equal(void **state)
{
  bool parse_key = true;
  bool parse_value = false;
  bool was_equal = false;
  bool waiting_for_equal = false;
  char key_tmp[KEY_LENGTH];
  char value_tmp[VALUE_LENGTH];
  char ch = '=';
  int index = 0;

  int status = parse_key_value(ch, &parse_key, &parse_value, &was_equal, &waiting_for_equal, key_tmp, value_tmp, &index);

  assert_false(status);
  assert_string_equal(key_tmp, "");
  assert_string_equal(value_tmp, "");
  assert_false(parse_key);
  assert_false(parse_value);
  assert_false(waiting_for_equal);
  assert_true(was_equal);
  assert_int_equal(index, 0);

} /* parse_key_value_valid_when_stops_key_parse_with_equal */

/*
  Name:        parse_key_value_valid_when_stops_value_parse

  Purpose:     Verify function parse_key_value when stops value parsing

  Params:      IN    state
              
  Returns:     Nothing
*/
void parse_key_value_valid_when_stops_value_parse(void **state)
{
  bool parse_key = false;
  bool parse_value = true;
  bool was_equal = false;
  bool waiting_for_equal = false;
  char key_tmp[KEY_LENGTH];
  char value_tmp[VALUE_LENGTH];
  char ch = '"';
  int index = 0;

  int status = parse_key_value(ch, &parse_key, &parse_value, &was_equal, &waiting_for_equal, key_tmp, value_tmp, &index);

  assert_true(status);
  assert_string_equal(key_tmp, "");
  assert_string_equal(value_tmp, "");
  assert_false(parse_key);
  assert_false(parse_value);
  assert_false(waiting_for_equal);
  assert_false(was_equal);
  assert_int_equal(index, 0);
}