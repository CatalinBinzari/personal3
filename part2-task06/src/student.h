
/*
  Header:  person.h

  Purpose: Contains function declarations from person.c file
*/

#ifndef PERSON_H
#define PERSON_H

#include "student_struct.h"
#define STUD_NR 9

void sort_by_grade(struct student *st, int n);
void display_promoted(struct student *st, int n);
void arithmetic_mean(struct student *st, int n);


#endif /* PERSON_H */
