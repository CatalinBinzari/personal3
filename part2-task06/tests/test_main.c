
/*
  Name:        test_main.c

  Purpose:     This file contains tests for validating 
               sorting with buuble array and  arithmetic mean 
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/student.h"

void sort_by_grade_valid(void **state);
void arithmetic_mean_valid(void **state);
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(sort_by_grade_valid),
      cmocka_unit_test(arithmetic_mean_valid),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        sort_by_grade_valid

  Purpose:     Test function sort_by_grade for valid result

  Params:      IN    state
              
  Returns:     Nothing

*/
void sort_by_grade_valid(void **state)
{

  struct student students[STUD_NR] = {{"name1", "surname1", 89.5},
                                      {"name2", "surname2", 100.00},
                                      {"name3", "surname3", 67.5},
                                      {"name4", "surname4", 95.5},
                                      {"name5", "surname5", 33.3},
                                      {"name6", "surname6", 22.7},
                                      {"name7", "surname7", 89.5},
                                      {"name8", "surname8", 0},
                                      {"name9", "surname9", 99.9}};
  sort_by_grade(students, STUD_NR);

  assert_float_equal(students[0].grade, 100.00, 0.001);
  assert_float_equal(students[1].grade, 99.9, 0.001);
  assert_float_equal(students[7].grade, 22.7, 0.001);
  assert_float_equal(students[8].grade, 0, 0.001);

} /* sort_by_grade_valid */

/*
  Name:        arithmetic_mean_valid

  Purpose:     Test function arithmetic_mean for valid result

  Params:      IN    state
              
  Returns:     Nothing

*/
void arithmetic_mean_valid(void **state)
{

  struct student students[STUD_NR] = {{"name1", "surname1", 89.5},
                                      {"name2", "surname2", 100.00},
                                      {"name3", "surname3", 67.5},
                                      {"name4", "surname4", 95.5},
                                      {"name5", "surname5", 33.3},
                                      {"name6", "surname6", 22.7},
                                      {"name7", "surname7", 89.5},
                                      {"name8", "surname8", 0},
                                      {"name9", "surname9", 99.9}};
  double res = arithmetic_mean(students, STUD_NR);

  assert_float_equal(res, 66.43, 0.01);

} /* arithmetic_mean_valid */
