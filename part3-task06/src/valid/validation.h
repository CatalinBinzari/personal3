
/*
  Header:  validation.h

  Purpose: Contains function declarations from validation.c file
*/

#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdbool.h>
#include "../dict/dict.h"

bool valid(char *key_tmp, char *value_tmp);
bool is_valid_key(char *key);
bool is_valid_value(char *value);

#endif /* VALIDATION_H */