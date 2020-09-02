
/* 
  Name:      number.c   

  Purpose:   Calculates fee of the payment 
*/

#include <stdio.h>
#include "number.h"

/*
  Name:        pay_charge

  Purpose:     Calculates fee depending on number of minutes are spend

  Params:      IN   minutes - number of minutes

  Returns:     representing the fee user may pay
*/
int pay_charge(int minutes)
{
  int fee;

  if(minutes < 0)
  {
    fee = -1;
  }
  else if(minutes <= 50)
  {
    fee = 0;
  }
  else if (minutes <= 199)
  {
    fee = (minutes - 50) * FEE_FOR_199_MINUTES;
  }
  else if (minutes <= 399)
  {
    fee = (minutes - 199) * FEE_FOR_399_MINUTES + pay_charge(199);
  }
  else if (minutes <= 499)
  {
    fee = (minutes - 399) * FEE_FOR_499_MINUTES + pay_charge(399);
  }
  else
  {
    fee = (minutes - 499) * FEE_FOR_500_MINUTES + pay_charge(499);
  }
  
  return fee;
} /* pay_charge */
