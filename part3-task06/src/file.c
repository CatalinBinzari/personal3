
/* 
  Name:      file.c 

  Purpose:   Contain functions which parse the input file char by char and store 'key-value' pairs to dictionary 
*/

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>

bool is_end_part_of_key(char ch);
bool is_edge_part_of_value(char ch);

/*
  Name:        parse_file

  Purpose:     Parse file char by char and store 'key-value' pairs to the dictionary
               it gets as parameter.
               Prints success/error/warning messages

  Params:      IN filename - filename to parse
               IN/OUT dict - pointer to dictionary

  Returns:     Nothing
*/
void parse_file(char *filename, dict_t **dict)
{
  char key_tmp[KEY_LENGTH];
  char value_tmp[VALUE_LENGTH];
  int c;
  bool ignoring = false;
  char ch = '\0';
  bool parse_key = false;
  bool parse_value = false;
  int index = 0;
  bool was_equal = false;
  bool waiting_for_equal = false;

  FILE *f_ptr = fopen(filename, "r");

  if (f_ptr == NULL)
  {
    printf("File not found!\n");
    exit(EXIT_FAILURE);
  }

  while ((c = fgetc(f_ptr)) != EOF)
  {
    ch = (char)c;

    if ((ignoring = parse_comments(ch, ignoring)))
    {
      continue;
    }

    if (((ch == '\t') || (ch == ' ') || (ch == '\n')) &&
        !(parse_key || parse_value))
    {
      continue;
    }

    if (parse_key_value(ch, &parse_key, &parse_value, &was_equal, &waiting_for_equal, key_tmp, value_tmp, &index))
    {
      print_error_string(add_value(dict, key_tmp, value_tmp), key_tmp);
    }
  }

  fclose(f_ptr);
} /* parse_file */

/*
  Name:        parse_comments

  Purpose:     Parse comments staring with '#' till the end of line

  Params:      IN ch - character to verify
               IN/OUT ignoring - is true if comment was found, else false

  Returns:     true, if comment was found, and
               false when it reaches end of the line
*/
bool parse_comments(char ch, bool ignoring)
{
  if (ch == '#')
  {
    ignoring = true;
  }
  else if ((ch == '\n') && ignoring)
  {
    ignoring = false;
  }

  return ignoring;
} /* parse_comments */

/*
  Name:        parse_key_value

  Purpose:     Parse 'key-value' pair

  Params:      IN ch - character to verify
               IN/OUT parse_key - status of parsing, is true if now key is being parsed
               IN/OUT parse_value - status of parsing, is true if now value is being parsed 
               IN/OUT was_equal - is true if '=' was parsed
               IN/OUT waiting_for_equal - is true if next char is expected to be '='
               OUT key_tmp - the parsed key is stored there
               OUT value_tmp - the parsed value is stored there
               int *index - place in the key/value where to append the current parsed char

  Returns:     true, if 'key-value' pair has finished parsing, else false
*/
bool parse_key_value(char ch, bool *parse_key, bool *parse_value, bool *was_equal,
                     bool *waiting_for_equal, char *key_tmp, char *value_tmp, int *index)
{
  if (is_front_part_of_key(ch) && !*parse_value && !*parse_key && !*waiting_for_equal)
  {
    *parse_key = true;
    key_tmp[(*index)++] = ch;
  }
  else if (is_end_part_of_key(ch) && !*parse_value && *parse_key && !*waiting_for_equal)
  {
    if (ch == '=')
    {
      *was_equal = true;
      *waiting_for_equal = false;
    }
    else
    {
      *waiting_for_equal = true;
    }

    *parse_key = false;
    key_tmp[(*index)++] = '\0';
    *index = 0;
  }
  else if (!*parse_value && *parse_key && !*waiting_for_equal)
  {
    key_tmp[(*index)++] = ch;
  }
  else if (is_edge_part_of_value(ch) && !*parse_key && !*parse_value && *was_equal)
  {
    *parse_value = true;
    *was_equal = false;
  }
  else if (is_edge_part_of_value(ch) && !*parse_key && *parse_value)
  {
    *parse_value = false;
    value_tmp[(*index)++] = '\0';
    *index = 0;
    return true;
  }
  else if (!*parse_key && *parse_value)
  {
    value_tmp[(*index)++] = ch;
  }
  else if (ch == '=' && *waiting_for_equal)
  {
    *waiting_for_equal = false;
    *was_equal = true;
  }
  else
  {
    printf("[ERROR]: Unknown character! ASCII:%d\n", ch);
    exit(EXIT_FAILURE);
  }

  return false;
} /* parse_key_value */

/*
  Name:        is_front_part_of_key

  Purpose:     Verify if char is '_' or is a letter

  Params:      IN ch - character to verify

  Returns:     true, if char is '_' is a letter, else false
*/
bool is_front_part_of_key(char ch)
{
  return (isalpha(ch) || ch == '_');
} /* is_front_part_of_key */

/*
  Name:        is_end_part_of_key

  Purpose:     Verify if char is '='

  Params:      IN ch - character to verify

  Returns:     true, if ch is '=', else false
*/
bool is_end_part_of_key(char ch)
{
  return ((ch == '=') || (ch == ' ') || (ch == '\t'));
} /* is_end_part_of_key */

/*
  Name:        is_edge_part_of_value

  Purpose:     Verify if char is '"'

  Params:      IN ch - character to verify

  Returns:     true, if ch is '"', else false
*/
bool is_edge_part_of_value(char ch)
{
  return (ch == '"');
} /* is_edge_part_of_value */

/*
  Name:        print_error_string

  Purpose:     Based on error code, prints a specific error message

  Params:      IN ret_code - error code
               IN key - key 
              
  Returns:     Nothing
*/
void print_error_string(int ret_code, char *key)
{
  switch (ret_code)
  {
  case SUCCESS:
    printf("[SUCCESS] '%s'\n", key);
    break;
  case EMPTY_VALUE:
    printf("[WARNING] Empty value! '%s' has been removed from dictionary\n", key);
    break;
  case INVALID:
    printf("[ERROR] Invalid 'key=value' pair found, '%s'\n", key);
    exit(EXIT_FAILURE);
    break;

  default:
    break;
  }
} /* print_error_string */
