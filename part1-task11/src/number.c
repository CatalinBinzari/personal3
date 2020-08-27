

/* 
  Name:      number.c   

  Purpose:   Find the eligibility of admission for a professional course    
*/

#include <stdio.h>
#include "number.h"

/*
  Name:        admission

  Purpose:     Find the eligibility of admission

  Params:      IN   mark_math - math at math
               IN   phy_mark - math at phy
               IN   chem_mark - mark at chem

  Returns:     1 if admitted, 0 if rejected
*/
int admission(int math_mark, int phy_mark, int chem_mark)
{
  int admited = FALSE;
  if ((math_mark >= 65) &&
      (phy_mark >= 55) &&
      (chem_mark >= 50) &&
      ((math_mark + phy_mark + chem_mark >= 180) ||
       (math_mark + phy_mark >= 140)))
  {
    admited = TRUE;
  }

  return admited;
} /* admission */
