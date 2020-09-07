
/* 
  Name:      car.c 

  Purpose:   Contain operations and algorithms in fuction which user can call 
*/

#include <stdio.h>
#include <stdlib.h>
#include "car.h"
#include <string.h>
#include <stddef.h>

/*
  Name:        add_car

  Purpose:     Add the car info from input formated input
               to car array 

  Params:      OUT list - car list 
               IN  list_command - user input in a struct
 
  Returns:     return code from car_add_result struct
*/
int add_car(car_list *list, car_command *list_command)
{
  car new_car;
  char delimiters[] = "|";
  char *running = strdup(list_command->detail);
  char *token;

  list->number_of_cars++;
  token = strsep(&running, delimiters);

  token = strsep(&running, delimiters);
  strcpy(new_car.license_plate, token);

  token = strsep(&running, delimiters);
  sscanf(token, "%d", &new_car.power);

  token = strsep(&running, delimiters);
  strcpy(new_car.brand, token);

  token = strsep(&running, delimiters);
  strcpy(new_car.model, token);

  token = strsep(&running, delimiters);
  new_car.color = get_color(token);

  token = strsep(&running, delimiters);
  sscanf(token, "%d", &new_car.year);

  for (int i = 0; i < list->number_of_cars; ++i)
  {
    if (strcmp(new_car.license_plate, list->car[i].license_plate) == 0)
    {
      return ALREADY_IN_LIST;
    }
  }

  if ((new_car.power > 5000) ||
      (new_car.power < 1) ||
      (new_car.year > 2020))
  {
    return PARAMS_INVALID;
  }

  list->car = (car *)realloc(list->car, (sizeof(car) * list->number_of_cars));
  memcpy(&list->car[list->number_of_cars - 1], &new_car, sizeof(car));

  return ADD_SUCCESS;
} /* add_car */

/*
  Name:        get_color

  Purpose:     compare token and return color id of that token

  Params:      IN token - string         

  Returns:     field
*/
color get_color(const char *token)
{
  if (strcmp(token, "white") == 0)
  {
    return WHITE;
  }
  else if (strcmp(token, "yellow") == 0)
  {
    return YELLOW;
  }
  else if (strcmp(token, "red") == 0)
  {
    return RED;
  }
  else if (strcmp(token, "blue") == 0)
  {
    return BLUE;
  }
  else if (strcmp(token, "green") == 0)
  {
    return GREEN;
  }
  else if (strcmp(token, "brown") == 0)
  {
    return BROWN;
  }
  else if (strcmp(token, "grey") == 0)
  {
    return GREY;
  }
  else if (strcmp(token, "black") == 0)
  {
    return BLACK;
  }
  else
  {
    return UNKNOWN;
  }
} /* get_color */

/*
  Name:        list_car

  Purpose:     function that list cars deppending of the parameters this function recieves

  Params:      IN token - string         

  Returns:     0 if was filtered, or -1
*/
int list_car(car_list *cars, car_command *list_command, car_list *listed_cars)
{
  listed_cars->number_of_cars = 0;
  int ret_code;

  if ((list_command->filter_field > 0) &&
      (list_command->filter_field < 7))
  {
    ret_code = filter(cars, list_command, listed_cars);
  }
  if ((list_command->sort_field > 0) &&
      (list_command->sort_field < 7))
  {
    ret_code == 0 ? sort(listed_cars, list_command) : sort(cars, list_command);
  }
  ret_code == 0 ? display(listed_cars) : display(cars);

  return 0;
} /* list_car */

/*
  Name:        copy_car

  Purpose:     realloc memory and copy car from one pointer to struct to another pointer to struct

  Params:      IN cars - copy car struct from here
               OUT listed_cars - copy car struct to there  
               IN i - struct pointer index  

  Returns:     Nothing
*/
void copy_car(car_list *cars, car_list *listed_cars, int i)
{
  listed_cars->number_of_cars++;
  listed_cars->car = (car *)realloc(listed_cars->car, (sizeof(car) * listed_cars->number_of_cars));
  memcpy(&listed_cars->car[listed_cars->number_of_cars - 1], &cars->car[i], sizeof(car));
} /* copy_car */

