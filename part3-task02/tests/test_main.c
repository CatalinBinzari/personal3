
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

 void parse_file_valid(void **state);
 
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(parse_file_valid),

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        parse_file_valid

  Purpose:     Test function parse_file using test file in.txt

  Params:      IN    state
              
  Returns:     Nothing
*/
void parse_file_valid(void **state)
{
  FILE *f_ptr = fopen("/home/user/workspace/part3-task02/src/in.txt", "r");
  statistic stats = {0};
  parse_file(f_ptr, &stats);

  assert_int_equal(stats.characters, 273);
  assert_int_equal(stats.words, 50);
  assert_int_equal(stats.lines, 5);
  assert_int_equal(stats.digits, 9);
} /* replace_all_valid */
