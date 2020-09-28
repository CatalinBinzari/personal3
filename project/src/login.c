
/*
    Name:       login.c
    
    Purpose:    Contain functions used for login
*/

#include "login.h"

/*
  Name:        _log

  Purpose:     Variadic function used for logging

  Description: If the level is less then LOG_LEVEL, this function should return immediately.
               If the value is greater equal, this function should generate a string composed of 
               <filename>::<line>: <variable_arguments><new_line>
               and print it to stderr.

  Params:      level - an integer used for the message level (info, warning, error)
               filename - a string describing the file where it took place (source file)
               line - an integer describing the line number
               format - a string describing the message format
               variable_arguments - ...

  Returns:     Nothing
*/
void _log(const int level, const char *filename, const int line, const char *format, ...)
{
  if (level < LOG_LEVEL)
  {
    return;
  }

  va_list args;
  va_start(args, format);
  char buffer[256];

  vsnprintf(buffer, 256, format, args);
  va_end(args);

  fprintf(stderr, "%s::%d: %s\n", filename, line, buffer);
} /* _log */
