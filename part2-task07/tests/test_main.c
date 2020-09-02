
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

void add_cars_verify_core_err_2(void **state);
void add_cars_verify_core_err_1(void **state);
void add_cars_verify_core_err_0(void **state);
void order_by_power_valid(void **state);
void display_valid(void **state);
void filter_by_year_valid(void **state);
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(add_cars_verify_core_err_2),
      cmocka_unit_test(add_cars_verify_core_err_1),
      cmocka_unit_test(add_cars_verify_core_err_0),
      cmocka_unit_test(order_by_power_valid),
      cmocka_unit_test(display_valid),
      cmocka_unit_test(filter_by_year_valid),

  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        add_cars_verify_core_err_2

  Purpose:     Test function add_cars for error code 2

  Params:      IN    state
              
  Returns:     Nothing
*/
void add_cars_verify_core_err_2(void **state)
{
  struct cars car[3];
  int number_of_cars = 0;
  struct cars car_to_add;
  car_to_add.number_of_seats = 9;
  car_to_add.power = 500;
  strcpy(car_to_add.brand, "BMW");
  strcpy(car_to_add.color, "black");
  car_to_add.year = 2020;

  int err_code = add_cars(car, &number_of_cars, car_to_add, 3);

  assert_int_equal(err_code, 2);
} /* add_cars_verify_core_err_2 */

/*
  Name:        add_cars_verify_core_err_1

  Purpose:     Test function add_cars for error code 1,
               when car array is full

  Params:      IN    state
              
  Returns:     Nothing
*/
void add_cars_verify_core_err_1(void **state)
{
  struct cars car[3];
  int number_of_cars = 3;
  struct cars car_to_add;
  car_to_add.number_of_seats = 4;
  car_to_add.power = 500;
  strcpy(car_to_add.brand, "BMW");
  strcpy(car_to_add.color, "black");
  car_to_add.year = 2020;

  int err_code = add_cars(car, &number_of_cars, car_to_add, 3);

  assert_int_equal(err_code, 1);
} /* add_cars_verify_core_err_1 */

/*
  Name:        add_cars_verify_core_err_0

  Purpose:     Test function add_cars for error code 0,
               when everything is okay

  Params:      IN    state
              
  Returns:     Nothing
*/
void add_cars_verify_core_err_0(void **state)
{
  struct cars car[3];
  int number_of_cars = 2;
  struct cars car_to_add;
  car_to_add.number_of_seats = 4;
  car_to_add.power = 500;
  strcpy(car_to_add.brand, "BMW");
  strcpy(car_to_add.color, "black");
  car_to_add.year = 2020;

  int err_code = add_cars(car, &number_of_cars, car_to_add, 3);
  assert_int_equal(err_code, 0);
  assert_int_equal(car_to_add.year, car[2].year);
  assert_int_equal(number_of_cars, 3);
} /* add_cars_verify_core_err_0 */

/*
  Name:        order_by_power_valid

  Purpose:     Test function order_by_power with valid structures;

  Params:      IN    state
              
  Returns:     Nothing
*/
void order_by_power_valid(void **state)
 { 
  //  int number_of_cars = 5;
  struct cars car[6] = {
    {2, 500, "test1", "test", 2001},
    {3, 300, "test2", "test", 2002},
    {4, 300, "test3", "test", 2003},
    {5, 100, "test4", "test", 2004},
    {6, 700, "test5", "test", 2005}
  };
  struct cars out_car[6];

  order_by_power(car, 5, out_car);
  
  assert_int_equal(out_car[0].power, 700);
  assert_int_equal(out_car[1].power, 500);
  assert_int_equal(out_car[2].power, 300);
  assert_int_equal(out_car[3].power, 300);
  assert_int_equal(out_car[4].power, 100);
} /* order_by_power_valid */

/*
  Name:        display_valid

  Purpose:     Test function display with valid structures;

  Params:      IN    state
              
  Returns:     Nothing
*/
void display_valid(void **state)
{ 
  struct cars car[6] = {
    {2, 500, "test1", "test", 2001},
    {3, 300, "test2", "test", 2002},
    {4, 300, "test3", "test", 2003},
    {5, 100, "test4", "test", 2004},
    {6, 700, "test5", "test", 2005}
  };
  display(car, 5);
} /* display_valid */

/*
  Name:        filter_by_year_valid

  Purpose:     Test function filter_by_year with valid structures;

  Params:      IN    state
              
  Returns:     Nothing
*/
void filter_by_year_valid(void **state)
{
  struct cars car[6] = {
    {2, 500, "test1", "test", 2001},
    {3, 300, "test2", "test", 2002},
    {4, 300, "test3", "test", 2003},
    {5, 100, "test4", "test", 2004},
    {6, 700, "test5", "test", 2005}
  };
  struct cars cars_filtered[6];
  int car_filtered_number;
  filter_by_year(car, 5, cars_filtered, &car_filtered_number, 2003);

  assert_int_equal(cars_filtered[0].year, 2003);
  assert_int_not_equal(cars_filtered[1].year, 2003);
  assert_int_equal(car_filtered_number, 1);
} /* filter_by_year_valid */
