
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
void add_car_already_in_list(void **state);
void list_car_brand(void **state);
void list_car_power(void **state);
void list_car_license_plate(void **state);
void list_car_model(void **state);
void list_car_color(void **state);
void list_car_year(void **state);
void list_car_year_sort_license_plate(void **state);
void list_car_year_sort_color(void **state);
void list_car_year_sort_year(void **state);
void delete_car_field_power(void **state);
void delete_car_field_power_10element_list(void **state);
void delete_all_elements(void **state);
void delete_zero_elements(void **state);
void delete_first_4_elements(void **state);
void delete_last_4_elements(void **state);
void delete_first_and_last_elements(void **state);
void parse_command_list_just_filter(void **state);
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(parse_command_list_just_filter),
      cmocka_unit_test(parse_command_add),
      //cmocka_unit_test(parse_command_list),
      cmocka_unit_test(parse_command_delete),
      cmocka_unit_test(add_car_valid),
      cmocka_unit_test(add_car_already_in_list),
      cmocka_unit_test(list_car_brand),
      cmocka_unit_test(list_car_power),
      cmocka_unit_test(list_car_license_plate),
      cmocka_unit_test(list_car_model),
      cmocka_unit_test(list_car_color),
      cmocka_unit_test(list_car_year),
      cmocka_unit_test(list_car_year_sort_license_plate),
      cmocka_unit_test(list_car_year_sort_color),
      cmocka_unit_test(list_car_year_sort_year),
      cmocka_unit_test(delete_car_field_power),
      cmocka_unit_test(delete_car_field_power_10element_list),
      cmocka_unit_test(delete_all_elements),
      cmocka_unit_test(delete_zero_elements),
      cmocka_unit_test(delete_first_4_elements),
      cmocka_unit_test(delete_last_4_elements),
      cmocka_unit_test(delete_first_and_last_elements),
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
  assert_false(command.sort_ascending);
} /* parse_command_list */

/*
  Name:        parse_command_list_just_filter

  Purpose:     Test function parse_command with 'list' input from user

  Params:      IN    state
              
  Returns:     Nothing
*/
void parse_command_list_just_filter(void **state)
{
  char user_input[] = "list -filter brand bmw";
  car_command command;

  int res = parse_command(user_input, &command);
  printf("%d", res);
} /* parse_command_list_just_filter */

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
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(sizeof(car) * list.number_of_cars);

  car_command command;
  strcpy(command.detail, "|AUD 1023|125|Audi|A6|red|2016|");

  int ret_code = add_car(&list, &command);
  assert_string_equal(list.car[0].license_plate, "AUD 1023");
  assert_string_equal(list.car[0].brand, "Audi");
  assert_string_equal(list.car[0].model, "A6");
  assert_int_equal(list.car[0].power, 125);
  assert_int_equal(list.car[0].color, RED);
  assert_int_equal(list.car[0].year, 2016);
  assert_int_equal(list.number_of_cars, 1);

  strcpy(command.detail, "|AUD 1028|400|Audi|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  assert_string_equal(list.car[1].license_plate, "AUD 1028");
  assert_string_equal(list.car[1].brand, "Audi");
  assert_string_equal(list.car[1].model, "A6");
  assert_int_equal(list.car[1].color, YELLOW);
  assert_int_equal(list.number_of_cars, 2);
  assert_int_equal(list.car[1].power, 400);
  assert_int_equal(list.car[1].year, 2018);

  assert_int_equal(ret_code, 0);
  free(list.car);
} /* add_car_valid */

