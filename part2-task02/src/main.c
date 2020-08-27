
/* 
  Name:      main.c                                                            

  Purpose:   A program to convert a lowercase string to uppercase    
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(int argc, char **argv)
{
  char str[100];
  
  scanf("%s", str);
  to_upper(str);
  
  printf("%s\n", str);

  return 0;
} /* main */
