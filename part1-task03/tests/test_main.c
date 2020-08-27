
/*
  Name:        test_main.c

  Purpose:     This file contains tests for converting Fahrenheit to Celsius
*/


#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/temperature.h"

void fahrenheit_to_celsius_valid(void **state);
void fahrenheit_to_celsius_minus(void **state);
void fahrenheit_to_celsius_int(void **state);
void fahrenheit_to_celsius_double(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(fahrenheit_to_celsius_valid),
      cmocka_unit_test(fahrenheit_to_celsius_minus),
      cmocka_unit_test(fahrenheit_to_celsius_int),
      cmocka_unit_test(fahrenheit_to_celsius_double),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        fahrenheit_to_celsius_valid

  Purpose:     Testing if fahrenheit_to_celsius function gives valid result

  Params:      IN    state
              
  Returns:     Nothing

*/
void fahrenheit_to_celsius_valid(void **state)
{
  float result = fahrenheit_to_celsius(32.6);

  assert_float_equal(result, 0.3333333, 0.0001);
} /* fahrenheit_to_celsius_valid */

/*
  Name:        fahrenheit_to_celsius_minus

  Purpose:     Testing if fahrenheit_to_celsius function gives valid result
               with minus values.

  Params:      IN    state
              
  Returns:     Nothing

*/
void fahrenheit_to_celsius_minus(void **state)
{
  float result = fahrenheit_to_celsius(-32.6);

  assert_float_equal(result, -35.8889, 0.0001);
} /* fahrenheit_to_celsius_minus */

/*
  Name:        fahrenheit_to_celsius_int

  Purpose:     Testing if fahrenheit_to_celsius function gives valid result
               with integer values.
  
  Params:      IN    state
              
  Returns:     Nothing

               
*/
void fahrenheit_to_celsius_int(void **state)
{
  float result = fahrenheit_to_celsius(32);

  assert_float_equal(result, 0, 0.0001);
} /* fahrenheit_to_celsius_int */

/*
  Name:        fahrenheit_to_celsius_double

  Purpose:     Testing if fahrenheit_to_celsius function gives valid result
               with double values.
  
  Params:      IN    state
              
  Returns:     Nothing

*/
void fahrenheit_to_celsius_double(void **state)
{
  float result = fahrenheit_to_celsius(0.0000032);

  assert_float_equal(result, -17.777776, 0.0001);
} /* fahrenheit_to_celsius_double */
