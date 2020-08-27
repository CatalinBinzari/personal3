
/*
  Name:        test_main.c

  Purpose:     in this file are tested functions from operations.c
*/


#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/operations.h"

void sum_valid_int(void **state);
void sum_valid_double(void **state);
void difference_valid_int(void **state);
void difference_valid_double(void **state);
void product_valid_int(void **state);
void division_valid_int(void **state);
void division_valid_double(void **state);
void modulus_valid_int(void **state);
void average_valid_int(void **state);
void minimum_valid_int(void **state);
void maximum_valid_int(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
      cmocka_unit_test(sum_valid_int),
      cmocka_unit_test(sum_valid_double),
      cmocka_unit_test(difference_valid_int),
      cmocka_unit_test(difference_valid_double),
      cmocka_unit_test(product_valid_int),
      cmocka_unit_test(division_valid_int),
      cmocka_unit_test(division_valid_double),
      cmocka_unit_test(modulus_valid_int),
      cmocka_unit_test(average_valid_int),
      cmocka_unit_test(minimum_valid_int),
      cmocka_unit_test(maximum_valid_int),

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        sum_valid_int

  Purpose:     validate sum function with an int

  Returns:  Nothing
*/
void sum_valid_int(void **state)
{
  int result = sum(100, 200);

  assert_int_equal(result, 300);
} /* sum_valid_int */

/*
  Name:        sum_valid_double

  Purpose:     validate sum function with a double

  Returns:  Nothing
*/
void sum_valid_double(void **state)
{
  float result = sum(1.560, 2.7700);

  assert_float_equal(result, 4.33, 0.000001);
} /* sum_valid_double */

/*
  Name:        difference_valid_int

  Purpose:     validate difference function with an int

  Returns:  Nothing
*/
void difference_valid_int(void **state)
{
  int result = difference(200, 100);

  assert_int_equal(result, 100);
} /* difference_valid_int */

/*
  Name:        difference_valid_double

  Purpose:     validate difference function with a double

  Returns:  Nothing
*/
void difference_valid_double(void **state)
{
  float result = difference(2.67890, 1.0099);

  assert_float_equal(result, 1.669, 0.000001);
} /* difference_valid_double */

/*
  Name:        product_valid_int

  Purpose:     validate product function with an int

  Returns:  Nothing
*/
void product_valid_int(void **state)
{
  int result = product(200, 156);

  assert_int_equal(result, 31200);
} /* product_valid_int */

/*
  Name:        division_valid_int

  Purpose:     validate division function with an int

  Returns:  Nothing
*/
void division_valid_int(void **state)
{
  double result = division(30, 5);

  assert_int_equal(result, 6);
} /* division_valid_int */

/*
  Name:        division_valid_double

  Purpose:     validate division function with a double

  Returns:  Nothing
*/
void division_valid_double(void **state)
{
  double result = division(31, 5);

  assert_float_equal(result, 6.2, 0.00001);
} /* division_valid_double */

/*
  Name:        modulus_valid_int

  Purpose:     validate modulus function with an int

  Returns:  Nothing
*/
void modulus_valid_int(void **state)
{
  double result = modulus(33.3, 30);

  assert_int_equal(result, 3.3);
} /* modulus_valid_int */

/*
  Name:        average_valid_int

  Purpose:     validate average function with an int

  Returns:  Nothing
*/
void average_valid_int(void **state)
{
  int result = average(8, 20);

  assert_int_equal(result, 14);
} /* average_valid_int */

/*
  Name:        minimum_valid_int

  Purpose:     validate minimum function with an int

  Returns:  Nothing
*/
void minimum_valid_int(void **state)
{
  int result = minimum(8, 20);

  assert_int_equal(result, 8);
} /* minimum_valid_int */

/*
  Name:        maximum_valid_int

  Purpose:     validate maximum function with an int

  Returns:  Nothing
*/
void maximum_valid_int(void **state)
{
  int result = maximum(8, 20);

  assert_int_equal(result, 20);
} /* maximum_valid_int */
