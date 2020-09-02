
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
#include <stdio.h>

#include "../src/student.h"

void sort_by_grade_valid(void **state);
void arithmetic_mean_valid(void **state);
void new_student_valid(void **state);
void add_students_valid(void **state);
void add_students_invalid_err_code_2(void **state);
void add_students_invalid_err_code_1(void **state);
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(sort_by_grade_valid),
      cmocka_unit_test(arithmetic_mean_valid),
      /*cmocka_unit_test(new_student_valid),*/
      cmocka_unit_test(add_students_valid),
      cmocka_unit_test(add_students_invalid_err_code_2),
      cmocka_unit_test(add_students_invalid_err_code_1),

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

  struct student students[9] = {{"name1", "surname1", 89.5},
                                {"name2", "surname2", 100.00},
                                {"name3", "surname3", 67.5},
                                {"name4", "surname4", 95.5},
                                {"name5", "surname5", 33.3},
                                {"name6", "surname6", 22.7},
                                {"name7", "surname7", 89.5},
                                {"name8", "surname8", 0},
                                {"name9", "surname9", 99.9}};
  sort_by_grade(students, 9);

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

  struct student students[9] = {{"name1", "surname1", 89.5},
                                {"name2", "surname2", 100.00},
                                {"name3", "surname3", 67.5},
                                {"name4", "surname4", 95.5},
                                {"name5", "surname5", 33.3},
                                {"name6", "surname6", 22.7},
                                {"name7", "surname7", 89.5},
                                {"name8", "surname8", 0},
                                {"name9", "surname9", 99.9}};
  double res = arithmetic_mean(students, 9);

  assert_float_equal(res, 66.43, 0.01);
} /* arithmetic_mean_valid */

/*
  Name:        new_student_valid

  Purpose:     Test function new_student for valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void new_student_valid(void **state)
{
  struct student student_to_add;
  student_to_add = new_student();

  assert_string_equal(student_to_add.name, "testname");
  assert_string_equal(student_to_add.surname, "testsurname");
  assert_float_equal(student_to_add.grade, 56.08, 0.01);
} /* new_student_valid */

/*
  Name:        add_students_valid

  Purpose:     Test function add_students for err_code 0

  Params:      IN    state
              
  Returns:     Nothing
*/
void add_students_valid(void **state)
{
  struct student students[3];
  struct student student_to_add;
  int student_counter = 2;

  student_to_add.name = "testname";
  student_to_add.surname = "testsurname";
  student_to_add.grade = 58.09;

  int err_code = add_students(students, &student_counter, student_to_add, 3);
  
  assert_string_equal(students[2].name, student_to_add.name);
  assert_string_equal(students[2].surname, student_to_add.surname);
  assert_float_equal(students[2].grade, student_to_add.grade, 0.01);
  assert_int_equal(student_counter, 3);
  assert_int_equal(err_code, 0);
} /* add_students_valid */

/*
  Name:        add_students_invalid_err_code_2

  Purpose:     Test function add_students for err_code 2

  Params:      IN    state
              
  Returns:     Nothing
*/
void add_students_invalid_err_code_2(void **state)
{
  struct student students[3];
  struct student student_to_add;
  int student_counter = 2;

  student_to_add.name = "testname";
  student_to_add.surname = "testsurname";
  student_to_add.grade = -58.09;

  int err_code = add_students(students, &student_counter, student_to_add, 3);
  
  assert_string_not_equal(students[2].name, student_to_add.name);
  assert_string_not_equal(students[2].surname, student_to_add.surname);
  assert_float_not_equal(students[2].grade, student_to_add.grade, 0.01);
  assert_int_not_equal(student_counter, 3);
  assert_int_equal(err_code, 2);
} /* add_students_invalid_err_code_2 */

/*
  Name:        add_students_invalid_err_code_1

  Purpose:     Test function add_students for err_code 1

  Params:      IN    state
              
  Returns:     Nothing
*/
void add_students_invalid_err_code_1(void **state)
{
  struct student students[3];
  struct student student_to_add;
  int student_counter = 3;

  student_to_add.name = "testname";
  student_to_add.surname = "testsurname";
  student_to_add.grade = 58.09;

  int err_code = add_students(students, &student_counter, student_to_add, 3);

  assert_string_not_equal(students[2].name, student_to_add.name);
  assert_string_not_equal(students[2].surname, student_to_add.surname);
  assert_float_not_equal(students[2].grade, student_to_add.grade, 0.01);
  assert_int_equal(student_counter, 3);
  assert_int_equal(err_code, 1);
} /* add_students_invalid_err_code_1 */