
/* 
  Name:      main.c                                                            

  Purpose:   Find the eligibility of admission for a professional course    
*/

#include <stdio.h>
#include <stdlib.h>
#include "number.h"

int main(int argc, char **argv)
{
  int math_mark;
  int phy_mark;
  int chem_mark;

  printf("Enter math mark: ");
  scanf("%d", &math_mark);
  printf("Enter phy mark: ");
  scanf("%d", &phy_mark);
  printf("Enter chem mark: ");
  scanf("%d", &chem_mark);

  printf("Result: %d\n", admission(math_mark, phy_mark, chem_mark));
  return 0;
} /* main */
