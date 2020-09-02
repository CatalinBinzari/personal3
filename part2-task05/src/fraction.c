
/* 
  Name:      fraction.c 

  Purpose:   Contains functions to read, output and add 2 fraction structures    
*/

#include <stdio.h>
#include "fraction.h"

/*
  Name:        add

  Purpose:     Calculate the sum of two fractions

  Params:      IN frac1 - struct fraction frac1
               IN frac2 - struct fraction frac2

  Returns:     struct fraction, or 0/0 if denominator is 0
*/
struct fraction add(struct fraction frac1, struct fraction frac2)
{
  int gcd_res;
  struct fraction res;
  int sign;
  
  res.numerator = (frac1.numerator * frac2.denominator) + (frac1.denominator * frac2.numerator);
  res.denominator = frac1.denominator * frac2.denominator;

  format(&res);

  if(res.denominator == 0)
  {
    res.numerator = 0;
    return res;
  }

  sign = get_sign(res);

  res.numerator *= sign;

  gcd_res = gcd(res.numerator, res.denominator);

  res.numerator /= gcd_res;
  res.denominator /= gcd_res;

  res.numerator *= sign;

  return res;
} /* add */

/*
  Name:        gcd

  Purpose:     GCD using modulo operator in Euclidean algorithm

  Params:      IN numerator
               IN denominator

  Returns:     GCD
*/
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} /* gcd */

/*
  Name:        get_sign

  Purpose:     Return sign of the fraction

  Params:      IN frac - struct fraction frac

  Returns:     return -1 if sign is negative, else 1
*/
int get_sign(struct fraction frac)
{
  int sign = 1;

  if (!((frac.numerator < 0) && (frac.denominator < 0)) &&
      ((frac.numerator < 0) || (frac.denominator < 0)))
  {
    sign = -1;
  }

  return sign;
} /* get_sign */

/*
  Name:        format

  Purpose:     Dhange fraction to format: (+-numerator / denominator)

  Params:      OUT frac - struct fraction

  Returns:     Nothing
*/
void format(struct fraction *frac)
{
  if (((frac->numerator < 0) && (frac->denominator < 0)) ||
      (frac->denominator < 0))
  {
    frac->numerator *= -1;
    frac->denominator *= -1;
  }
} /* format */

/*
  Name:        format

  Purpose:     Display fraction

  Params:      IN frac - struct fraction

  Returns:     Nothing
*/
void display(struct fraction frac)
{
  printf("Fraction: (%d / %d)\n", frac.numerator, frac.denominator);
} /* display */
