
/* 
  Name:      main.c                                                            

  Purpose:   String manipulation using pointer arithmetics.
*/

#include <stdio.h>
#include <stdlib.h>
#include "car.h"
#define CAR_ELEMENTS 100


int main(int argc, char **argv)
{
  struct cars car[CAR_ELEMENTS];
  struct cars cars_sorted[CAR_ELEMENTS];
  struct cars car_to_add;
  int number_of_cars;

  int selection = -1;

  selection = user_selection();
  printf("all good. %d\n",selection);

  switch (selection)
  {
  case 1:
    car_to_add = new_car();
    int tmp = add_cars(car, &number_of_cars, car_to_add, CAR_ELEMENTS);
    printf("tmp: %d", tmp);
    break;
  case 2:
    order_by_power(car, number_of_cars, cars_sorted);
    printf("tmp: %d", cars_sorted[0].year);
    break;
  
  default:
    break;
  }

  return 0;
} /* main */
