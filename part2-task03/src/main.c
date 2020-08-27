
/* 
  Name:      main.c                                                            

  Purpose:   Finds the total number of alphabets, digits or special characters in a string.
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(int argc, char **argv)
{
  struct string_elements elements;
  char str[100];
  
  printf("Enter the string: ");
  scanf("%[^\n]s", str);

  elements = count_elements(str);
  
  printf("Alphabets: %d\n", elements.alphabets);
  printf("Digits: %d\n", elements.digits);
  printf("Special characters: %d\n", elements.special_chars);
  return 0;
} /* main */
