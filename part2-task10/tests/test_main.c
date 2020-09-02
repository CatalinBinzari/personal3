
/*
  Name:        test_main.c

  Purpose:     Test functions from car.c file
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

#include "../src/car.h"

void parse_command_add(void **state);
void parse_command_list(void **state);
void parse_command_delete(void **state);
void add_car_valid(void **state);
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(parse_command_add),
      cmocka_unit_test(parse_command_list),
      cmocka_unit_test(parse_command_delete),
      cmocka_unit_test(add_car_valid),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        parse_command_add

  Purpose:     Test function parse_command with 'add' input from user

  Params:      IN    state
              
  Returns:     Nothing
*/
void parse_command_add(void **state)
{
  char user_input[] = "add |AUD 1023|125|Audi|A6|red|2016|";
  car_command command;

  int res = parse_command(user_input, &command);

  assert_int_equal(res, 0);
  assert_int_equal(command.id, 0);
  assert_string_equal(command.detail, "|AUD 1023|125|Audi|A6|red|2016|");
} /* parse_command_add */

/*
  Name:        parse_command_list

  Purpose:     Test function parse_command with 'list' input from user

  Params:      IN    state
              
  Returns:     Nothing
*/
void parse_command_list(void **state)
{
  char user_input[] = "list -filter brand bmw -sort year d";
  car_command command;

  int res = parse_command(user_input, &command);

  assert_int_equal(res, 0);
  assert_int_equal(command.id, 1);
  assert_int_equal(command.filter_field, BRAND);
  assert_string_equal(command.filter_value, "bmw");
  assert_int_equal(command.sort_field, YEAR);
  assert_false(command.sort_value);
} /* parse_command_list */

/*
  Name:        parse_command_delete

  Purpose:     Test function parse_command with 'delete' input from user

  Params:      IN    state
              
  Returns:     Nothing
*/
void parse_command_delete(void **state)
{
  char user_input[] = "delete -filter year 2012";
  car_command command;

  int res = parse_command(user_input, &command);

  assert_int_equal(res, 0);
  assert_int_equal(command.id, 2);
  assert_int_equal(command.filter_field, YEAR);
  assert_string_equal(command.filter_value, "2012");
} /* parse_command_delete */

/*
  Name:        add_car_valid

  Purpose:     Test function add_car with input by user

  Params:      IN    state
              
  Returns:     Nothing
*/
void add_car_valid(void **state)
{
  car_list *cars = (car_list *) malloc(sizeof(car_list));
  car_command command;

  int ret_code = add_car(cars, &command);
  assert_int_equal(ret_code, 0);
} /* add_car_valid */