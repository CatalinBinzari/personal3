
/*
  Name:        test_main.c

  Purpose:     Test string manipulation functions from string.c file
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
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        verify_student_code_exists_invalid

  Purpose:     Test function verify student code for valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void verify_student_code_exists_invalid(void **state)
{
  FILE *f_ptr = fopen("/home/user/workspace/part3-task03/src/student.txt", "r");
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
  FILE *f_ptr = fopen("/home/user/workspace/part3-task03/src/student.txt", "r");
  int ret_code = verify_student_code_exists(f_ptr, "10004");
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
  FILE *f_ptr = fopen("/home/user/workspace/part3-task03/src/student.txt", "a");
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
  FILE *f_ptr = fopen("/home/user/workspace/part3-task03/src/student1.txt", "a");
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
