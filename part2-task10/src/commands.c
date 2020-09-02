
/* 
  Name:      commands.c 

  Purpose:   Used for functions that parses user input
*/

#include <stdio.h>
#include <stdlib.h>
#include "car.h"
#include <string.h>
#include <stddef.h>

/*
  Name:        parse_command

  Purpose:     Use the command ID to determine which function to call: add_car, list_car, delete_car

  Params:      IN command - command written by user           

  Returns:     int
*/
int parse_command(const char *user_input, car_command *command)
{
  char delimiters[] = " ";
  char *running = strdup(user_input);
  char *token;
  token = strsep(&running, delimiters);

  if (strcmp(token, "add") == 0)
  {
    command->id = ADD_COMMAND;
    strcpy(command->detail, running);
  }
  else if (strcmp(token, "list") == 0)
  {
    command->id = LIST_COMMAND;
    token = strsep(&running, delimiters);
    if(strcmp(token, "-filter") == 0)
    {
      token = strsep(&running, delimiters);
      command->filter_field = get_field(token); //tomodify
      token = strsep(&running, delimiters);
      strcpy(command->filter_value, token);
    }
    token = strsep(&running, delimiters);
    if(strcmp(token, "-sort") == 0)
    {
      token = strsep(&running, delimiters);
      command->sort_field = get_field(token); //to modify
      token = strsep(&running, delimiters);
      command->sort_value = (strcmp(token, "a") == 0 ? true : false);
    }
  }
  else if (strcmp(token, "delete") == 0)
  {
    command->id = DELETE_COMMAND;
        token = strsep(&running, delimiters);
    if(strcmp(token, "-filter") == 0)
    {
      token = strsep(&running, delimiters);
      command->filter_field = get_field(token); //tomodify
      token = strsep(&running, delimiters);
      strcpy(command->filter_value, token);
    }
  }
  else if (strcmp(token, "help") == 0)
  {
    command->id = HELP;
  }
  else if (strcmp(token, "exit") == 0)
  {
    command->id = EXIT;
  }
  else
  {
    command->id = TRY_AGAIN;
  }
  return 0;

} /* parse_command */

/*
  Name:        get_field

  Purpose:     compare token and return field of that token

  Params:      IN token - string         

  Returns:     field
*/
field get_field(const char* token)
{
  if (strcmp(token, "license_plate") == 0)
  {
    return LICENSE_PLATE;
  }
  else if(strcmp(token, "power") == 0)
  {
    return POWER;
  }
  else if(strcmp(token, "brand") == 0)
  {
    return BRAND;
  }
  else if(strcmp(token, "model") == 0)
  {
    return MODEL;
  }
  else if(strcmp(token, "color") == 0)
  {
    return COLOR;
  }
  else if(strcmp(token, "year") == 0)
  {
    return YEAR;
  }
  else 
  {
    return INVALID;
  }

} /* get_field */