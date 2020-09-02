
/* 
  Name:      car.c 

  Purpose:   Contain operations and algorithms which user can select 
*/

#include <stdio.h>
#include <stdlib.h>
#include "car.h"
#include <string.h>
/*
  Name:        user_selection

  Purpose:     Display a user friendly selection menu 

  Params:      Nothing            

  Returns:     an integer, respresenting user choice
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
  Name:        new_car

  Purpose:     Create a struct with data

  Params:      Nothing            

  Returns:     struct
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
      (car_to_add.power < 0) ||
      (car_to_add.year > 2020))
  {
    core_error = PARAMS_INVALID;
    return core_error;
  }

  if (*number_of_cars >= max_size)
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
  Name:        comparePowerDesc

  Purpose:     Used to compare power from 2 cars structs

  Params:      IN pa = struct cars
               IN pb = struct cars

  Returns:     positive int, zero, negative int 
*/
int comparePowerDesc(const void *pa, const void *pb)
{
  const struct cars *p1 = pa;
  const struct cars *p2 = pb;

  return p2->power - p1->power;
} /* comparePowerDesc */

/*
  Name:        order_by_power

  Purpose:     Order input array by power and output result in another array

  Params:      IN  car  -  car array
               IN  n  -  number of cars in car array
               OUT cars_sorted  -  array os cars sorted by power    

  Returns:     Nothing
*/
void order_by_power(struct cars *car, int n, struct cars *cars_sorted)
{
  for (int i = 0; i <= n; i++)
  {
    cars_sorted[i] = car[i];
  }

  qsort(cars_sorted, n, sizeof(cars_sorted[0]), comparePowerDesc);
} /* order_by_power */

/*
  Name:        display

  Purpose:     Display car array

  Params:      IN  car  -  car array
               IN  n  -  number of cars in car array  

  Returns:     Nothing
*/
void display(struct cars *car, int n)
{
  for(int i = 0; i < n; ++i)
  {
    printf("Seats: \t%d\n",car[i].number_of_seats);
    printf("Power: \t%d\n",car[i].power);
    printf("Brand: \t%s\n",car[i].brand);
    printf("Color: \t%s\n",car[i].color);
    printf("Year: \t%d\n",car[i].year);
  }
} /* display */

/*
  Name:        filter_by_year

  Purpose:     Filter the array by a given year

  Params:      IN  car  -  the car array
               IN  input_car_num  -  the number of cars
               OUT output_array - the cars after filtering
               OUT output_car_num - cars number after filtering
               IN year - given year

  Returns:     Nothing
*/
void filter_by_year(struct cars *car, int input_car_num, struct cars *output_array, int *output_car_num, int given_year)
{
  *output_car_num = 0;
  for(int i = 0; i < input_car_num; ++i)
  {
    if(car[i].year == given_year)
    {
      output_array[(*output_car_num)++] = car[i];
    }
  }
} /* filter_by_year */
