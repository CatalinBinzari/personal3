
/*
  Name:        test_main.c

  Purpose:     This file contains tests for validating 
               adding of two fractions, with positive ande negative 
               denominators and numerators 
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include "../src/fraction.h"

void add_valid(void **state);
void add_negative_values(void **state);
void add_values_different_numerator(void **state);
void add_values_different_denominator(void **state);
void get_sign_positive_val(void **state);
void get_sign_zero(void **state);
void get_sign_negative_val(void **state);
void get_sign_both_negative(void **state);
void get_sign_negative_denominator(void **state);
void format_denominator(void **state);
void format_denominator_and_numerator(void **state);
void format_nothing(void **state);
void format_nothing_positive_denominator(void **state);
void add_both_negative(void **state);
void add_both_denominators_negative(void **state);
void add_both_zero_denominator(void **state);
void add_both_zero_numerator(void **state);
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(add_valid),
      cmocka_unit_test(add_negative_values),
      cmocka_unit_test(add_values_different_denominator),
      cmocka_unit_test(add_values_different_numerator),
      cmocka_unit_test(get_sign_positive_val),
      cmocka_unit_test(get_sign_zero),
      cmocka_unit_test(get_sign_negative_val),
      cmocka_unit_test(get_sign_both_negative),
      cmocka_unit_test(get_sign_negative_denominator),
      cmocka_unit_test(format_denominator),
      cmocka_unit_test(format_denominator_and_numerator),
      cmocka_unit_test(format_nothing),
      cmocka_unit_test(format_nothing_positive_denominator),
      cmocka_unit_test(add_both_negative),
      cmocka_unit_test(add_both_denominators_negative),
      cmocka_unit_test(add_both_zero_denominator),
      cmocka_unit_test(add_both_zero_numerator),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        add_valid

  Purpose:     Test function add for valid result

  Params:      IN    state
              
  Returns:     Nothing

*/
void add_valid(void **state)
{

  struct fraction frac1 = {5, 8};
  struct fraction frac2 = {3, 8};
  struct fraction res;
  res = add(frac1, frac2);

  assert_int_equal(res.numerator, 1);
  assert_int_equal(res.denominator, 1);

} /* add_valid */

/*
  Name:        add_negative_values

  Purpose:     Test function add for result with negative values

  Params:      IN    state
              
  Returns:     Nothing

*/
void add_negative_values(void **state)
{

  struct fraction frac1 = {-4, 8};
  struct fraction frac2 = {3, 8};
  struct fraction res;
  res = add(frac1, frac2);

  assert_int_equal(res.numerator, -1);
  assert_int_equal(res.denominator, 8);

} /* add_negative_values */

/*
  Name:        add_values_different_numerator

  Purpose:     Test function add for result with values

  Params:      IN    state
              
  Returns:     Nothing

*/
void add_values_different_numerator(void **state)
{

  struct fraction frac1 = {4, 8};
  struct fraction frac2 = {3, 8};
  struct fraction res;
  res = add(frac1, frac2);

  assert_int_equal(res.numerator, 7);
  assert_int_equal(res.denominator, 8);

} /* add_values_different_numerator */

/*
  Name:        add_values_different_denominator

  Purpose:     Test function add for result with vdifferent denominator

  Params:      IN    state
              
  Returns:     Nothing

*/
void add_values_different_denominator(void **state)
{

  struct fraction frac1 = {4, 7};
  struct fraction frac2 = {3, 8};
  struct fraction res;
  res = add(frac1, frac2);

  assert_int_equal(res.numerator, 53);
  assert_int_equal(res.denominator, 56);

} /* add_values_different_denominator */

/*
  Name:        get_sign_positive_val

  Purpose:     Test function get_sign with positive fraction

  Params:      IN    state
              
  Returns:     Nothing

*/
void get_sign_positive_val(void **state)
{

  struct fraction frac = {4, 7};
  int sign = get_sign(frac);

  assert_int_equal(sign, 1);
  

} /* get_sign_positive_val */

/*
  Name:        get_sign_zero

  Purpose:     Test function get_sign with fraction with zero numerator

  Params:      IN    state
              
  Returns:     Nothing

*/
void get_sign_zero(void **state)
{

  struct fraction frac = {0, 7};
  int sign = get_sign(frac);

  assert_int_equal(sign, 1);
} /* get_sign_zero */

/*
  Name:        get_sign_negative_val

  Purpose:     Test function get_sign with fraction with negative numerator

  Params:      IN    state
              
  Returns:     Nothing

*/
void get_sign_negative_val(void **state)
{

  struct fraction frac = {-3, 7};
  int sign = get_sign(frac);

  assert_int_equal(sign, -1);
} /* get_sign_negative_val */

