
/*****************************************************************************/
/* Name:   temperature.c                                                     */
/*                                                                           */
/* Purpose: Convert temperature from Fahrenheit to Celsius                   */
/*                                                                           */
/*****************************************************************************/

#include "temperature.h"


/*
  Name:        fahrenheit_to_celsius

  Purpose:     Convert fahrenheit to celsius

  Params:      IN    fahrenheit_temp - fahrenheit temperature in degrees 

  Returns:   a variable value
*/
double fahrenheit_to_celsius(double fahrenheit_temp)
{
    return frh_to_cels(fahrenheit_temp);
} /* fahrenheit_to_celsius */