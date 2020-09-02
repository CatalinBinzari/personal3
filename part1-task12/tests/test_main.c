
/*
  Name:        test_main.c

  Purpose:     This file contains tests for fee charge that user should pay 
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/number.h"
void pay_charge_valid_25(void **state);
void pay_charge_valid_50(void **state);
void pay_charge_valid_51(void **state);
void pay_charge_valid_199(void **state);
void pay_charge_valid_200(void **state);
void pay_charge_valid_400(void **state);
void pay_charge_valid_500(void **state);
void test_charge_value_41_min(void **state);
void test_charge_value_50_min(void **state);
void test_charge_value_76_min(void **state);
void test_charge_value_199_min(void **state);
void test_charge_value_282_min(void **state);
void test_charge_value_399_min(void **state);
void test_charge_value_420_min(void **state);
void test_charge_value_499_min(void **state);
void test_charge_value_500_min(void **state);
void test_charge_value_510_min(void **state);
void test_charge_value_negative_value(void **state);


/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(pay_charge_valid_25),
      cmocka_unit_test(pay_charge_valid_50),
      cmocka_unit_test(pay_charge_valid_51),
      cmocka_unit_test(pay_charge_valid_199),
      cmocka_unit_test(pay_charge_valid_400),
      cmocka_unit_test(pay_charge_valid_500),
      cmocka_unit_test(test_charge_value_41_min),
      cmocka_unit_test(test_charge_value_50_min),
      cmocka_unit_test(test_charge_value_76_min),
      cmocka_unit_test(test_charge_value_199_min),
      cmocka_unit_test(test_charge_value_282_min),
      cmocka_unit_test(test_charge_value_399_min),
      cmocka_unit_test(test_charge_value_420_min),
      cmocka_unit_test(test_charge_value_499_min),
      cmocka_unit_test(test_charge_value_500_min),
      cmocka_unit_test(test_charge_value_510_min),
      cmocka_unit_test(test_charge_value_negative_value),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        pay_charge_valid_25

  Purpose:     Test that pay_charge gives corect return with IN = 25

  Params:      IN    state

  Returns:     Nothing
*/
void pay_charge_valid_25(void **state)
{
  int pay_fee = pay_charge(25);

  assert_int_equal(pay_fee, 0);
} /* pay_charge_valid_25 */

/*
  Name:        pay_charge_valid_50

  Purpose:     Test that pay_charge gives corect return with IN = 50

  Params:      IN    state

  Returns:     Nothing
*/
void pay_charge_valid_50(void **state)
{
  int pay_fee = pay_charge(50);

  assert_int_equal(pay_fee, 0);
} /* pay_charge_valid_50 */

/*
  Name:        pay_charge_valid_51

  Purpose:     Test that pay_charge gives corect return with IN = 51

  Params:      IN    state

  Returns:     Nothing
*/
void pay_charge_valid_51(void **state)
{
  int pay_fee = pay_charge(51);

  assert_int_equal(pay_fee, 20);
} /* pay_charge_valid_51 */

/*
  Name:        pay_charge_valid_199

  Purpose:     Test that pay_charge gives corect return with IN = 199

  Params:      IN    state

  Returns:     Nothing
*/
void pay_charge_valid_199(void **state)
{
  int pay_fee = pay_charge(199);

  assert_int_equal(pay_fee, 2980);
} /* pay_charge_valid_199 */

/*
  Name:        pay_charge_valid_400

  Purpose:     Test that pay_charge gives corect return with IN = 400

  Params:      IN    state

  Returns:     Nothing
*/
void pay_charge_valid_400(void **state)
{
  int pay_fee = pay_charge(400);

  assert_int_equal(pay_fee, 5990);
} /* pay_charge_valid_400 */

/*
  Name:        pay_charge_valid_500

  Purpose:     Test that pay_charge gives corect return with IN = 500

  Params:      IN    state

  Returns:     Nothing
*/
void pay_charge_valid_500(void **state)
{
  int pay_fee = pay_charge(500);

  assert_int_equal(pay_fee, 6985);
} /* pay_charge_valid_500 */

