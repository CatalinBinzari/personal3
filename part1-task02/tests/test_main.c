/*
  Name:        test_main.c

  Purpose:     This file contains tests for triangle validation 

*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/triangle.h"

void test_triangle_angles_sum_180(void **state);
void test_triangle_angles_sum_lt_180(void **state);
void test_triangle_angles_sum_gt_180(void **state);
void test_triangle_angles_zero_angle(void **state);
void test_triangle_angles_negative_angle(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{

  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_triangle_angles_sum_180),
      cmocka_unit_test(test_triangle_angles_sum_lt_180),
      cmocka_unit_test(test_triangle_angles_sum_gt_180),
      cmocka_unit_test(test_triangle_angles_zero_angle),
      cmocka_unit_test(test_triangle_angles_negative_angle),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        test_triangle_angles_sum_180

  Purpose:     Validate that a triangle with angles: 60,45,75 exist
    
  Params:      IN    state
              
  Returns:     Nothing
*/
void test_triangle_angles_sum_180(void **state)
{
  int result = triangle_angles(60, 45, 75);

  assert_int_equal(result, 1);
} /* test_triangle_angles_sum_180 */

/*
  Name:        test_triangle_angles_sum_lt_180

  Purpose:     Validate that a triangle with angles: 45, 45, 80 does not exist
    
  Params:      IN    state
              
  Returns:     Nothing
*/
void test_triangle_angles_sum_lt_180(void **state)
{
  int result = triangle_angles(45, 45, 80);

  assert_int_equal(result, 0);
} /* test_triangle_angles_sum_lt_180 */

/*
  Name:        test_triangle_angles_sum_gt_180

  Purpose:     Validate that a triangle with angles: 60, 90, 80 does not exist
    
  Params:      IN    state
              
  Returns:     Nothing
*/
void test_triangle_angles_sum_gt_180(void **state)
{
  int result = triangle_angles(60, 90, 80);

  assert_int_equal(result, 0);
} /* test_triangle_angles_sum_gt_180 */

/*
  Name:        test_triangle_angles_zero_angle

  Purpose:     Validate that a triangle with angles: 120, 60, 0 does not exist
  
  Params:      IN    state
              
  Returns:     Nothing
*/
void test_triangle_angles_zero_angle(void **state)
{
  int result = triangle_angles(120, 60, 0);

  assert_int_equal(result, 0);
} /* test_triangle_angles_zero_angle */

/*
  Name:        test_triangle_angles_negative_angle

  Purpose:     Validate that a triangle with angles: 90, 120, -30 does not exist

  Params:      IN    state
              
  Returns:     Nothing
*/
void test_triangle_angles_negative_angle(void **state)
{
  int result = triangle_angles(90, 120, -30);

  assert_int_equal(result, 0);
} /* test_triangle_angles_negative_angle */
