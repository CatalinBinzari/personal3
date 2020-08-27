
/* 
  Name:      main.c                                                            

  Purpose:   Read the data for two persons and output the person with the greater age. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "person.h"

int main(int argc, char **argv)
{
  struct person per1;
  struct person per2;

  per1 = read_person();
  per2 = read_person();

  output_person(greater_age(per1, per2));
  
  free(per1.name);
  free(per2.name);

  return 0;
} /* main */
