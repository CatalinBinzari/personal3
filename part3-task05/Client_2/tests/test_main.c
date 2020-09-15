
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

#include "../src/client.h"

// void replace_all_valid(void **state);
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      //cmocka_unit_test(replace_all_valid),

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        replace_all_valid

  Purpose:     Test function replace_all for valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
// void replace_all_valid(void **state)
// {
//   char buffer[] = "lll ppp ttt lll pp";
//   char old_word[] = "lll";
//   char new_word[] = "mmm";
//   int counter = 0;
//   replace_all(buffer, old_word, new_word, &counter);

//   assert_int_equal(counter, 2);
//   assert_string_equal(buffer, "mmm ppp ttt mmm pp");
// } /* replace_all_valid */