/*
  Name:        add_car_already_in_list

  Purpose:     Test function add_car with return code 3,
               meaning already in the list

  Params:      IN    state
              
  Returns:     Nothing
*/
void add_car_already_in_list(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(sizeof(car) * list.number_of_cars);

  car_command command;

  strcpy(command.detail, "|AUD 1023|125|Audi|A6|red|2016|");
  int ret_code = add_car(&list, &command);
  assert_string_equal(list.car[0].license_plate, "AUD 1023");

  strcpy(command.detail, "|AUD 1023|400|Audi|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  assert_string_not_equal(list.car[1].license_plate, "AUD 1023");

  assert_int_equal(ret_code, 3);

  free(list.car);
} /* add_car_already_in_list */

/*
  Name:        list_car_brand

  Purpose:     Test function list_car for valid result while filtering brand

  Params:      IN    state
              
  Returns:     Nothing
*/
void list_car_brand(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(sizeof(car));
  car_list listed_cars;
  listed_cars.number_of_cars = 0;
  listed_cars.car = (car *)malloc(sizeof(car));
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1023|125|Audi|A1|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|BW 0024|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|125|Audi|A2|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A3|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1026|125|Opel|A4|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A5|yellow|2018|");
  ret_code = add_car(&list, &command);

  command.filter_field = BRAND;
  strcpy(command.filter_value, "Audi");
  command.sort_field = MODEL;
  command.sort_ascending = false;
  ret_code = list_car(&list, &command, &listed_cars);

  assert_int_equal(list.number_of_cars, 6);
  assert_int_equal(listed_cars.number_of_cars, 3);
  assert_int_equal(ret_code, 0);
  assert_string_equal(listed_cars.car[0].brand, "Audi");
  assert_string_equal(listed_cars.car[1].brand, "Audi");
  assert_string_equal(listed_cars.car[2].brand, "Audi");
  assert_string_equal(listed_cars.car[0].model, "A5");
  assert_string_equal(listed_cars.car[1].model, "A2");
  assert_string_equal(listed_cars.car[2].model, "A1");

  free(list.car);
  free(listed_cars.car);
} /* list_car_brand */

/*
  Name:        list_car_power

  Purpose:     Test function list_car for valid result while filtering power

  Params:      IN    state
              
  Returns:     Nothing
*/
void list_car_power(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(sizeof(car));
  car_list listed_cars;
  listed_cars.number_of_cars = 0;
  listed_cars.car = (car *)malloc(sizeof(car));
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1023|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|BW 0024|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|125|Mercedes|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1026|125|Opel|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A6|yellow|2018|");
  ret_code = add_car(&list, &command);

  command.filter_field = POWER;
  strcpy(command.filter_value, "125");
  command.sort_field = BRAND;
  command.sort_ascending = true;
  ret_code = list_car(&list, &command, &listed_cars);

  assert_int_equal(list.number_of_cars, 6);
  assert_int_equal(listed_cars.number_of_cars, 3);
  assert_int_equal(ret_code, 0);
  assert_int_equal(listed_cars.car[0].power, 125);
  assert_int_equal(listed_cars.car[1].power, 125);
  assert_int_equal(listed_cars.car[2].power, 125);
  assert_string_equal(listed_cars.car[0].brand, "Audi");
  assert_string_equal(listed_cars.car[1].brand, "Mercedes");
  assert_string_equal(listed_cars.car[2].brand, "Opel");

  free(list.car);
  free(listed_cars.car);
} /* list_car_power */

/*
  Name:        list_car_license_plate

  Purpose:     Test function list_car for valid result while filtering license_plate

  Params:      IN    state
              
  Returns:     Nothing
*/
void list_car_license_plate(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(sizeof(car));
  car_list listed_cars;
  listed_cars.number_of_cars = 0;
  listed_cars.car = (car *)malloc(sizeof(car));
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1023|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|BW 0024|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1026|125|Opel|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A6|yellow|2018|");
  ret_code = add_car(&list, &command);

  command.filter_field = LICENSE_PLATE;
  strcpy(command.filter_value, "AUD 1024");
  command.sort_field = BRAND;
  command.sort_ascending = true;
  ret_code = list_car(&list, &command, &listed_cars);

  assert_int_equal(list.number_of_cars, 6);
  assert_int_equal(listed_cars.number_of_cars, 1);
  assert_int_equal(ret_code, 0);
  assert_string_equal(listed_cars.car[0].license_plate, "AUD 1024");

  free(list.car);
  free(listed_cars.car);
} /* list_car_license_plate */

/*
  Name:        list_car_model

  Purpose:     Test function list_car for valid result while filtering model

  Params:      IN    state
              
  Returns:     Nothing
*/
void list_car_model(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(sizeof(car));
  car_list listed_cars;
  listed_cars.number_of_cars = 0;
  listed_cars.car = (car *)malloc(sizeof(car));
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1023|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|BW 0024|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|UU|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1026|125|Opel|PP|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A5|yellow|2018|");
  ret_code = add_car(&list, &command);

  command.filter_field = MODEL;
  strcpy(command.filter_value, "A6");
  command.sort_field = LICENSE_PLATE;
  command.sort_ascending = true;
  ret_code = list_car(&list, &command, &listed_cars);

  assert_int_equal(list.number_of_cars, 6);
  assert_int_equal(listed_cars.number_of_cars, 2);
  assert_int_equal(ret_code, 0);
  assert_string_equal(listed_cars.car[0].model, "A6");
  assert_string_equal(listed_cars.car[1].model, "A6");
  assert_string_equal(listed_cars.car[2].model, "");

  free(list.car);
  free(listed_cars.car);
} /* list_car_model */

/*
  Name:        list_car_color

  Purpose:     Test function list_car for valid result while filtering model

  Params:      IN    state
              
  Returns:     Nothing
*/
void list_car_color(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(sizeof(car));
  car_list listed_cars;
  listed_cars.number_of_cars = 0;
  listed_cars.car = (car *)malloc(sizeof(car));
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1023|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|BW 0024|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1026|120|Audi|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|459|Audi|A6|yellow|2018|");
  ret_code = add_car(&list, &command);

  command.filter_field = COLOR;
  strcpy(command.filter_value, "1");
  command.sort_field = POWER;
  command.sort_ascending = false;
  ret_code = list_car(&list, &command, &listed_cars);

  assert_int_equal(list.number_of_cars, 6);
  assert_int_equal(listed_cars.number_of_cars, 3);
  assert_int_equal(ret_code, 0);
  assert_int_equal(listed_cars.car[0].color, YELLOW);
  assert_int_equal(listed_cars.car[1].color, YELLOW);
  assert_int_equal(listed_cars.car[2].color, YELLOW);
  assert_int_equal(listed_cars.car[0].power, 459);
  assert_int_equal(listed_cars.car[1].power, 400);
  assert_int_equal(listed_cars.car[2].power, 120);

  free(list.car);
  free(listed_cars.car);
} /* list_car_color */

/*
  Name:        list_car_year

  Purpose:     Test function list_car for valid result while filtering year

  Params:      IN    state
              
  Returns:     Nothing
*/
void list_car_year(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(sizeof(car));
  car_list listed_cars;
  listed_cars.number_of_cars = 0;
  listed_cars.car = (car *)malloc(sizeof(car));
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1023|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|BW 0024|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1026|125|Opel|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A6|yellow|2018|");
  ret_code = add_car(&list, &command);

  command.filter_field = YEAR;
  strcpy(command.filter_value, "2016");
  command.sort_field = LICENSE_PLATE;
  command.sort_ascending = false;
  ret_code = list_car(&list, &command, &listed_cars);

  assert_int_equal(list.number_of_cars, 6);
  assert_int_equal(listed_cars.number_of_cars, 3);
  assert_int_equal(ret_code, 0);
  assert_string_equal(listed_cars.car[0].license_plate, "AUD 1026");
  assert_string_equal(listed_cars.car[1].license_plate, "AUD 1024");
  assert_string_equal(listed_cars.car[2].license_plate, "AUD 1023");

  free(list.car);
  free(listed_cars.car);
} /* list_car_year */

/*
  Name:        list_car_year_sort_license_plate

  Purpose:     Test function list_car for valid result while filtering year
               and sorting by license_plate

  Params:      IN    state
              
  Returns:     Nothing
*/
void list_car_year_sort_license_plate(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(sizeof(car));
  car_list listed_cars;
  listed_cars.number_of_cars = 0;
  listed_cars.car = (car *)malloc(sizeof(car));
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1026|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|BW 0024|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1023|125|Opel|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A6|yellow|2018|");
  ret_code = add_car(&list, &command);

  command.filter_field = YEAR;
  strcpy(command.filter_value, "2016");
  command.sort_field = LICENSE_PLATE;
  command.sort_ascending = true;
  ret_code = list_car(&list, &command, &listed_cars);

  assert_int_equal(list.number_of_cars, 6);
  assert_int_equal(listed_cars.number_of_cars, 3);
  assert_int_equal(ret_code, 0);
  assert_string_equal(listed_cars.car[0].license_plate, "AUD 1023");
  assert_string_equal(listed_cars.car[1].license_plate, "AUD 1024");
  assert_string_equal(listed_cars.car[2].license_plate, "AUD 1026");

  free(list.car);
  free(listed_cars.car);
} /* list_car_year_sort_license_plate */

/*
  Name:        list_car_year_sort_color

  Purpose:     Test function list_car for valid result while filtering year
               and sorting by color

  Params:      IN    state
              
  Returns:     Nothing
*/
void list_car_year_sort_color(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(sizeof(car));
  car_list listed_cars;
  listed_cars.number_of_cars = 0;
  listed_cars.car = (car *)malloc(sizeof(car));
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1026|125|Audi|A6|white|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|BW 0024|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1023|125|Opel|A6|green|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);

  command.filter_field = YEAR;
  strcpy(command.filter_value, "2016");
  command.sort_field = COLOR;
  command.sort_ascending = true;
  ret_code = list_car(&list, &command, &listed_cars);

  assert_int_equal(list.number_of_cars, 6);
  assert_int_equal(listed_cars.number_of_cars, 4);
  assert_int_equal(ret_code, 0);
  assert_string_equal(listed_cars.car[0].license_plate, "AUD 1026");
  assert_string_equal(listed_cars.car[1].license_plate, "AUD 1024");
  assert_string_equal(listed_cars.car[2].license_plate, "AUD 1023");
  assert_string_equal(listed_cars.car[3].license_plate, "AUD 1027");

  command.filter_field = YEAR;
  strcpy(command.filter_value, "2016");
  command.sort_field = COLOR;
  command.sort_ascending = false;
  ret_code = list_car(&list, &command, &listed_cars);

  assert_int_equal(listed_cars.number_of_cars, 4);
  assert_string_equal(listed_cars.car[0].license_plate, "AUD 1027");
  assert_string_equal(listed_cars.car[1].license_plate, "AUD 1023");
  assert_string_equal(listed_cars.car[2].license_plate, "AUD 1024");
  assert_string_equal(listed_cars.car[3].license_plate, "AUD 1026");

  free(list.car);
  free(listed_cars.car);
} /* list_car_year_sort_color */

