
/*
  Header:  temperature.h

  Purpose: contains function declarations from temperature.c file
*/

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#define TRUE 1
#define FALSE 0
#define frh_to_cels(f) (f - 32) * 5 / 9

double fahrenheit_to_celsius(double fahrenheit_temp);

#endif //TEMPERATURE_H
