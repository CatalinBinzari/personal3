
/*
  Header:  commands.h

  Purpose: Contains declaration from commands.c file
*/

#ifndef COMMANDS_H
#define COMMANDS_H
#include "car.h"

int parse_command(const char *user_input, car_command *command);
field get_field(const char *token);

#endif /* COMMANDS_H */
