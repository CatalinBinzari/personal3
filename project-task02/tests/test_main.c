
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

#include "config.h"
#define TEST_FILE_PATH "tests/test_config.ini"


void get_config_value_valid(void **state);
void get_config_value_valid_2(void **state);
void get_server_address_valid_when_key_is_found(void **state);
void get_server_address_valid_when_key_is_not_found(void **state);
void validate_number_valid(void **state);
void validate_number_when_no_digit(void **state);
void is_ip_address_valid(void **state);
void get_config_value_valid_3(void **state);
void get_config_value_valid_4(void **state);
void get_config_value_valid_5(void **state);


/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(get_config_value_valid),
      cmocka_unit_test(get_config_value_valid_2),
      cmocka_unit_test(get_server_address_valid_when_key_is_found),
      cmocka_unit_test(get_server_address_valid_when_key_is_not_found),
      cmocka_unit_test(validate_number_valid),
      cmocka_unit_test(validate_number_when_no_digit),
      cmocka_unit_test(is_ip_address_valid),
      cmocka_unit_test(get_config_value_valid_3),
      cmocka_unit_test(get_config_value_valid_4),
      cmocka_unit_test(get_config_value_valid_5),
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
  int value_length = 200;
  char value[value_length];
  bool key_was_found = false;
  key_was_found = get_config_value(TEST_FILE_PATH, "age", value, value_length);

  assert_string_equal("55", value);
  assert_true(key_was_found);
} /* get_config_value_valid */

/*
  Name:        get_config_value_valid_2

  Purpose:     Test function is_valid_key with valid or invalid input parameters 

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_config_value_valid_2(void **state)
{
  int value_length = 200;
  char value[value_length];
  bool key_was_found = false;
  key_was_found = get_config_value(TEST_FILE_PATH, "ag66e", value, value_length);

  assert_string_equal("string&^%$*$5   6546%65", value);
  assert_true(key_was_found);
} /* get_config_value_valid_2 */

/*
  Name:        get_config_value_valid_3

  Purpose:     Test function is_valid_key with value of 200 chars

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_config_value_valid_3(void **state)
{
  int value_length = 201;
  char value[value_length];
  bool key_was_found = false;
  key_was_found = get_config_value(TEST_FILE_PATH, "_500_char_string", value, value_length);

  assert_string_equal("tvDWylGjUaVOrP2WUZRWXnrzFn5YJxJg19A4BcRmTh1LOKkAPMSXzxyj9zByJXrNUqBXXp2Ui9DfMPabZTmuV8NX6YKKuy4VL2mCWHOfeF6hTxI3LCuq4kBzVJR153C1lCj8bl2UX003NKcQRu5Od9AnaNqJK3gmKAPt3loe7Jfwpa9zIWWDfSy80LHnXsDG7B53zuoc",
   value);
  assert_true(key_was_found);
} /* get_config_value_valid_3 */

/*
  Name:        get_config_value_valid_4

  Purpose:     Test function is_valid_key with value of 500 chars

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_config_value_valid_4(void **state)
{
  int value_length = 501; 
  char value[value_length];
  bool key_was_found = false;
  key_was_found = get_config_value(TEST_FILE_PATH, "_500_char_string", value, value_length);

  assert_string_equal("tvDWylGjUaVOrP2WUZRWXnrzFn5YJxJg19A4BcRmTh1LOKkAPMSXzxyj9zByJXrNUqBXXp2Ui9DfMPabZTmuV8NX6YKKuy4VL2mCWHOfeF6hTxI3LCuq4kBzVJR153C1lCj8bl2UX003NKcQRu5Od9AnaNqJK3gmKAPt3loe7Jfwpa9zIWWDfSy80LHnXsDG7B53zuoc84HeGDnarnQrK3Sijcy6EDantGKNFDEFq57BWdCWsuI29J1w4PVANQcjePN0qJfnrzkXkbAFm8fPUqIKr7XEWDOQ2ZBJXNzKq8xDirk5MoN5Yxx4Y3y7y1a58279ClXGIqCBNUDnB03nv98IC2kibtry3fTb96C4JVIhDasdcicTcj3D7DzRZuMazcLunVzwkVAvLQ0uPf9Q9F6RB92bq5E6TXIzuL3MUqaKZsad4UPNwQlYF1oxwRk24xGPPTkWHTnReO0t67sl40OIEwooDJfSbm6XdAmGlzBsaALlxxaU",
   value);
  assert_true(key_was_found);
} /* get_config_value_valid_4 */