/*
  Name:        filter

  Purpose:     filters input struct pointer to another output struct pointer

  Params:      IN cars - copy car struct from here
               OUT listed_cars - copy car struct to there  
               IN listed_Cars - filtered car struct from here

  Returns:     0 if was filtered, else -1
*/
int filter(car_list *cars, car_command *list_command, car_list *listed_cars)
{
  int ret_code = -1;
  switch (list_command->filter_field)
  {
  case 1:
    for (int i = 0; i < cars->number_of_cars; ++i)
    {
      if (strcmp(cars->car[i].license_plate, list_command->filter_value) == 0)
      {
        copy_car(cars, listed_cars, i);
        ret_code = 0;
      }
    }
    break;
  case 2:
    for (int i = 0; i < cars->number_of_cars; ++i)
    {
      if (cars->car[i].power == atoi(list_command->filter_value))
      {
        copy_car(cars, listed_cars, i);
        ret_code = 0;
      }
    }
    break;
  case 3:
    for (int i = 0; i < cars->number_of_cars; ++i)
    {
      if (strcmp(cars->car[i].brand, list_command->filter_value) == 0)
      {
        copy_car(cars, listed_cars, i);
        ret_code = 0;
      }
    }
    break;
  case 4:
    for (int i = 0; i < cars->number_of_cars; ++i)
    {
      if (strcmp(cars->car[i].model, list_command->filter_value) == 0)
      {
        copy_car(cars, listed_cars, i);
        ret_code = 0;
      }
    }
  case 5:
    for (int i = 0; i < cars->number_of_cars; ++i)
    {
      if (cars->car[i].color == atoi(list_command->filter_value))
      {
        copy_car(cars, listed_cars, i);
        ret_code = 0;
      }
    }
  case 6:
    for (int i = 0; i < cars->number_of_cars; ++i)
    {
      if (cars->car[i].year == atoi(list_command->filter_value))
      {
        copy_car(cars, listed_cars, i);
        ret_code = 0;
      }
    }
    break;
  default:
    break;
  }

  return ret_code;
} /* filter */

/*
  Name:        sort

  Purpose:     sort ascending or descending the input struct pointer

  Params:      IN/OUT listed_cars - car struct 
               IN list_command - command struct

  Returns:     Nothing
*/
void sort(car_list *listed_cars, car_command *list_command)
{
  switch (list_command->sort_field)
  {
  case 1:
    list_command->sort_ascending
        ? qsort(listed_cars->car, listed_cars->number_of_cars, sizeof(car), compareLicensePlateAsc)
        : qsort(listed_cars->car, listed_cars->number_of_cars, sizeof(car), compareLicensePlateDesc);
    break;
  case 2:
    list_command->sort_ascending
        ? qsort(listed_cars->car, listed_cars->number_of_cars, sizeof(car), comparePowerAsc)
        : qsort(listed_cars->car, listed_cars->number_of_cars, sizeof(car), comparePowerDesc);
    break;
  case 3:
    list_command->sort_ascending
        ? qsort(listed_cars->car, listed_cars->number_of_cars, sizeof(car), compareBrandAsc)
        : qsort(listed_cars->car, listed_cars->number_of_cars, sizeof(car), compareBrandDesc);
    break;
  case 4:
    list_command->sort_ascending
        ? qsort(listed_cars->car, listed_cars->number_of_cars, sizeof(car), compareModelAsc)
        : qsort(listed_cars->car, listed_cars->number_of_cars, sizeof(car), compareModelDesc);
    break;
  case 5:
    list_command->sort_ascending
        ? qsort(listed_cars->car, listed_cars->number_of_cars, sizeof(car), compareColorAsc)
        : qsort(listed_cars->car, listed_cars->number_of_cars, sizeof(car), compareColorDesc);
    break;
  case 6:
    list_command->sort_ascending
        ? qsort(listed_cars->car, listed_cars->number_of_cars, sizeof(car), compareYearAsc)
        : qsort(listed_cars->car, listed_cars->number_of_cars, sizeof(car), compareYearDesc);
    break;
  default:
    break;
  }
} /* sort */

