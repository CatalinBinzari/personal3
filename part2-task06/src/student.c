
/* 
  Name:      student.c 

  Purpose:   TODO   
*/

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

/*
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
}

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
}

void arithmetic_mean(struct student *st, int n)
{
  
}