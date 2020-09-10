
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
    case 's':
      ret_code = add_student();
      printf("%s", meaningful(ret_code));
      break;
    case 'g':
      ret_code = add_grades();
      printf("%s", meaningful(ret_code));
      break;
    case 'a':
      ret_code = view_graduated();
      printf("%s", meaningful(ret_code));
      break;
    case 'h':
      printf_info();
      break;
    case 'x':
      printf("Exiting...\n");
      printf("\nSuccessfully closed all files and exited.\n");
      return 0;
      break;
    default:
      printf_info();
      break;
    }
  }

  return 0;
} /* main */
