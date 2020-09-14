
/*
  Name:        test_main.c

  Purpose:     Tests products management functions
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

void verify_valid_with_invalid_product_code(void **state);
void verify_valid_with_invalid_product_name(void **state);
void verify_valid_with_invalid_product_price(void **state);
void verify_product_code_exists_valid(void **state);
void verify_product_code_exists_does_not_exist(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(verify_valid_with_invalid_product_code),
      cmocka_unit_test(verify_valid_with_invalid_product_name),
      cmocka_unit_test(verify_valid_with_invalid_product_price),
      cmocka_unit_test(verify_product_code_exists_valid),
      cmocka_unit_test(verify_product_code_exists_does_not_exist),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        verify_valid_with_invalid_product_code

  Purpose:     Test function verify_valid with invalid product_code, with 6 chars

  Params:      IN    state
              
  Returns:     Nothing
*/
void verify_valid_with_invalid_product_code(void **state)
{
  product_data product;
  strcpy(product.product_code, "000000");
  strcpy(product.product_name, "detergent");
  product.price = 99.09;
  product.quantity = 456;

  int ret_code = verify_valid(product);

  assert_int_equal(ret_code, PARAMETERS_INVALID);
} /* verify_valid_with_invalid_product_code */

/*
  Name:        verify_valid_with_invalid_product_name

  Purpose:     Test function verify_valid with invalid product_name, with 0 chars

  Params:      IN    state
              
  Returns:     Nothing
*/
void verify_valid_with_invalid_product_name(void **state)
{
  product_data product;
  strcpy(product.product_code, "00001");
  strcpy(product.product_name, "");
  product.price = 99.09;
  product.quantity = 456;

  int ret_code = verify_valid(product);

  assert_int_equal(ret_code, PARAMETERS_INVALID);
} /* verify_valid_with_invalid_product_name */

/*
  Name:        verify_valid_with_invalid_product_price

  Purpose:     Test function verify_valid with invalid product_price, with minus value

  Params:      IN    state
              
  Returns:     Nothing
*/
void verify_valid_with_invalid_product_price(void **state)
{
  product_data product;
  strcpy(product.product_code, "00001");
  strcpy(product.product_name, "test");
  product.price = -99.09;
  product.quantity = 456;

  int ret_code = verify_valid(product);

  assert_int_equal(ret_code, PARAMETERS_INVALID);
} /* verify_valid_with_invalid_product_price */

/*
  Name:        verify_product_code_exists_valid

  Purpose:     Test function verify_product_code_exists with valid input file

  Params:      IN    state
              
  Returns:     Nothing
*/
void verify_product_code_exists_valid(void **state)
{
  FILE *f_ptr = fopen("/home/user/workspace/part3-task04/tests/product.dat", "r");
  int ret_code = verify_product_code_exists(f_ptr, "00001");
  assert_int_equal(ret_code, PRODUCT_CODE_ALREADY_IN_FILE);
} /* verify_product_code_exists_valid */

/*
  Name:        verify_product_code_exists_does_not_exist

  Purpose:     Test function verify_product_code_exists 
               with valid input file and inexistent code

  Params:      IN    state
              
  Returns:     Nothing
*/
void verify_product_code_exists_does_not_exist(void **state)
{
  FILE *f_ptr = fopen("/home/user/workspace/part3-task04/tests/product.dat", "r");
  int ret_code = verify_product_code_exists(f_ptr, "91101");
  assert_int_equal(ret_code, 0);
} /* verify_product_code_exists_does_not_exist */
