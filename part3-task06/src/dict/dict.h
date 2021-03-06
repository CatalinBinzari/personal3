
/*
  Header:  dict.h

  Purpose: Contains function declarations from dict.c file
*/

#ifndef DICT_H
#define DICT_H
#include "../valid/validation.h"
#define KEY_LENGTH 32
#define VALUE_LENGTH 96

enum error_code
{
  KEY_NOT_FOUND = -3,
  INVALID,
  EMPTY_VALUE,
  SUCCESS
};

typedef struct dict_t_struct
{
  char key[KEY_LENGTH];
  char value[VALUE_LENGTH];
  struct dict_t_struct *next;
} dict_t;

dict_t **dict_alloc(void);
void dict_dealloc(dict_t **dict);
char *get_value(dict_t *dict, char *key);
int rem_value(dict_t **dict, char *key);
int add_value(dict_t **dict, char *key, char *value);
bool has_value(dict_t *dict, const char *key);
void print_all(dict_t *dict);
#endif /* DICT_H */
