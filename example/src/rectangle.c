
/*****************************************************************************/
/* Name:   rectangle.c                                                       */
/*                                                                           */
/* Purpose:  TODO                                                            */
/*                                                                           */
/*****************************************************************************/

#include "rectangle.h"


int rectangle_area(int length, int width)
{
  if ((length <= 0) || (width <= 0))
  {
    return -1;
  }

  return (length * width);
} /* area */
