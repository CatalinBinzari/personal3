
/* 
  Name:      main.c                                                            

  Purpose:   Display a menu where the user select 
             one of the operations to perform on a list of cars
*/

#include <stdio.h>
#include <stdlib.h>
#include "car.h"
#include "commands.h"

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
    reset(&command);
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
      }
      break;
    case LIST_COMMAND:
      printf("in list main\n");
      ret_code = list_car(&list, &command, &listed_cars);
      if (ret_code != 0)
      {
        printf("Invalid command. Error code %d.\n", ret_code);
      }
      break;
    case DELETE_COMMAND:
      printf("in delete main\n");
      ret_code = delete_car(&list, &command);
      ret_code != 0 ? printf("Insuccess delete. Error code %d.\n", ret_code)
                    : printf("Success delete.\n");
      break;
    case HELP:
      display_help_support();
      break;
    case EXIT:
      printf("Exiting...\n");
      return 0;
      break;

    default:
      break;
    }
  }
  free(list.car);
  free(listed_cars.car);

  return 0;
} /* main */
