
/*
  Header:  string.h

  Purpose: Contains function declarations from string.c file
*/

#ifndef STRING_H
#define STRING_H
#include <stdbool.h>

int s_len(const char* string);
char* find_char(const char* letter, char* string);
int get_index(const char* letter_address, const char* string);
void trim_vowel(const char* input, char* out);
bool is_palindrome(const char* input);

#endif /* STRING_H */
