
#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

void test_dummy(void **state);

/*****************************************************************************/
/* Test Main Function                                                        */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_dummy),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

void test_dummy(void **state)
{
  assert_int_equal(0, 0);
}
