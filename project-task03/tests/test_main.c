
/*
  Name:        test_main.c

  Purpose:     Tests _log function 
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
#include "connection.h"
#define TEST_FILE_PATH "tests/test_servers.ini"

void get_server_address_valid_when_key_is_found(void **state);
void get_server_address_valid_when_key_is_not_found(void **state);
void validate_number_valid(void **state);
void validate_number_when_no_digit(void **state);
void is_ip_address_valid(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(get_server_address_valid_when_key_is_found),
      cmocka_unit_test(get_server_address_valid_when_key_is_not_found),
      cmocka_unit_test(validate_number_valid),
      cmocka_unit_test(validate_number_when_no_digit),
      cmocka_unit_test(is_ip_address_valid),

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        get_server_address_valid_when_key_is_found

  Purpose:     Tests get_server_address for valid result when key exists

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_server_address_valid_when_key_is_found(void **state)
{
  connection conn;
  bool key_was_found;

  key_was_found = get_server_address(TEST_FILE_PATH, "addr", &conn.address);

  assert_string_equal(inet_ntoa(conn.address.sin_addr), "192.168.0.1");
  assert_int_equal(ntohs(conn.address.sin_port), 54790);
  assert_true(key_was_found);
} /* get_server_address_valid_when_key_is_found */

/*
  Name:        get_server_address_valid_when_key_is_not_found

  Purpose:     Tests get_server_address for valid result when key exists

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_server_address_valid_when_key_is_not_found(void **state)
{
  connection conn;
  bool key_was_found;

  key_was_found = get_server_address(TEST_FILE_PATH, "not_found_addr", &conn.address);

  assert_int_equal(ntohs(conn.address.sin_port), 0);
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
