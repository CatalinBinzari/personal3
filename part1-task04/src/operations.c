
/*****************************************************************************/
/* Name:   operations.c                                                      */
/*                                                                           */
/* Purpose:  Declared math operations to be executed on two numbers          */
/*                                                                           */
/*****************************************************************************/

#include "operations.h"
#include <math.h>

/*
  Name:        sum

  Purpose:     Sum of 2 numbers

  Params:      IN    first_num   - double
               IN    second_num  - double
               
  Returns:  a variable number
*/
double sum(double first_num, double second_num)
{
  return (first_num + second_num);
} /* sum */

/*
  Name:        difference

  Purpose:     Difference of 2 numbers

  Params:      IN    first_num   - double
               IN    second_num  - double

  Returns:  a variable number
*/
double difference(double first_num, double second_num)
{
  return (first_num - second_num);
} /* difference */

/*
  Name:        product

  Purpose:     Product of 2 numbers

  Params:      IN    first_num   - double
               IN    second_num  - double

  Returns:  a variable number
*/
double product(double first_num, double second_num)
{
  return (first_num * second_num);
} /* product */

/*
  Name:        division

  Purpose:     Division of 2 numbers

  Params:      IN    first_num   - double
               IN    second_num  - double

  Returns:  a variable number
*/
double division(double first_num, double second_num)
{
  return (first_num / second_num);
} /* division */

/*
  Name:        modulus

  Purpose:     Modulus of 2 numbers

  Params:      IN    first_num   - double
               IN    second_num  - double

  Returns:  a variable number
*/
double modulus(double first_num, double second_num)
{
  return (fmod(first_num, second_num));
} /* modulus */

/*
  Name:        average

  Purpose:     Average of 2 numbers

  Params:      IN    first_num   - double
               IN    second_num  - double

  Returns:  a variable number
*/
double average(double first_num, double second_num)
{
  return ((first_num + second_num) / 2);
} /* average */

/*
  Name:        minimum

  Purpose:     Minimum of 2 numbers

  Params:      IN    first_num   - double
               IN    second_num  - double

  Returns:  a variable number
*/
double minimum(double first_num, double second_num)
{
  return ((first_num > second_num) ? second_num : first_num);
} /* minimum */

/*
  Name:        maximum

  Purpose:     Maximum of 2 numbers

  Params:      IN    first_num   - double
               IN    second_num  - double

  Returns:  a variable number
*/
double maximum(double first_num, double second_num)
{
  return ((first_num > second_num) ? first_num : second_num);
} /* maximum */
