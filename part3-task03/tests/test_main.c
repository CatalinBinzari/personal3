
/*
  Name:        test_main.c

  Purpose:     Test data manipulation from student, graduate, grades files
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

#include "../src/file.h"

void verify_student_code_exists_valid(void **state);
void verify_student_code_exists_invalid(void **state);
void append_to_file_valid(void **state);
void append_to_file_when_file_dont_exist(void **state);
void concat_and_format_valid(void **state);
void verify_grades_valid(void **state);
void grades_to_string_valid(void **state);
void grades_to_string_invalid(void **state);
void view_graduated_valid(void **state);
void get_name_surname_by_student_code_valid(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(verify_student_code_exists_valid),
      cmocka_unit_test(verify_student_code_exists_invalid),
      cmocka_unit_test(append_to_file_valid),
      cmocka_unit_test(append_to_file_when_file_dont_exist),
      cmocka_unit_test(concat_and_format_valid),
      cmocka_unit_test(verify_grades_valid),
      cmocka_unit_test(grades_to_string_valid),
      cmocka_unit_test(grades_to_string_invalid),
      cmocka_unit_test(view_graduated_valid),
      cmocka_unit_test(get_name_surname_by_student_code_valid),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        verify_student_code_exists_invalid

  Purpose:     Test function verify student code for invalid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void verify_student_code_exists_invalid(void **state)
{
  FILE *f_ptr = fopen("/home/user/workspace/part3-task03/tests/student_test.txt", "r");
  int ret_code = verify_student_code_exists(f_ptr, "00001");
  fclose(f_ptr);

  assert_int_equal(ret_code, -2);
} /* verify_student_code_exists_invalid */

/*
  Name:        verify_student_code_exists_valid

  Purpose:     Test function verify_student_code_exists for valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void verify_student_code_exists_valid(void **state)
{
  FILE *f_ptr = fopen("/home/user/workspace/part3-task03/tests/student_test.txt", "r");
  int ret_code = verify_student_code_exists(f_ptr, "11004");
  fclose(f_ptr);

  assert_int_equal(ret_code, 0);
} /* verify_student_code_exists_valid */

/*
  Name:        append_to_file_valid

  Purpose:     Test function append_to_file for valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void append_to_file_valid(void **state)
{
  FILE *f_ptr = fopen("/home/user/workspace/part3-task03/tests/student_test.txt", "a");
  char str_to_append[100] = "00004, name7, name8, 78.90\n";
  int err_code = append_to_file(f_ptr, str_to_append);
  fclose(f_ptr);

  assert_int_equal(err_code, 0);
} /* append_to_file_valid */

/*
  Name:        append_to_file_when_file_dont_exist

  Purpose:     Test function append_to_file when file does not exists

  Params:      IN    state
              
  Returns:     Nothing
*/
void append_to_file_when_file_dont_exist(void **state)
{
  FILE *f_ptr = fopen("/home/user/workspace/part3-task03/tests/student_test.txt", "a");
  char str_to_append[100] = "00004, name7, name8, 78.90\n";
  int err_code = append_to_file(f_ptr, str_to_append);
  fclose(f_ptr);

  assert_int_equal(err_code, 0);
} /* append_to_file_when_file_dont_exist */

/*
  Name:        concat_and_format_valid

  Purpose:     Test function concat_and_format for valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void concat_and_format_valid(void **state)
{
  student_data student;
  strcpy(student.student_code, "000cb");
  strcpy(student.f_name, "Catalin");
  strcpy(student.l_name, "Binzari");
  student.age = 21;
  char age_as_str[4];
  sprintf(age_as_str, "%d", student.age);

  char *res = concat_and_format(
      student.student_code, student.f_name, student.l_name, age_as_str);

  assert_string_equal(res, "000cb, Catalin, Binzari, 21\n");
  free(res);
} /* concat_and_format_valid */

/*
  Name:        concat_and_format_valid

  Purpose:     Test function verify_grades for valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void verify_grades_valid(void **state)
{
  student_grades grades = {"00000", 10, 10, 10};
  int err_code = verify_grades(grades);
  assert_int_equal(err_code, 0);

  student_grades grades1 = {"00000", 0, 10, 10};
  err_code = verify_grades(grades1);
  assert_int_equal(err_code, -3);

  student_grades grades2 = {"000000", 5, 10, 10};
  err_code = verify_grades(grades2);
  assert_int_equal(err_code, -3);
} /* verify_grades_valid */

/*
  Name:        grades_to_string_valid

  Purpose:     Test function grades_to_string for valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void grades_to_string_valid(void **state)
{
  int grade = 7;
  const char *res = grades_to_string(grade);

  assert_string_equal(res, "7");
} /* grades_to_string_valid */

/*
  Name:        grades_to_string_invalid

  Purpose:     Test function grades_to_string for valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void grades_to_string_invalid(void **state)
{
  int grade = 12;
  const char *res = grades_to_string(grade);

  assert_string_equal(res, "NaG");
} /* grades_to_string_invalid */

/*
  Name:        view_graduated_valid

  Purpose:     Test function view_graduated for valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void view_graduated_valid(void **state)
{
  int err_code = view_graduated();
  assert_int_equal(err_code, 0);
} /* view_graduated_valid */

void get_name_surname_by_student_code_valid(void **state)
{
  graduated_students_t graduated;
  strcpy(graduated.student_code, "00001");
  FILE *f_students = fopen("/home/user/workspace/part3-task03/tests/student_test.txt", "r");
  int ret_code = get_name_surname_by_student_code(f_students, graduated.student_code, graduated.f_name, graduated.l_name);
  assert_int_equal(ret_code, 0);
  assert_string_equal(graduated.f_name, "name1");
  assert_string_equal(graduated.l_name, "name2");
}
