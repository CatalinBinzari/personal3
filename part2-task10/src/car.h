
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
  ADD_SUCCESS,
  ARRAY_FULL,
  PARAMS_INVALID,
  ALREADY_IN_LIST
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
  BLACK,
  UNKNOWN
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
  bool sort_ascending;
} car_command;

typedef struct car_lists
{
  car *car;
  unsigned int number_of_cars;
} car_list;

int parse_command(const char *user_input, car_command *command);
field get_field(const char *token);
int add_car(car_list *cars, car_command *list_command);
color get_color(const char *token);
int list_car(car_list *cars, car_command *list_command, car_list *listed_cars);
void copy_car(car_list *cars, car_list *listed_cars, int i);
void filter(car_list *cars, car_command *list_command, car_list *listed_cars);
void sort(car_list *listed_cars, car_command *list_command);
int compareLicensePlateAsc(const void *pa, const void *pb);
int compareLicensePlateDesc(const void *pa, const void *pb);
int comparePowerAsc(const void *pa, const void *pb);
int comparePowerDesc(const void *pa, const void *pb);
int compareBrandAsc(const void *pa, const void *pb);
int compareBrandDesc(const void *pa, const void *pb);
int compareModelAsc(const void *pa, const void *pb);
int compareModelDesc(const void *pa, const void *pb);
int compareColorAsc(const void *pa, const void *pb);
int compareColorDesc(const void *pa, const void *pb);
int compareYearAsc(const void *pa, const void *pb);
int compareYearDesc(const void *pa, const void *pb);
int delete_car(car_list *cars, car_command *add_command);
void delete_by_power(car_list *list, car_command *list_command, int *i);
void delete_by_license_plate(car_list *list, car_command *list_command, int *i);
void delete_by_brand(car_list *list, car_command *list_command, int *i);
void delete_by_color(car_list *list, car_command *list_command, int *i);
void delete_by_year(car_list *list, car_command *list_command, int *i);
void delete_by_model(car_list *list, car_command *list_command, int *i);

#endif /* CAR_H */
