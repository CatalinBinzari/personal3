
/* 
  Name:      dict.c 

  Purpose:   A key/value dict system
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"

/*
  Name:        dict_alloc

  Purpose:     Allocates a block of size dict_t

  Params:      Nothing
              
  Returns:     block of memory 
*/
dict_t **dict_alloc(void)
{
  return malloc(sizeof(dict_t));
} /* dict_alloc */

/*
  Name:        dict_dealloc

  Purpose:     Free a block of memory

  Params:      IN dict - pointer to dictionary
              
  Returns:     Nothing
*/
void dict_dealloc(dict_t **dict)
{
  dict_t *ptr;
  for (ptr = *dict; ptr != NULL; ptr = ptr->next)
  {
    free(ptr);
  }
} /* dict_dealloc */

/*
  Name:        get_value

  Purpose:     Get value of the key

  Params:      IN dict - pointer to dictionary
               IN key - key string
              
  Returns:     Value of the key or empty string
*/
char *get_value(dict_t *dict, char *key)
{
  dict_t *ptr;
  for (ptr = dict; ptr != NULL; ptr = ptr->next)
  {
    if (strcmp(ptr->key, key) == 0)
    {
      return ptr->value;
    }
  }

  return "";
} /* get_value */

/*
  Name:        rem_value

  Purpose:     Remove value from dictionary

  Params:      IN/OUT dict - pointer to dictionary
               IN key - key string to de removed
              
  Returns:     Return code:
               SUCCESS, in case when value was removed, 
               KEY_NOT_FOUND, in case when key was not found and nothing was removed
*/
int rem_value(dict_t **dict, char *key)
{
  dict_t *ptr, *prev;
  for (ptr = *dict, prev = NULL; ptr != NULL; prev = ptr, ptr = ptr->next)
  {
    printf("%s", "count");
    if (strcmp(ptr->key, key) == 0)
    {
      if (ptr->next != NULL)
      {
        if (prev == NULL)
        {
          *dict = ptr->next;
        }
        else
        {
          prev->next = ptr->next;
        }
      }
      else if (prev != NULL)
      {
        prev->next = NULL;
      }
      else
      {
        *dict = NULL;
      }

      free(ptr->key);
      free(ptr);

      return SUCCESS;
    }
  }
  return KEY_NOT_FOUND;
} /* rem_value */

/*
  Name:        add_value

  Purpose:     Validate and add item to dictionary

  Params:      IN/OUT dict - pointer to dictionary
               IN key - key string to de added
               IN value - value string to be added
              
  Returns:     Return code:
               INVALID, in case when invalid key or value is found
               EMPTY_VALUE, in case of empty value, after key is removed from dict
               SUCCESS, in case when 'key-value' pair is stored/added to dictionary
*/
int add_value(dict_t **dict, char *key, char *value)
{
  if (!valid(key, value))
  {
    return INVALID;
  }

  if (rem_value(dict, key) != KEY_NOT_FOUND)
  {
    printf("[WARNING] '%s' is replacing an existing key!\n", key);
  }

  if (strlen(value) == 0)
  {
    return EMPTY_VALUE;
  }

  dict_t *d = malloc(sizeof(struct dict_t_struct));
  strcpy(d->key, key);
  strcpy(d->value, value);
  d->next = *dict;
  *dict = d;

  return SUCCESS;
} /* add_value */

/*
  Name:        has_value

  Purpose:     Verifies if key exist in dictionary.
               Returns true if key exist, else false.

  Params:      IN dict - pointer to dictionary
               IN key - key string
              
  Returns:     true if key exist in dictionary, else false
*/
bool has_value(dict_t *dict, const char *key)
{
  dict_t *ptr;
  for (ptr = dict; ptr != NULL; ptr = ptr->next)
  {
    if (strcmp(ptr->key, key) == 0)
    {
      return true;
    }
  }

  return false;
} /* has_value */

/*
  Name:        print_all

  Purpose:     Print all 'key-value' pairs from input dict

  Params:      IN dict - pointer to dictionary
              
  Returns:     Nothing
*/
void print_all(dict_t *dict)
{
  int i = 0;
  dict_t *ptr;
  for (ptr = dict; ptr != NULL; ptr = ptr->next)
  {
    printf("[%d] %s = %s\n", i, ptr->key, ptr->value);
    ++i;
  }
} /* print_all */