/*
  Name:        compareLicensePlateAsc

  Purpose:     sort ascending by license player

  Params:      IN pa - car struct
               IN pb - car struct

  Returns:     integer
*/
int compareLicensePlateAsc(const void *pa, const void *pb)
{
  const car *p1 = pa;
  const car *p2 = pb;

  return strcmp(p1->license_plate, p2->license_plate);
} /* compareLicensePlateAsc */

/*
  Name:        compareLicensePlateDesc

  Purpose:     sort descending by license player

  Params:      IN pa - car struct
               IN pb - car struct

  Returns:     integer
*/
int compareLicensePlateDesc(const void *pa, const void *pb)
{
  const car *p1 = pa;
  const car *p2 = pb;

  return strcmp(p2->license_plate, p1->license_plate);
} /* compareLicensePlateDesc */

/*
  Name:        comparePowerAsc

  Purpose:     sort asscending by power

  Params:      IN pa - car struct
               IN pb - car struct

  Returns:     integer
*/
int comparePowerAsc(const void *pa, const void *pb)
{
  const car *p1 = pa;
  const car *p2 = pb;

  return p1->power - p2->power;
} /* comparePowerAsc */

/*
  Name:        comparePowerDesc

  Purpose:     sort descending by power

  Params:      IN pa - car struct
               IN pb - car struct

  Returns:     integer
*/
int comparePowerDesc(const void *pa, const void *pb)
{
  const car *p1 = pa;
  const car *p2 = pb;

  return p2->power - p1->power;
} /* comparePowerDesc */

/*
  Name:        compareBrandAsc

  Purpose:     sort ascending by brand

  Params:      IN pa - car struct
               IN pb - car struct

  Returns:     integer
*/
int compareBrandAsc(const void *pa, const void *pb)
{
  const car *p1 = pa;
  const car *p2 = pb;

  return strcmp(p1->brand, p2->brand);
} /* compareBrandAsc */

/*
  Name:        compareBrandDesc

  Purpose:     sort descending by brand

  Params:      IN pa - car struct
               IN pb - car struct

  Returns:     integer
*/
int compareBrandDesc(const void *pa, const void *pb)
{
  const car *p1 = pa;
  const car *p2 = pb;

  return strcmp(p2->brand, p1->brand);
} /* compareBrandDesc */

/*
  Name:        compareModelAsc

  Purpose:     sort ascending by model

  Params:      IN pa - car struct
               IN pb - car struct

  Returns:     integer
*/
int compareModelAsc(const void *pa, const void *pb)
{
  const car *p1 = pa;
  const car *p2 = pb;

  return strcmp(p1->model, p2->model);
} /* compareModelAsc */

/*
  Name:        compareModelDesc

  Purpose:     sort descending by model

  Params:      IN pa - car struct
               IN pb - car struct

  Returns:     integer
*/
int compareModelDesc(const void *pa, const void *pb)
{
  const car *p1 = pa;
  const car *p2 = pb;

  return strcmp(p2->model, p1->model);
} /* compareModelDesc */

/*
  Name:        compareColorAsc

  Purpose:     sort ascending by color

  Params:      IN pa - car struct
               IN pb - car struct

  Returns:     integer
*/
int compareColorAsc(const void *pa, const void *pb)
{
  const car *p1 = pa;
  const car *p2 = pb;

  return p1->color - p2->color;
} /* compareColorAsc */

/*
  Name:        compareColorDesc

  Purpose:     sort descending by color

  Params:      IN pa - car struct
               IN pb - car struct

  Returns:     integer
*/
int compareColorDesc(const void *pa, const void *pb)
{
  const car *p1 = pa;
  const car *p2 = pb;

  return p2->color - p1->color;
} /* compareColorDesc */

/*
  Name:        compareYearAsc

  Purpose:     sort ascending by year

  Params:      IN pa - car struct
               IN pb - car struct

  Returns:     integer
*/
int compareYearAsc(const void *pa, const void *pb)
{
  const car *p1 = pa;
  const car *p2 = pb;

  return p1->year - p2->year;
} /* compareYearAsc */

