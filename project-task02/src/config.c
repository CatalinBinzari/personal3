
/*
    Name:       config.c
    
    Purpose:    Contain functions which are parsing config type file
*/

#include "../include/config.h"

/*
  Name:        get_config_value

  Purpose:     TODO

  Params:      IN filename - a string with the name of the file to read from
               IN key - a string with the left hand value of the assignment
               OUT value - the output where the value will be stored
               OUT length - the maximum length of the output                     

  Returns:     true  if the key was found
               false if the key wasn't found   
*/
bool get_config_value(char *filename, char *key, char *value, int *length)
{
  char buffer[BUFFER_LENGTH];
  char read_key[KEY_LENGTH];
  char read_value[VALUE_LENGTH];
  int return_code;
  FILE *f_ptr = fopen(filename, "r");

  if (f_ptr == NULL)
  {
    printf("File not found!\n");
    exit(EXIT_FAILURE);
  }

  while (fgets(buffer, BUFFER_LENGTH, f_ptr))
  {
    /* %[^\"] - means scan everything to string until ' " ' char appears */
    return_code = sscanf(buffer, "%[_,a-z,A-Z,0-9] = \"%[^\"]", read_key, read_value);

    /* retur_code == 2, means both read_key and read_value was scaned */
    if (return_code == 2)
    {
      if (strcmp(read_key, key) == 0)
      {
        *length = my_strcpy(value, read_value);
        fclose(f_ptr);
        return true;
      }
    }
    else
    {
      printf("[WARNING]\n");
    }
    
  }

  fclose(f_ptr);

  return false;
} /* get_config_value */

/*
  Name:        my_strcpy

  Purpose:     Basic implementation of string copy function and calculating the length of the string too

  Params:      IN destination - string where to copy source string
               IN source - strong to be copied to destination

  Returns:     destionation string length 
*/
int my_strcpy(char *destination, char *source)
{
  int destingation_length = 0;

  while (*source != '\0')
  {
    *destination = *source;
    destingation_length++;
    destination++;
    source++;
  }
  *destination = '\0';

  return destingation_length;
} /* my_strcpy */