/*
  Name:        test_charge_value_41_min

  Purpose:     Test that pay_charge gives corect return with IN = 41

  Params:      IN    state

  Returns:     Nothing
*/
void test_charge_value_41_min(void **state)
{
  int pay_fee = pay_charge(41);

  assert_int_equal(pay_fee, 0);
} /* test_charge_value_41_min */

/*
  Name:        test_charge_value_50_min

  Purpose:     Test that pay_charge gives corect return with IN = 50

  Params:      IN    state

  Returns:     Nothing
*/
void test_charge_value_50_min(void **state)
{
  int pay_fee = pay_charge(50);

  assert_int_equal(pay_fee, 0);
} /* test_charge_value_41_min */

/*
  Name:        test_charge_value_76_min

  Purpose:     Test that pay_charge gives corect return with IN = 76

  Params:      IN    state

  Returns:     Nothing
*/
void test_charge_value_76_min(void **state)
{
  int pay_fee = pay_charge(76);

  assert_int_equal(pay_fee, 520);
} /* test_charge_value_76_min */

/*
  Name:        test_charge_value_199_min

  Purpose:     Test that pay_charge gives corect return with IN = 199

  Params:      IN    state

  Returns:     Nothing
*/
void test_charge_value_199_min(void **state)
{
  int pay_fee = pay_charge(199);

  assert_int_equal(pay_fee, 2980);
} /* test_charge_value_199_min */

/*
  Name:        test_charge_value_282_min

  Purpose:     Test that pay_charge gives corect return with IN = 282

  Params:      IN    state

  Returns:     Nothing
*/
void test_charge_value_282_min(void **state)
{
  int pay_fee = pay_charge(282);

  assert_int_equal(pay_fee, 4225);
} /* test_charge_value_282_min */

/*
  Name:        test_charge_value_399_min

  Purpose:     Test that pay_charge gives corect return with IN = 399

  Params:      IN    state

  Returns:     Nothing
*/
void test_charge_value_399_min(void **state)
{
  int pay_fee = pay_charge(399);

  assert_int_equal(pay_fee, 5980);
} /* test_charge_value_399_min */

/*
  Name:        test_charge_value_420_min

  Purpose:     Test that pay_charge gives corect return with IN = 420

  Params:      IN    state

  Returns:     Nothing
*/
void test_charge_value_420_min(void **state)
{
  int pay_fee = pay_charge(420);

  assert_int_equal(pay_fee, 6190);
} /* test_charge_value_420_min */

/*
  Name:        test_charge_value_499_min

  Purpose:     Test that pay_charge gives corect return with IN = 499

  Params:      IN    state

  Returns:     Nothing
*/
void test_charge_value_499_min(void **state)
{
  int pay_fee = pay_charge(499);

  assert_int_equal(pay_fee, 6980);
} /* test_charge_value_499_min */

/*
  Name:        test_charge_value_500_min

  Purpose:     Test that pay_charge gives corect return with IN = 500

  Params:      IN    state

  Returns:     Nothing
*/
void test_charge_value_500_min(void **state)
{
  int pay_fee = pay_charge(500);

  assert_int_equal(pay_fee, 6985);
} /* test_charge_value_500_min */

/*
  Name:        test_charge_value_510_min

  Purpose:     Test that pay_charge gives corect return with IN = 510

  Params:      IN    state

  Returns:     Nothing
*/
void test_charge_value_510_min(void **state)
{
  int pay_fee = pay_charge(510);

  assert_int_equal(pay_fee, 7035);
} /* test_charge_value_510_min */

/*
  Name:        test_charge_value_negative_value

  Purpose:     Test that pay_charge gives corect return with IN = -1

  Params:      IN    state

  Returns:     Nothing
*/
void test_charge_value_negative_value(void **state)
{
  int pay_fee = pay_charge(-1);

  assert_int_equal(pay_fee, -1);
} /* test_charge_value_negative_value */
