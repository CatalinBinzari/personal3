
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
  car_list *cars = (car_list *) malloc(sizeof(car_list));
  //car_list *listed_cars = (car_list *) malloc(sizeof(car_list));
  char user_input[100];
  car_command command;
  int ret_code;

  while (1)
  {
    printf("[car park]:");
    fgets(user_input, 100, stdin);

    int i = parse_command(user_input, &command);
    printf("%d\n", i);
    switch (command.id)
    {
    case ADD_COMMAND:
      ret_code = add_car(cars, &command);
      printf("%d\n", ret_code);
      break;
    
    default:
      break;
    }


  }
  free(cars);
  return 0;
} /* main */
