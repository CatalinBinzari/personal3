
/*
  Header:  car.h

  Purpose: Contains declaration from car.c file and structs/enum
*/

#ifndef CAR_H
#define CAR_H
#include <stdbool.h>

typedef enum
{
  INVALID = 0,
  LICENSE_PLATE,
  POWER,
  BRAND,
  MODEL,
  COLOR,
  YEAR
} field;

enum car_add_result
{
  ADD_INSUCCESS = -1,
  ADD_SUCCESS = 0,
  ARRAY_FULL = 1,
  PARAMS_INVALID = 2
};

typedef enum
{
  EXIT = -1,
  ADD_COMMAND,
  LIST_COMMAND,
  DELETE_COMMAND,
  HELP,
  TRY_AGAIN
} command;

typedef enum
{
  WHITE = 0,
  YELLOW,
  RED,
  BLUE,
  GREEN,
  BROWN,
  GREY,
  BLACK
} color;

typedef struct cars
{
  char license_plate[10];
  int power;
  char brand[20];
  char model[20];
  color color;
  int year;
} car;

typedef struct car_commands
{
  command id;
  char detail[100];
  field filter_field;
  char filter_value[21];
  field sort_field;
  bool sort_value;
} car_command;

typedef struct car_lists
{
  car *cars;
  unsigned int number_of_cars;
} car_list;

int parse_command(const char *user_input, car_command *command);
field get_field(const char *token);
int add_car(car_list *cars, car_command *list_command);

#endif /* CAR_H */
