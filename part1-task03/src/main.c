
/*****************************************************************************/
/* Name:   main.c                                                            */
/*                                                                           */
/* Purpose:  Get Fahrenheit temperature from user and convert it to Celsius  */
/*                                                                           */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "temperature.h"

int main(int argc, char **argv)
{
    double fahrenheit_temp;

    printf("Enter the temperature in Fahrenheit (degrees): ");
    scanf("%lf", &fahrenheit_temp);

    printf("Temperature converted from Fahrenheit to Celsius (degrees): %f\n", frh_to_cels(fahrenheit_temp));

    return 0;
} /* main */