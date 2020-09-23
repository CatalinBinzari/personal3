
/* 
  Name:      validation.c 

  Purpose:   Contains just functions we use to validate a 'key-value' pair
*/

#include <ctype.h>
#include <string.h>
#include "validation.h"

/*
  Name:        valid

  Purpose:     Verify if key and value is valid

  Params:      IN key - key as a string 
               IN value - value as a string 
              
  Returns:     true, if 'key-value' pair is valid, else false
*/
bool valid(char *key_tmp, char *value_tmp)
{
    if ((strlen(key_tmp) == 0) ||
        (strlen(key_tmp) > 31) ||
        (strlen(value_tmp) > 95) ||
        !is_valid_key(key_tmp) ||
        !is_valid_value(value_tmp))
    {
        return false;
    }

    return true;
} /* valid */

/*
  Name:        is_valid_key

  Purpose:     Verify if key is valid

  Params:      IN key - key as a string 
              
  Returns:     true, if key is valid, else false
*/
bool is_valid_key(char *key)
{
    if (!isalpha(key[0]) && !(key[0] == '_'))
    {
        return false;
    }

    for (int i = 1; key[i] != '\0'; ++i)
    {
        if ((key[i] != '_' && !isalpha(key[i]) && !isdigit(key[i])))
        {
            return false;
        }
    }

    return true;
} /* is_valid_key */

/*
  Name:        is_valid_value

  Purpose:     Verify if value is valid

  Params:      IN value - value as a string 
              
  Returns:     true, if value is valid, else false
*/
bool is_valid_value(char *value)
{

    for (int i = 0; value[i] != '\0'; ++i)
    {
        if (value[i] == '"' || value[i] == '\n')
        {
            return false;
        }
    }

    return true;
} /* is_valid_value */
