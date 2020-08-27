
/*
  Name:        test_main.c

  Purpose:     In this file are tested maximum and minimum
               functions from operations.c
*/


#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/operations.h"
void maximum_valid(void **state);
void minimum_valid(void **state);
void minimum_negativ(void **state);
void maximum_all_negative(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{

  const struct CMUnitTest tests[] = {
      cmocka_unit_test(maximum_valid),
      cmocka_unit_test(minimum_valid),
      cmocka_unit_test(minimum_negativ),
      cmocka_unit_test(maximum_all_negative),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        maximum_valid

  Purpose:     tested function maximum with positive values

  Params:      IN    state
              
  Returns:     Nothing

*/
void maximum_valid(void **state)
{
  int result = maximum(4, 5, 6);

  assert_int_equal(result, 6);
} /* maximum_valid */

/*
  Name:        maximum_all_negative

  Purpose:     tested function maximum with negative values

  Params:      IN    state
              
  Returns:     Nothing

*/
void maximum_all_negative(void **state)
{
  int result = maximum(-4, -5, -6);

  assert_int_equal(result, -4);
} /* maximum_all_negative */

/*
  Name:        minimum_valid

  Purpose:     tested function minimum with positive values

  Params:      IN    state
              
  Returns:     Nothing

*/
void minimum_valid(void **state)
{
  int result = minimum(4, 5, 6);

  assert_int_equal(result, 4);
} /* minimum_valid */

/*
  Name:        minimum_negativ

  Purpose:     tested function minimum with negative values

  Params:      IN    state
              
  Returns:     Nothing

*/
void minimum_negativ(void **state)
{
  int result = minimum(4, 5, -6);

  assert_int_equal(result, -6);
} /* minimum_negativ */