/*
  Name:        list_car_year_sort_year

  Purpose:     Test function list_car for valid result while filtering year
               and sorting by year

  Params:      IN    state
              
  Returns:     Nothing
*/
void list_car_year_sort_year(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(sizeof(car));
  car_list listed_cars;
  listed_cars.number_of_cars = 0;
  listed_cars.car = (car *)malloc(0);
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1026|125|Audi|A6|white|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|BW 0024|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1023|125|Opel|A6|green|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);

  command.filter_field = COLOR;
  strcpy(command.filter_value, "7");
  command.sort_field = YEAR;
  command.sort_ascending = true;
  ret_code = list_car(&list, &command, &listed_cars);

  assert_int_equal(list.number_of_cars, 6);
  assert_int_equal(listed_cars.number_of_cars, 2);
  assert_int_equal(ret_code, 0);
  assert_string_equal(listed_cars.car[0].license_plate, "AUD 1027");
  assert_string_equal(listed_cars.car[1].license_plate, "BW 0024");

  command.filter_field = COLOR;
  strcpy(command.filter_value, "7");
  command.sort_field = YEAR;
  command.sort_ascending = false;
  ret_code = list_car(&list, &command, &listed_cars);

  assert_int_equal(listed_cars.number_of_cars, 2);
  assert_string_equal(listed_cars.car[0].license_plate, "BW 0024");
  assert_string_equal(listed_cars.car[1].license_plate, "AUD 1027");

  free(list.car);
  free(listed_cars.car);
} /* list_car_year_sort_year */

