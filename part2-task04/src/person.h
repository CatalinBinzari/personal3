
/*
  Header:  person.h

  Purpose: Contains function declarations from person.c file
*/

#ifndef PERSON_H
#define PERSON_H

#define TRUE 1
#define FALSE 0

#include "person_struct.h"

struct person greater_age(struct person per1, struct person per2);
void output_person(struct person per);
struct person read_person();

#endif /* PERSON_H */
