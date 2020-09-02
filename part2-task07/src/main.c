
/* 
  Name:      main.c                                                            

  Purpose:   Display a menu where the user select one of the operations
*/

#include <stdio.h>
#include <stdlib.h>
#include "car.h"
#define CAR_ELEMENTS 100

int main(int argc, char **argv)
{
  struct cars car[CAR_ELEMENTS];
  struct cars cars_sorted[CAR_ELEMENTS];
  struct cars cars_filtered[CAR_ELEMENTS];
  struct cars car_to_add;
  int number_of_cars;
  int cars_counter; 
  int car_filtered_number = 0;
  int given_year;
  int selection = -1;

  
  while (selection != 4)
  {
    selection = user_selection();
    printf("Selection is: %d\n", selection);

    switch (selection)
    {
    case 1:
      printf("Insert number of cars: ");
      scanf("%d", &number_of_cars);
      while (cars_counter < (cars_counter + number_of_cars))
      {
        car_to_add = new_car();
        int tmp = add_cars(car, &cars_counter, car_to_add, CAR_ELEMENTS);
        printf("Return code: %d\n", tmp);
      }
      break;
    case 2:
      order_by_power(car, cars_counter, cars_sorted);
      display(cars_sorted, cars_counter);
      printf("Display finished with %d elements\n", cars_counter);
      break;
    case 3:
      printf("Enter the year: ");
      scanf("%d", &given_year);
      filter_by_year(car, cars_counter, cars_filtered, &car_filtered_number, given_year);
      display(cars_filtered, car_filtered_number);
      printf("Display finished with %d elements\n", car_filtered_number);
      break;

    default:
      printf("Exiting...\n");
      break;
    }
  }

  return 0;
} /* main */
