
/*****************************************************************************/
/* Name:   main.c                                                            */
/*                                                                           */
/* Purpose:  Calculate aria and perimeter from values given by user          */
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
  printf("Rectangle perimeter is: %d square meters\n", rectangle_perimeter(length, width));

  return 0;
} /* main */
