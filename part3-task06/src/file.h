
/*
  Header:  file.h

  Purpose: Contains function declarations from file.c file
*/

#ifndef FILE_H
#define FILE_H
#include "dict/dict.h"
#include "valid/validation.h"
#define PATH "values.ini"

void parse_file(char *filename, dict_t **dict);
void print_error_string(int ret_code, char *code);
bool parse_comments(char ch, bool ignoring);

#endif /* FILE_H */
