
/*****************************************************************************/
/* Name:   main.c                                                            */
/*                                                                           */
/* Purpose:  TODO                                                            */
/*                                                                           */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"

int main(int argc, char **argv)
{
  int length;
  int width;

  printf("Enter rectangle length (meters): ");
  scanf("%d", &length);
  printf("Enter rectangle width (meters): ");
  scanf("%d", &width);

  printf("Rectangle area is: %d square meters\n", rectangle_area(length, width));

  return 0;
} /* main */
