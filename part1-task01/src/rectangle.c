
/*****************************************************************************/
/* Name:   rectangle.c                                                       */
/*                                                                           */
/* Purpose: Calculate aria and perimeter of a rectangle                      */
/*                                                                           */
/*****************************************************************************/

#include "rectangle.h"


/*
  Name:        rectangle_area.c

  Purpose:     Calculates aria of the rectangle

  Params:      IN    length   - rectagngle length
               IN    width    - rectangle width

  Returns:  if invalid parameters -1 otherwise, the rectangle area value
*/
int rectangle_area(int length, int width)
{
  if ((length <= 0) || (width <= 0))
  {
    return -1;
  }

  return (length * width);
} /* rectangle_area */


/*
  Name:        rectangle_perimeter.c

  Purpose:     Calculates perimeter of the rectangle

  Params:      IN    length   - rectagngle length
               IN    width    - rectangle width

  Returns:  if invalid parameters -1 otherwise, the rectangle perimeter value
*/
int rectangle_perimeter(int length, int width)
{
  if ((length <= 0) || (width <= 0))
  {
    return -1;
  }

  return ((length + width) * 2);
} /* rectangle_perimeter */
