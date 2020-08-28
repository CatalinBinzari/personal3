
/* 
  Name:      string.c 

  Purpose:   String manipulation using pointer arithmetics:
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <stdbool.h>
#include <string.h>

/*
  Name:        s_len

  Purpose:     Find the length of the string

  Params:      IN string - NULL terminated string               

  Returns:     an integer, meaning string length
*/
int s_len(const char* string)
{
  int str_len = 0;

  while(*string != '\0')
  {
    str_len++;
    string++;
  }

  return str_len;
} /* s_len */

/*
  Name:        find_char

  Purpose:     Find the the address of the first occurence of 'letter' in 'string'

  Params:      IN letter - letter
               IN string - NULL terminated string               

  Returns:     the address of the first occurence of "letter" in string,
               or NULL if letter is not found
*/
char* find_char(const char* letter, char* string) 
{
  char *address = NULL;

  while(*string != '\0')
  { 
    if(*string == *letter)
    {      
      address = string;
      break;
    }
    string++;
  }
  return address;
} /* find_char */

/*
  Name:        get_index

  Purpose:     Find the index of the first occurence of letter in the string

  Params:      IN letter_address - letter address
               IN string - NULL terminated string               

  Returns:     the address of the first occurence of "letter" in string,
               or -1 id address is not found
*/
int get_index(const char* letter_address, const char* string) 
{ 
  int index = 0;

  while( letter_address != string && *string !='\0')
  {
    index++;
    string++;
  }
  if(*string =='\0') 
  {
    index = -1;
  }

  return index;
} /* get_index */

/*
  Name:        trim_vowel

  Purpose:     Remove vowels from a string.

  Params:      IN  input  - input string 
               OUT out    - output string without vowels               

  Returns:     Nothing
*/
void trim_vowel(const char* input, char* out)
{
  bool is_vowel = false;

  while( *input !='\0')
  { 
    is_vowel = (*input == 'a' || *input == 'e' || *input == 'i' || *input == 'o' || *input == 'u' ||
                       *input == 'A' || *input == 'E' || *input == 'I' || *input == 'O' || *input == 'U');
    if(is_vowel)
    {
      input++;
      is_vowel = false;
    }
    else
    {
      *out++=*input++;
    }
  }
} /* trim_vowel */

/*
  Name:        is_palindrome

  Purpose:     Check if string is palindrome

  Params:      IN  input  - input string                

  Returns:     true if string is palindrome, else false
*/
bool is_palindrome(const char* input)
{
  int l = 0;
  int str_len = s_len(input) - 1;
  while (str_len > l) 
	{ 
		if (*(input + l++) != *(input + str_len--)) 
		{ 
			return false; 
		} 
	} 

  return true;
} /* is_palindrome */