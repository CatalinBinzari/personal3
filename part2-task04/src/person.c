
/* 
  Name:      person.c 

  Purpose:   Contains functions for reading, outputing and comparing 2 person structures    
*/

#include <stdio.h>
#include <stdlib.h>
#include "person.h"

/*
  Name:        greater_age

  Purpose:     Output the person with the greater age

  Params:      IN per1 - struct person per1
               IN per2 - struct person per2

  Returns:     struct per1, if per1.age > per2.age, else struct per2,
               or struct per3, if the persons age is equal
*/
struct person greater_age(struct person per1, struct person per2) 
{ 
  struct person per3={"The same age", per1.age};
  
  return ((per1.age != per2.age) ? ((per1.age > per2.age) ? per1 : per2) : per3);
} /* greater_age */

/*
  Name:        output_person

  Purpose:     Output the person

  Params:      IN per - struct person per

  Returns:     Nothing 
*/
void output_person(struct person per) 
{
  printf("\nThe greater person is:\nPerson name: %s\nPerson age: %d\n", per.name, per.age);
} /* output_person */

/*
  Name:        read_person

  Purpose:     Read data and store it into person struct

  Params:      Nothing
               
  Returns:     person struct with read data
*/
struct person read_person() 
{
  struct person per;
  per.name = (char*)malloc(sizeof(char));
  printf("\nEnter person name: ");
  scanf("%s", per.name);
  printf("Enter person age: ");
  scanf("%d", &per.age);
  return per;
} /* read_person */