/*
  Name:        compareYearDesc

  Purpose:     sort descending by year

  Params:      IN pa - car struct
               IN pb - car struct

  Returns:     integer
*/
int compareYearDesc(const void *pa, const void *pb)
{
  const car *p1 = pa;
  const car *p2 = pb;

  return p2->year - p1->year;
} /* compareYearDesc */

/*
  Name:        delete_car

  Purpose:     delete all items that match on filter field

  Params:      IN/OUT list - car struct from here 
               IN list_command -  command struct

  Returns:     -1, if nothing is deleted, else 0
*/
int delete_car(car_list *list, car_command *list_command)
{
  int ret_code = DELETE_INSUCCESS;
  switch (list_command->filter_field)
  {
  case 1:
    for (int i = 0; i < list->number_of_cars; ++i)
    {
      if (strcmp(list->car[i].license_plate, list_command->filter_value) == 0)
      {
        delete_by_license_plate(list, list_command, &i);
        ret_code = DELETE_SUCCESS;
      }
    }
    break;
  case 2:
    for (int i = 0; i < list->number_of_cars; ++i)
    {
      if (list->car[i].power == atoi(list_command->filter_value))
      {
        delete_by_power(list, list_command, &i);
        ret_code = DELETE_SUCCESS;
      }
    }
    break;
  case 3:
    for (int i = 0; i < list->number_of_cars; ++i)
    {
      if (strcmp(list->car[i].brand, list_command->filter_value) == 0)
      {
        delete_by_brand(list, list_command, &i);
        ret_code = DELETE_SUCCESS;
      }
    }
    break;
  case 4:
    for (int i = 0; i < list->number_of_cars; ++i)
    {
      if (strcmp(list->car[i].model, list_command->filter_value) == 0)
      {
        delete_by_model(list, list_command, &i);
        ret_code = DELETE_SUCCESS;
      }
    }
    break;
  case 5:
    for (int i = 0; i < list->number_of_cars; ++i)
    {
      if (list->car[i].color == atoi(list_command->filter_value))
      {
        delete_by_color(list, list_command, &i);
        ret_code = DELETE_SUCCESS;
      }
    }
  case 6:
    for (int i = 0; i < list->number_of_cars; ++i)
    {
      if (list->car[i].year == atoi(list_command->filter_value))
      {
        delete_by_year(list, list_command, &i);
        ret_code = DELETE_SUCCESS;
      }
    }
    break;
  default:
    break;
  }
  list->car = (car *)realloc(list->car, (sizeof(car) * list->number_of_cars));

  return ret_code;
} /* delete_car */

/*
  Name:        delete_by_power

  Purpose:     delete all items that match on field - power

  Params:      IN/OUT list - car struct from here 
               IN list_command -  command struct
               IN/OUT i - index

  Returns:     Nothing
*/
void delete_by_power(car_list *list, car_command *list_command, int *i)
{
  for (int j = *i + 1; j < list->number_of_cars; ++j)
  {
    if (list->car[j].power == atoi(list_command->filter_value))
    {
      continue;
    }
    memcpy(&list->car[*i], &list->car[j], sizeof(car));
    ++*i;
  }
  list->number_of_cars = *i;
} /* delete_by_power */

/*
  Name:        delete_by_license_plate

  Purpose:     delete all items that match on field - license plate

  Params:      IN/OUT list - car struct from here 
               IN list_command -  command struct
               IN/OUT i - index

  Returns:     Nothing
*/
void delete_by_license_plate(car_list *list, car_command *list_command, int *i)
{
  for (int j = *i + 1; j < list->number_of_cars; ++j)
  {
    if (strcmp(list->car[j].license_plate, list_command->filter_value) == 0)
    {
      continue;
    }
    memcpy(&list->car[*i], &list->car[j], sizeof(car));
    ++*i;
  }
  list->number_of_cars = *i;
} /* delete_by_license_plate */

