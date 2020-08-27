
/*****************************************************************************/
/* Name:   main.c                                                            */
/*                                                                           */
/* Purpose:  Verify if a triangle can be formed with the                     */
/*           given value for the angles                                      */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"

int main(int argc, char **argv)
{
    int first_angle;
    int second_angle;
    int third_angle;

    printf("Enter first angle length (degrees): ");
    scanf("%d", &first_angle);
    printf("Enter second angle length (degrees): ");
    scanf("%d", &second_angle);
    printf("Enter third angle length (degrees): ");
    scanf("%d", &third_angle);

    if (triangle_angles(first_angle, second_angle, third_angle))
    {
      printf("Triangle exists\n");
    }
    else
    {
      printf("Triangle does not exist\n");
    }

    return 0;
} /* main */
