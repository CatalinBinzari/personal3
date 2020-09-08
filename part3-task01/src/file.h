
/*
  Header:  string.h

  Purpose: Contains function declarations from file.c file
*/

#ifndef FILE_H
#define FILE_H
#include <stdbool.h>
#define BUFFER_SIZE 1000

void replace_all(char *str, const char *old_word, const char *new_word, int *counter);
char* concat(const char *s1, const char *s2, const char *s3);
#endif /* FILE_H */