/*
  Name:        get_sign_both_negative

  Purpose:     Test function get_sign with fraction with negative numerator
               and negative denominator

  Params:      IN    state
              
  Returns:     Nothing

*/
void get_sign_both_negative(void **state)
{

  struct fraction frac = {-3, -7};
  int sign = get_sign(frac);

  assert_int_equal(sign, 1);
} /* get_sign_both_negative */

/*
  Name:        get_sign_negative_denominator

  Purpose:     Test function get_sign with fraction with negative denominator

  Params:      IN    state
              
  Returns:     Nothing

*/
void get_sign_negative_denominator(void **state)
{

  struct fraction frac = {3, -7};
  int sign = get_sign(frac);

  assert_int_equal(sign, -1);
} /* get_sign_negative_denominator */

/*
  Name:        format_denominator

  Purpose:     Test function format with fraction 
               containing negative denominator

  Params:      IN    state
              
  Returns:     Nothing

*/
void format_denominator(void **state)
{
  struct fraction frac = {3, -7};
  format(&frac);

  assert_int_equal(frac.numerator, -3);
  assert_int_equal(frac.denominator, 7);
} /* format_denominator */

/*
  Name:        format_denominator_and_numerator

  Purpose:     Test function format with fraction 
               containing negative denominator and nevative numerator

  Params:      IN    state
              
  Returns:     Nothing

*/
void format_denominator_and_numerator(void **state)
{
  struct fraction frac = {-3, -7};
  format(&frac);

  assert_int_equal(frac.numerator, 3);
  assert_int_equal(frac.denominator, 7);
} /* format_denominator_and_numerator */

/*
  Name:        format_nothing

  Purpose:     Test function format with fraction 
               containing positive denominator and positive numerator

  Params:      IN    state
              
  Returns:     Nothing

*/
void format_nothing(void **state)
{
  struct fraction frac = {3, 7};
  format(&frac);

  assert_int_equal(frac.numerator, 3);
  assert_int_equal(frac.denominator, 7);
} /* format_nothing */

/*
  Name:        format_nothing_positive_denominator

  Purpose:     Test function format with fraction 
               containing positive denominator and negativ numerator

  Params:      IN    state
              
  Returns:     Nothing

*/
void format_nothing_positive_denominator(void **state)
{
  struct fraction frac = {-3, 7};
  format(&frac);

  assert_int_equal(frac.numerator, -3);
  assert_int_equal(frac.denominator, 7);
} /* format_nothing_positive_denominator */

/*
  Name:        add_both_negative

  Purpose:     Test function add for result with negative values

  Params:      IN    state
              
  Returns:     Nothing

*/
void add_both_negative(void **state)
{

  struct fraction frac1 = {-4, -8};
  struct fraction frac2 = {-3, -8};
  struct fraction res;
  res = add(frac1, frac2);

  assert_int_equal(res.numerator, 7);
  assert_int_equal(res.denominator, 8);

} /* add_both_negative */

/*
  Name:        add_both_denominators_negative

  Purpose:     Test function add for result with negative values

  Params:      IN    state
              
  Returns:     Nothing
*/
void add_both_denominators_negative(void **state)
{
  struct fraction frac1 = {4, -8};
  struct fraction frac2 = {3, -8};
  struct fraction res;
  res = add(frac1, frac2);

  assert_int_equal(res.numerator, -7);
  assert_int_equal(res.denominator, 8);

} /* add_both_denominators_negative */

/*
  Name:        add_both_zero_denominator

  Purpose:     Test function add for result if denominator is 0

  Params:      IN    state
              
  Returns:     Nothing
*/
void add_both_zero_denominator(void **state)
{
  struct fraction frac1 = {8, 0};
  struct fraction frac2 = {9, 0};
  struct fraction res;

  res = add(frac1, frac2);

  assert_int_equal(res.numerator, 0);
  assert_int_equal(res.denominator, 0);

} /* add_both_zero_denominator */

/*
  Name:        add_both_zero_numerator

  Purpose:     Test function add for result if numerator is 0

  Params:      IN    state
              
  Returns:     Nothing
*/
void add_both_zero_numerator(void **state)
{
  struct fraction frac1 = {0, 4};
  struct fraction frac2 = {0, 9};
  struct fraction res;

  res = add(frac1, frac2);

  assert_int_equal(res.numerator, 0);
  assert_int_equal(res.denominator, 1);

} /* add_both_zero_numerator */