/*
  Name:        delete_car_field_power

  Purpose:     Test function delete_car for valid result while filtering power

  Params:      IN    state
              
  Returns:     Nothing
*/
void delete_car_field_power(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(sizeof(car));
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1026|125|Audi|A6|white|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|BW 1024|400|Bmw|X5|black|2019|"); //DECE
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1023|125|Opel|A6|green|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);

  command.filter_field = POWER;
  strcpy(command.filter_value, "400");
  ret_code = delete_car(&list, &command);

  assert_int_equal(list.number_of_cars, 3);
  assert_int_equal(ret_code, 0);
  assert_string_equal(list.car[0].license_plate, "AUD 1026");
  assert_string_equal(list.car[1].license_plate, "AUD 1024");
  assert_string_equal(list.car[2].license_plate, "AUD 1023");

  free(list.car);
} /* delete_car_field_power */

/*
  Name:        delete_car_field_power_10element_list

  Purpose:     Test function delete_car for valid result while filtering power

  Params:      IN    state
              
  Returns:     Nothing
*/
void delete_car_field_power_10element_list(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(sizeof(car));
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1026|125|Audi|A6|white|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1021|125|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|125|Opel|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1023|400|Opel|A6|green|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1028|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1029|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1030|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1031|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1032|125|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);

  command.filter_field = POWER;
  strcpy(command.filter_value, "400");
  ret_code = delete_car(&list, &command);

  assert_int_equal(list.number_of_cars, 6);
  assert_int_equal(ret_code, 0);
  assert_string_equal(list.car[0].license_plate, "AUD 1026");
  assert_string_equal(list.car[1].license_plate, "AUD 1021");
  assert_string_equal(list.car[2].license_plate, "AUD 1024");
  assert_string_equal(list.car[3].license_plate, "AUD 1025");
  assert_string_equal(list.car[4].license_plate, "AUD 1029");
  assert_string_equal(list.car[5].license_plate, "AUD 1032");
  free(list.car);
} /* delete_car_field_power_10element_list */

