
/*
    Name:       config.c
    
    Purpose:    Contain functions which are parsing config type file
*/

#include "config.h"

/*
  Name:        get_config_value

  Purpose:     Get value of a specific key and return true if it's found

  Params:      IN filename - a string with the name of the file to read from
               IN key - a string with the left hand value of the assignment
               OUT value - the output where the value will be stored
               IN length - the maximum length of the output                     

  Returns:     true  if the key was found
               false if the key wasn't found   
*/
bool get_config_value(char *filename, char *key, char *value, int length)
{
  const int buffer_length = KEY_LENGTH + length + ADDITIONAL_CHARACTER_LENGTH;
  char buffer[buffer_length];
  char read_key[KEY_LENGTH];
  char read_value[length];
  int return_code;

  FILE *f_ptr = fopen(filename, "r");

  if (f_ptr == NULL)
  {
    printf("File not found!\n");
    exit(EXIT_FAILURE);
  }

  while (fgets(buffer, buffer_length, f_ptr))
  {
    /* %[^\"] - means scan everything to string until ' " ' char appears */
    return_code = sscanf(buffer, "%[_,a-z,A-Z,0-9] = \"%[^\"]", read_key, read_value);

    /* retur_code == 2, means both read_key and read_value was scaned */
    if (return_code == 2)
    {
      if (strcmp(read_key, key) == 0)
      {
        strncpy(value, read_value, length-1);
        value[length - 1] = '\0';
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
  Name:        get_server_address

  Purpose:     Get ip and port based on specific key from a file

  Params:      IN filename - a string with the name of the file to read from
               IN key - a string with the left hand value of the assignment
               OUT ip - the output string where the value will be stored
               OUT port - port address                    

  Returns:     true  if the key was found
               false if the key wasn't found   
*/
bool get_server_address(char *filename, char *key, char *ip, unsigned short *port)
{
  char buffer[ADDRESS_BUFFER_LENGTH];
  char read_key[KEY_LENGTH];
  char read_ip[ADDRESS_LENGTH];
  int return_code;
  unsigned short read_port = 0;
  FILE *f_ptr = fopen(filename, "r");

  if (f_ptr == NULL)
  {
    printf("File not found!\n");
    exit(EXIT_FAILURE);
  }

  while (fgets(buffer, ADDRESS_BUFFER_LENGTH, f_ptr))
  {
    return_code = sscanf(buffer, "%[_,a-z,A-Z,0-9] = \"%[^:]:%hd", read_key, read_ip, &read_port);

    /* retur_code == 3, means all three: read_key and read_ip and read_port was scaned */
    if ((return_code == 3) && is_valid(read_ip, read_port))
    {
      if (strcmp(read_key, key) == 0)
      {
        strcpy(ip, read_ip);
        *port = read_port;
        fclose(f_ptr);

        return true;
      }
    }
  }
  fclose(f_ptr);

  return false;
} /* get_server_address */

/*
  Name:        is_valid

  Purpose:     Validates ip and port

  Params:      IN read_ip - ip address 
               IN read_port - port                 

  Returns:     true  if ip and port is valid
               false if one or both are not valid 
*/
bool is_valid(const char *read_ip, unsigned short read_port)
{
  if (is_ip_address(read_ip) && read_port <= 65535 && read_port > 0)
  {
    return true;
  }

  return false;
} /* is_valid */

/*
  Name:        validate_number

  Purpose:     Vefiry if string contains just digits

  Params:      IN str - string               

  Returns:     true  if string contains just digits
               false if a char from string is not digit
*/
bool validate_number(char *str)
{
  while (*str)
  {
    if (!isdigit(*str))
    {
      return false;
    }
    str++;
  }

  return true;
} /* validate_number */

/*
  Name:        is_ip_address

  Purpose:     Vefiry if the input IP string is a valid IP address

  Params:      IN ip - string               

  Returns:     true  if ip is valid
               false if ip is not valid
*/
bool is_ip_address(const char *ip)
{
  char ip_tmp[ADDRESS_LENGTH];
  int num, dots = 0;
  char *ptr;
  strcpy(ip_tmp, ip);

  if (ip_tmp == NULL)
  {
    return false;
  }
  /*  cut the string using dot delimiter */
  ptr = strtok(ip_tmp, ".");

  if (ptr == NULL)
  {
    return false;
  }

  while (ptr)
  {
    /* check whether the sub string is holding only number or not */
    if (!validate_number(ptr))
    {
      return false;
    }

    /* convert substring to number */
    num = atoi(ptr);
    if (num >= 0 && num <= 255)
    {
      ptr = strtok(NULL, ".");
      if (ptr != NULL)
        dots++;
    }
    else
    {
      return false;
    }
  }

  if (dots != 3)
  {
    return false;
  }

  return true;
} /* is_ip_address */
