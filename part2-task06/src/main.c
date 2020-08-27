
/* 
  Name:      main.c                                                            

  Purpose:   Order the students after the grade and display the promoted students.
             Calculate the arithmetic mean obtained.
*/

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char **argv)
{
  struct student students[STUD_NR] = {{"name1", "surname1", 89.5},
                                      {"name2", "surname2", 100.00},
                                      {"name3", "surname3", 67.5},
                                      {"name4", "surname4", 95.5},
                                      {"name5", "surname5", 33.3},
                                      {"name6", "surname6", 22.7},
                                      {"name7", "surname7", 89.5},
                                      {"name8", "surname8", 0},
                                      {"name9", "surname9", 99.9}};
  sort_by_grade(students, STUD_NR);
  display_promoted(students, STUD_NR);
  printf("Arithmetic mean: %.2f\n", arithmetic_mean(students, STUD_NR));
  return 0;
} /* main */
