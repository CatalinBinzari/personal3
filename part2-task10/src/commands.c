
/* 
  Name:      commands.c 

  Purpose:   Used for functions that parses user input
*/

#include <stdio.h>
#include <stdlib.h>
#include "commands.h"
#include <string.h>
#include <stddef.h>

/*
  Name:        parse_command

  Purpose:     Use the command ID to determine which function to call:
               add_car, list_car, delete_car, help, exit

  Params:      user_input -string given by user
               OUT command - written by user in formatted way           

  Returns:     Integer, meaning command ID
*/
int parse_command(const char *user_input, car_command *command)
{
  char delimiters[] = " ";
  char sort_delimiters[] = "|";
  char *running = strdup(user_input);
  char *token;
  token = strsep(&running, delimiters);

  if (strcmp(token, "add") == 0)
  {
    command->id = ADD_COMMAND;
    strcpy(command->detail, running);
  }
  else if (strncmp(token, "list", 4) == 0)
  {
    printf("in list 38\n");
    command->id = LIST_COMMAND;
    if (running != NULL)
    {
      token = strsep(&running, delimiters);
    }
    if (strcmp(token, "-filter") == 0)
    {
      token = strsep(&running, delimiters);
      command->filter_field = get_field(token);
      token = strsep(&running, delimiters);
      strcpy(command->filter_value, token);
      if (running != NULL)
      {
        token = strsep(&running, delimiters);
      }
    }

    if (strcmp(token, "-sort") == 0)
    {
      token = strsep(&running, sort_delimiters);
      command->sort_field = get_field(token);
      command->sort_ascending = strncmp(running, "a", 1) == 0 ? true : false;
    }
  }
  else if (strcmp(token, "delete") == 0)
  {
    command->id = DELETE_COMMAND;
    token = strsep(&running, delimiters);
    if (strcmp(token, "-filter") == 0)
    {
      token = strsep(&running, delimiters);
      command->filter_field = get_field(token);
      token = strsep(&running, delimiters);
      if (token[strlen(token) - 1] == '\n')
        token[strlen(token) - 1] = '\0';
      strcpy(command->filter_value, token);
    }
  }
  else if (strncmp(token, "help", 4) == 0)
  {
    command->id = HELP;
  }
  else if (strncmp(token, "exit", 4) == 0)
  {
    command->id = EXIT;
  }

  return command->id;
} /* parse_command */

/*
  Name:        get_field

  Purpose:     compare token from user and returns field constant of that token

  Params:      IN token - string         

  Returns:     field constant, or INVALID, if field is not found
*/
field get_field(const char *token)
{
  if (strncmp(token, "license_plate", 13) == 0)
  {
    return LICENSE_PLATE;
  }
  else if (strncmp(token, "power", 5) == 0)
  {
    return POWER;
  }
  else if (strncmp(token, "brand", 5) == 0)
  {
    return BRAND;
  }
  else if (strncmp(token, "model", 5) == 0)
  {
    return MODEL;
  }
  else if (strncmp(token, "color", 5) == 0)
  {
    return COLOR;
  }
  else if (strncmp(token, "year", 4) == 0)
  {
    return YEAR;
  }
  else
  {
    return INVALID;
  }
} /* get_field */
