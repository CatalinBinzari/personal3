
/*
  Name:        test_main.c

  Purpose:     This file contains tests for validating 
               the person with greater age 
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/person.h"

void greater_age_valid(void **state);
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(greater_age_valid),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        greater_age_valid

  Purpose:     Test function greater_age for valid result

  Params:      IN    state
              
  Returns:     Nothing

*/
void greater_age_valid(void **state)
{
  struct person p1={"name1", 3};
  struct person p2={"name2", 8};
  struct person p3;
  p3 = greater_age(p1, p2);

  assert_string_equal(p3.name, "name2");
  assert_int_equal(p3.age, 8);

} /* greater_age_valid */
