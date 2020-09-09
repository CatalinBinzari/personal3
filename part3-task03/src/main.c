
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
      printf("ret code 's', :%d\n", ret_code);
      break;
    case 'g':
      ret_code = add_grades();
      printf("ret code 's', :%d\n", ret_code);
      break;
      break;
    case 'a':
      break;
    case 'h':
      //function print nfo
      break;
    case 'x':
      break;
    default:
      break;
    }
  }

  printf("\nSuccessfully closed all files and exited.\n");

  return 0;
} /* main */
