
/* 
  Name:      main.c                                                            

  Purpose:   Based on user options, display/add students/grades, or filter and store to files
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
int main()
{
  char user_input;
  int ret_code;

  while (1)
  {
    printf("[user command]:");
    scanf(" %c", &user_input);

    switch (user_input)
    {
    case 'a':
      ret_code = add_product();
      printf("%s", meaningful(ret_code));
      break;
    case 'w':
      ret_code = print_products(&all);
      printf("%s", meaningful(ret_code));
      break;
    case 'b':
      ret_code = print_products(&all_by_name);
      printf("%s", meaningful(ret_code));
      break;
    case 'e':
      ret_code = print_products(&most_expensive);
      printf("%s", meaningful(ret_code));
      break;
    case 'h':
      printf_info();
      break;
    case 'x':
      printf("Exiting...\n");
      return 0;
      break;
    default:
      printf_info();
      break;
    }
  }

  return 0;
} /* main */
