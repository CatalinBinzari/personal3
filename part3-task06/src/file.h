
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
bool is_front_part_of_key(char ch);
bool parse_key_value(char ch, bool *parse_key, bool *parse_value, bool *was_equal,
                     bool *waiting_for_equal, char *key_tmp, char *value_tmp, int *index);

#endif /* FILE_H */