/*
  Name:        delete_all_elements

  Purpose:     Test function delete_car for delete all elements in list

  Params:      IN    state
              
  Returns:     Nothing
*/
void delete_all_elements(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(0);
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1026|400|Audi|A6|white|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1021|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|400|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1023|400|Opel|A6|green|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1028|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1029|400|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1030|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1031|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1032|400|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);

  command.filter_field = POWER;
  strcpy(command.filter_value, "400");
  ret_code = delete_car(&list, &command);

  assert_int_equal(list.number_of_cars, 0);
  assert_int_equal(ret_code, 0);

  free(list.car);
} /* delete_all_elements */

/*
  Name:        delete_zero_elements

  Purpose:     Test function delete_car for delete 0 elements in list

  Params:      IN    state
              
  Returns:     Nothing
*/
void delete_zero_elements(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(0);
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1026|400|Audi|A6|white|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1021|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|400|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1023|400|Opel|A6|green|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1028|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1029|400|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1030|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1031|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1032|400|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);

  command.filter_field = POWER;
  strcpy(command.filter_value, "125");
  ret_code = delete_car(&list, &command);

  assert_int_equal(list.number_of_cars, 11);
  assert_int_equal(ret_code, 0);

  free(list.car);
} /* delete_zero_elements */

/*
  Name:        delete_first_4_elements

  Purpose:     Test function delete_car for delete first 4 elements from list
               by field = license plate

  Params:      IN    state
              
  Returns:     Nothing
*/
void delete_first_4_elements(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(0);
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1026|400|Audi|A6|white|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1021|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|400|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A6|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1023|400|Opel|A6|green|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1028|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1029|400|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1030|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1031|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1032|400|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);

  command.filter_field = LICENSE_PLATE;
  strcpy(command.filter_value, "AUD 1026");
  ret_code = delete_car(&list, &command);
  strcpy(command.filter_value, "AUD 1021");
  ret_code = delete_car(&list, &command);
  strcpy(command.filter_value, "AUD 1024");
  ret_code = delete_car(&list, &command);
  strcpy(command.filter_value, "AUD 1025");
  ret_code = delete_car(&list, &command);

  assert_int_equal(list.number_of_cars, 7);
  assert_int_equal(ret_code, 0);
  assert_string_equal(list.car[0].license_plate, "AUD 1023");
  assert_string_equal(list.car[6].license_plate, "AUD 1032");

  free(list.car);
} /* delete_first_4_elements */

/*
  Name:        delete_last_4_elements

  Purpose:     Test function delete_car for delete last 4 elements from list
               by field = model

  Params:      IN    state
              
  Returns:     Nothing
*/
void delete_last_4_elements(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(0);
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1026|400|Audi|A8|white|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1021|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|400|Audi|A2|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A3|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1023|400|Opel|A4|green|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A5|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1028|400|Audi|A5|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1029|400|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1030|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1031|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1032|400|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);

  command.filter_field = MODEL;
  strcpy(command.filter_value, "A6");
  ret_code = delete_car(&list, &command);

  assert_int_equal(list.number_of_cars, 7);
  assert_int_equal(ret_code, 0);
  assert_string_equal(list.car[0].license_plate, "AUD 1026");
  assert_string_equal(list.car[6].license_plate, "AUD 1028");
  assert_string_not_equal(list.car[7].license_plate, "AUD 1029");

  free(list.car);
} /* delete_last_4_elements */

/*
  Name:        delete_first_and_last_elements

  Purpose:     Test function delete_car for delete first and 
               last  element from list by field = year

  Params:      IN    state
              
  Returns:     Nothing
*/
void delete_first_and_last_elements(void **state)
{
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(0);
  car_command command;
  int ret_code;

  strcpy(command.detail, "|AUD 1026|400|Audi|A8|white|2017|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1021|400|Bmw|X5|black|2019|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1024|400|Audi|A2|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1025|400|Opel|A3|yellow|2018|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1023|400|Opel|A4|green|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1027|400|Audi|A5|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1028|400|Audi|A5|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1029|400|Audi|A6|red|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1030|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1031|400|Audi|A6|black|2016|");
  ret_code = add_car(&list, &command);
  strcpy(command.detail, "|AUD 1032|400|Audi|A6|red|2017|");
  ret_code = add_car(&list, &command);

  command.filter_field = YEAR;
  strcpy(command.filter_value, "2017");
  ret_code = delete_car(&list, &command);

  assert_int_equal(list.number_of_cars, 9);
  assert_int_equal(ret_code, 0);
  assert_string_equal(list.car[0].license_plate, "AUD 1021");
  assert_string_equal(list.car[8].license_plate, "AUD 1031");

  free(list.car);
} /* delete_first_and_last_elements */