/*
  Name:        delete_by_brand

  Purpose:     delete all items that match on field - brand

  Params:      IN/OUT list - car struct from here 
               IN list_command -  command struct
               IN/OUT i - index

  Returns:     Nothing
*/
void delete_by_brand(car_list *list, car_command *list_command, int *i)
{
  for (int j = *i + 1; j < list->number_of_cars; ++j)
  {
    if (strcmp(list->car[j].brand, list_command->filter_value) == 0)
    {
      continue;
    }
    memcpy(&list->car[*i], &list->car[j], sizeof(car));
    ++*i;
  }
  list->number_of_cars = *i;
} /* delete_by_brand */

/*
  Name:        delete_by_model

  Purpose:     delete all items that match on field - model

  Params:      IN/OUT list - car struct from here 
               IN list_command -  command struct
               IN/OUT i - index

  Returns:     Nothing
*/
void delete_by_model(car_list *list, car_command *list_command, int *i)
{
  for (int j = *i + 1; j < list->number_of_cars; ++j)
  {
    if (strcmp(list->car[j].model, list_command->filter_value) == 0)
    {
      continue;
    }
    memcpy(&list->car[*i], &list->car[j], sizeof(car));
    ++*i;
  }
  list->number_of_cars = *i;
} /* delete_by_model */

/*
  Name:        delete_by_color

  Purpose:     delete all items that match on field - color

  Params:      IN/OUT list - car struct from here 
               IN list_command -  command struct
               IN/OUT i - index

  Returns:     Nothing
*/
void delete_by_color(car_list *list, car_command *list_command, int *i)
{
  for (int j = *i + 1; j < list->number_of_cars; ++j)
  {
    if (list->car[j].color == atoi(list_command->filter_value))
    {
      continue;
    }
    memcpy(&list->car[*i], &list->car[j], sizeof(car));
    ++*i;
  }
  list->number_of_cars = *i;
} /* delete_by_color */

/*
  Name:        delete_by_year

  Purpose:     delete all items that match on field - year

  Params:      IN/OUT list - car struct from here 
               IN list_command -  command struct
               IN/OUT i - index

  Returns:     Nothing
*/
void delete_by_year(car_list *list, car_command *list_command, int *i)
{
  for (int j = *i + 1; j < list->number_of_cars; ++j)
  {
    if (list->car[j].year == atoi(list_command->filter_value))
    {
      continue;
    }
    memcpy(&list->car[*i], &list->car[j], sizeof(car));
    ++*i;
  }
  list->number_of_cars = *i;
} /* delete_by_year */

/*
  Name:        display

  Purpose:     display all items from car list

  Params:      IN list - car struct from here 

  Returns:     Nothing
*/
void display(car_list *list)
{
  for (int i = 0; i < list->number_of_cars; ++i)
  {
    printf("Car index \t[%d]\n", i);
    printf("License : \t%s\n", list->car[i].license_plate);
    printf("Power: \t%d\n", list->car[i].power);
    printf("Brand: \t%s\n", list->car[i].brand);
    printf("Model: \t%s\n", list->car[i].model);
    printf("Color: \t%d\n", list->car[i].color);
    printf("Year: \t%d\n\n", list->car[i].year);
  }
} /* display */

/*
  Name:        reset

  Purpose:     initialize command fields to initial values

  Params:      IN list_command -  command struct

  Returns:     Nothing
*/
void reset(car_command *command)
{
  command->id = INITIAL;
  strcpy(command->detail, "");
  command->filter_field = INVALID;
  strcpy(command->filter_value, "");
  command->sort_field = INVALID;
  command->sort_ascending = true;
} /* reset */

/*
  Name:        display_help_support

  Purpose:     display string messages

  Params:      Nothing

  Returns:     Nothing
*/
void display_help_support()
{
  printf("Available command examples:\n"
         "add |AUD 1023|125|Audi|A6|red|2016|\n"
         "list -filter brand bmw -sort year|d\n"
         "list\n"
         "list -filter brand bmw\n"
         "list -sort year|a\n"
         "delete -filter year 2012\n");
} /* display_help_support */
