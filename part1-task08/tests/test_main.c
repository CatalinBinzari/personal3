
/*
  Name:        test_main.c

  Purpose:     This file contains tests for whether the number is positive, negative or zero 
             with if statement and switch statement
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/number.h"
void number_state_with_if_stmt_valid_negative(void **state);
void number_state_with_if_stmt_valid_positive(void **state);
void number_state_with_if_stmt_valid_zero(void **state);
void number_state_with_switch_stmt_valid_zero(void **state);
void number_state_with_switch_stmt_valid_positive(void **state);
void number_state_with_switch_stmt_valid_negative(void **state);
void parallel_functions_comparation(void **state);
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(number_state_with_if_stmt_valid_negative),
      cmocka_unit_test(number_state_with_if_stmt_valid_positive),
      cmocka_unit_test(number_state_with_if_stmt_valid_zero),
      cmocka_unit_test(number_state_with_switch_stmt_valid_zero),
      cmocka_unit_test(number_state_with_switch_stmt_valid_positive),
      cmocka_unit_test(number_state_with_switch_stmt_valid_negative),
      cmocka_unit_test(parallel_functions_comparation),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        number_state_with_if_stmt_valid_negative

  Purpose:     Test that number_state_with_if_stmt works with negative values. 

  Params:      IN    state
              
  Returns:     Nothing

*/
void number_state_with_if_stmt_valid_negative(void **state)
{
  int fstate = number_state_with_if_stmt(-5);

  assert_int_equal(fstate, -1);
} /* number_state_with_if_stmt_valid_negative */

/*
  Name:        number_state_with_if_stmt_valid_positive

  Purpose:     Test that number_state_with_if_stmt works with positive values. 

  Params:      IN    state
              
  Returns:     Nothing

*/
void number_state_with_if_stmt_valid_positive(void **state)
{
  int fstate = number_state_with_if_stmt(5);

  assert_int_equal(fstate, 1);
} /* number_state_with_if_stmt_valid_positive */

/*
  Name:        number_state_with_if_stmt_valid_zero

  Purpose:     Test that number_state_with_if_stmt works with zero value. 

  Params:      IN    state
              
  Returns:     Nothing

*/
void number_state_with_if_stmt_valid_zero(void **state)
{
  int fstate = (0);

  assert_int_equal(fstate, 0);
} /* number_state_with_if_stmt_valid_zero */

/*number_state_with_if_stmt
  Name:        number_state_with_switch_stmt_valid_positive

  Purpose:     Test that number_state_with_switch_stmt works with positive value. 

  Params:      IN    state
              
  Returns:     Nothing

*/
void number_state_with_switch_stmt_valid_positive(void **state)
{
  int fstate = number_state_with_switch_stmt(5);

  assert_int_equal(fstate, 1);
} /* number_state_with_switch_stmt_valid_positive */

/*
  Name:        number_state_with_switch_stmt_valid_negative

  Purpose:     Test that number_state_with_switch_stmt works with negative value. 

  Params:      IN    state
              
  Returns:     Nothing

*/
void number_state_with_switch_stmt_valid_negative(void **state)
{
  int fstate = number_state_with_switch_stmt(-5);

  assert_int_equal(fstate, -1);
} /* number_state_with_switch_stmt_valid_negative */

/*
  Name:        number_state_with_switch_stmt_valid_zero

  Purpose:     Test that number_state_with_switch_stmt works with zero value. 

  Params:      IN    state
              
  Returns:     Nothing

*/
void number_state_with_switch_stmt_valid_zero(void **state)
{
  int fstate = number_state_with_switch_stmt(0);

  assert_int_equal(fstate, 0);
} /* number_state_with_switch_stmt_valid_zero */

/*
  Name:        parallel_functions_comparation

  Purpose:     Test if both functions gives the same value. 

  Params:      IN    state
              
  Returns:     Nothing

*/
void parallel_functions_comparation(void **state)
{
  int positive_if_stmt = number_state_with_if_stmt(5.055);
  int positive_switch_stmt = number_state_with_switch_stmt(5.055);

  int negative_if_stmt = number_state_with_if_stmt(-5.055);
  int negative_switch_stmt = number_state_with_switch_stmt(-5.055);

  int zero_if_stmt = number_state_with_if_stmt(0);
  int zero_switch_stmt = number_state_with_switch_stmt(0);

  assert_int_equal(positive_if_stmt, positive_switch_stmt);
  assert_int_equal(negative_if_stmt, negative_switch_stmt);
  assert_int_equal(zero_if_stmt, zero_switch_stmt);
} /* parallel_functions_comparation */