/*
  Name:        get_config_value_valid_5

  Purpose:     Test function is_valid_key with value of 550 chars

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_config_value_valid_5(void **state)
{
  int value_length = 501; 
  char value[value_length];
  bool key_was_found = false;
  key_was_found = get_config_value(TEST_FILE_PATH, "_550_char_string", value, value_length);

  assert_string_equal("zYJs8leFsbrujLURHTn9ORWv8WJMfdn7wHfvBja9Iaz8J0aShV6Sfya2FQ2hT5a5VTXCU9Ux4a9P7nMki6r4NbX1BYZn5srHN0m3kajsOWPzG7XX3OscsLHccNLeDNNvxdoKWwyTBVgIm5d5VDv2qe6WaXcXFCJybePviVJjN3v9PglFS78lOJGXuALN1dsBolwPH9ESzpGqxtGmI3ZnxUdceP3myej1nyT3MK14s9gIqMX1XQourA5M0kaDDG5fFWenfzkwL0sV8P5hOKb7iKDRVky8NCSsqadkudASSZRZ1S9Z2jcdk641uE0hID5wyKwdeeBGjgucZMWpxVVvqEeHjDXpE3PzFeaTssdNNibXYMWAbH0UGKmRg6IxCmZnhNrNuIANoGLaDD5vmj81FraWDIPwXPGAe1UcvkF7aedSWMsOz0jxnxWyKKdRT1Wi257LHwOFp05HWy6MDtXteEHDd8TkNGeUoIE8XdHXgAhDIyggyn84",
   value);
  assert_true(key_was_found);
} /* get_config_value_valid_5 */


/*
  Name:        get_server_address_valid_when_key_is_found

  Purpose:     Tests get_server_address for valid result when key exists

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_server_address_valid_when_key_is_found(void **state)
{
  char ip[20];
  unsigned short port;
  bool key_was_found;

  key_was_found = get_server_address(TEST_FILE_PATH, "addr", ip, &port);

  assert_string_equal(ip, "192.168.0.1");
  assert_int_equal(port, 54790);
  assert_true(key_was_found);
} /* get_server_address_valid_when_key_is_found */

/*
  Name:        get_server_address_valid_when_key_is_not_found

  Purpose:     Tests get_server_address for valid result when key does not exists

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_server_address_valid_when_key_is_not_found(void **state)
{
  char ip[20] = "";
  unsigned short port = 0;
  bool key_was_found = false;
  ;

  key_was_found = get_server_address(TEST_FILE_PATH, "smth", ip, &port);

  assert_string_equal(ip, "");
  assert_int_equal(port, 0);
  assert_false(key_was_found);
} /* get_server_address_valid_when_key_is_not_found */

/*
  Name:        validate_number_valid

  Purpose:     Tests validate_number for valid result string contains just digits

  Params:      IN    state
              
  Returns:     Nothing
*/
void validate_number_valid(void **state)
{
  bool just_digits = validate_number("192");
  assert_true(just_digits);
} /* validate_number_valid */

/*
  Name:        validate_number_when_no_digit

  Purpose:     Tests validate_number for valid result string does not contain digits 

  Params:      IN    state
              
  Returns:     Nothing
*/
void validate_number_when_no_digit(void **state)
{
  bool just_digits = validate_number("1P2");
  assert_false(just_digits);
} /* validate_number_when_no_digit */

/*
  Name:        is_ip_address_valid

  Purpose:     Tests is_ip_address for valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void is_ip_address_valid(void **state)
{
  char ip1[] = "192.168.4.1";
  char ip2[] = "172.16.253.1";
  char ip3[] = "172.16.253.100";
  char ip4[] = "192.800.100.1";
  char ip5[] = "125.512.100.abc";
  char ip6[] = "125.512.100.1000";

  assert_true(is_ip_address(ip1));
  assert_true(is_ip_address(ip2));
  assert_true(is_ip_address(ip3));
  assert_false(is_ip_address(ip4));
  assert_false(is_ip_address(ip5));
  assert_false(is_ip_address(ip6));
} /* is_ip_address_valid */
