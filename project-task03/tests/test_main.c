
/*
  Name:        test_main.c

  Purpose:     Tests _log function 
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
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
    
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        _log_valid

  Purpose:     Tests variadic function _log

  Params:      IN    state
              
  Returns:     Nothing
*/
