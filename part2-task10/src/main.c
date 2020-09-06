
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
  car_list list;
  list.number_of_cars = 0;
  list.car = (car *)malloc(0);

  car_list listed_cars;
  listed_cars.number_of_cars = 0;
  listed_cars.car = (car *)malloc(0);

  car_command command;
  int ret_code;
  char user_input[100];
  while (1)
  {
    printf("[car park]:");
    fgets(user_input, 100, stdin);

    ret_code = parse_command(user_input, &command);

    if (ret_code == 4)
    {
      printf("Invalid command. Type 'help' to display supported commands\n");
      continue;
    }
    switch (command.id)
    {
    case ADD_COMMAND:
      ret_code = add_car(&list, &command);
      if (ret_code != 0)
      {
        printf("Invalid command. Error code %d.\n", ret_code);
      } //TODO in dependenta de ret code sa printez un mesaj
      break;
    case LIST_COMMAND:
      printf("in list main\n");
      ret_code = list_car(&list, &command, &listed_cars);
      if (ret_code != 0)
      {
        printf("Invalid command. Error code %d.\n", ret_code);
      } //TODO in dependenta de ret code sa printez un mesaj
      break;

    default:
      break;
    }
  }
  free(list.car);
  free(listed_cars.car);
  return 0;
} /* main */
