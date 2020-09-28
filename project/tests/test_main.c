
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

#include "../src/login.h"

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
