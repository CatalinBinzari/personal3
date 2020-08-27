
/*
  Name:        triangle.c

  Purpose:     Verify if triangle may exit or not
*/


#include "triangle.h"

/*
  Name:        triangle_angles

  Purpose:     verify triangle existence

  Params:      IN    first_angle   - int, angle from user
               IN    second_angle  - int, angle from user
               IN    third_angle   - int, angle from user

  Returns:  0 if triangle does not exist, otherwise 1
*/
int triangle_angles(int first_angle, int second_angle, int third_angle)
{
    if ((first_angle <= 0) ||
       (second_angle <= 0) || 
        (third_angle <= 0) ||
        ((first_angle + second_angle + third_angle) != 180))
    {
      return 0;
    }

    return 1;
} /* triangle_angles */
