
/* 
  Name:      car.c 

  Purpose:   TODO
*/

#include <stdio.h>
#include <stdlib.h>
#include "car.h"
#include <string.h>
/*
  Name:        user_selection

  Purpose:     TODO

  Params:      Nothing            

  Returns:     an integer, TODO
*/
int user_selection()
{
  int selection;
  printf("Select the operation:\n"
         "[1] Add new car\n"
         "[2] Display cars ordered by power\n"
         "[3] Display cars from year (year read from keyboard)\n"
         "[4] Exit\n");
  scanf("%d", &selection);
  if (selection < 1 || selection > 4)
  {
    return -1;
  }
  return selection;
} /* user_selection */

/*
  Name:        add_new_car

  Purpose:     TODO

  Params:      Nothing            

  Returns:     an integer, TODO
*/
struct cars new_car()
{
  struct cars car;

  printf("Enter car details\n"
         "Number of seats(>=2 && <=8): ");
  scanf("%d", &car.number_of_seats);
  printf("\nPower: ");
  scanf("%d", &car.power);
  printf("\nBrand: ");
  scanf("%s", car.brand);
  printf("\nColor: ");
  scanf("%s", car.color);
  printf("\nYear of manufacture: ");
  scanf("%d", &car.year);

  return car;
} /* new_car */

/*
  Name:        add_cars

  Purpose:     Insert car to car_array and checks possible errors

  Params:      car  -  car array
               number_of_cars  -  number of chars in char array
               car_to_add  -  car to append to char array      

  Returns:     0, if car is added successfuly, 1 if car array is full, params are invalid
*/
int add_cars(struct cars *car, int *number_of_cars, struct cars car_to_add, int max_size)
{ 
  int core_error = ADD_INSUCCESS;
  if (((car_to_add.number_of_seats < 2) || (car_to_add.number_of_seats > 8)) ||
      (car_to_add.power < 0 )||
      (car_to_add.year > 2020))
  {
    core_error = PARAMS_INVALID;
    return core_error;
  }

  if(*number_of_cars >= max_size)
  {
    core_error = ARRAY_FULL;
    return core_error;
  }

  car[*number_of_cars] = car_to_add;
  ++*number_of_cars;
  core_error = ADD_SUCCESS;
  
  return core_error;
} /* add_cars */

/*
  Name:        order_by_power

  Purpose:     Order input array by power and output result in another array

  Params:      IN  car  -  car array
               IN  n  -  number of chars in char array
               OUT cars_sorted  -  array os cars sorted by power    

  Returns:     Nothing
*/
void order_by_power(struct cars *car, int n, struct cars *cars_sorted)
{
  int i, j;
  struct cars temp;
  memcpy(&cars_sorted, &car, n);

  // printf("\n\n%d: %d\n",car[2].power, cars_sorted[2].power);
  // printf("\n\n%d: %d\n",car[4].power, cars_sorted[4].power);
  // printf("\n\n%d: %d\n",car[1].power, cars_sorted[1].power);

  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < (n - 1 - i); j++)
    {
      if (cars_sorted[j].power < cars_sorted[j + 1].power)
      {
        temp = cars_sorted[j];
        cars_sorted[j] = cars_sorted[j + 1];
        cars_sorted[j + 1] = temp;
      }
    }
  }

} /* order_by_power */

