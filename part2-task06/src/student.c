
/* 
  Name:      student.c 

  Purpose:   Sorts struct array desc, display promoted students, calculates arithmetic mean 
*/

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

/*
  Name:        sort_by_grade

  Purpose:     Sort desc with bubble sort the array of structs

  Params:      OUT    st   - pointer to structure array of students
               IN     n    - number of students

  Returns:     Nothing
*/
void sort_by_grade(struct student *st, int n)
{
  int i, j;
  struct student temp;

  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < (n - 1 - i); j++)
    {
      if (st[j].grade < st[j + 1].grade)
      {
        temp = st[j];
        st[j] = st[j + 1];
        st[j + 1] = temp;
      }
    }
  }
} /* sort_by_grade */

/*
  Name:        display_promoted

  Purpose:     Display promoted students (grade>=50)

  Params:      OUT    st   - pointer to structure array of students
               IN     n    - number of students

  Returns:     Nothing
*/
void display_promoted(struct student *st, int n)
{
  int i;

  printf("\n\nName\tSurname\t\tGrade\n");
  for (i = 0; i < n; i++)
  {
    if (st[i].grade > 50)
    {
      printf("%s\t%s\t%.2f\n", st[i].name, st[i].surname, st[i].grade);
    }
    else
      break;
  }
} /* display_promoted */

/*
  Name:        arithmetic_mean

  Purpose:     Calculates arithmetic mean 

  Params:      OUT    st   - pointer to structure array of students
               IN     n    - number of students

  Returns:     a double result
*/
double arithmetic_mean(struct student *st, int n)
{
  double sum = 0;
  int i;

  for (i = 0; i < n; i++)
  {
    sum += st[i].grade;
  }

  return (sum / n);
} /* arithmetic_mean */
