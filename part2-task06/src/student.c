
/* 
  Name:      student.c 

  Purpose:   Sorts struct array desc, display promoted students, calculates arithmetic mean 
*/

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

/*
  Name:        compareGrades

  Purpose:     Used to compare grades from 2 structs

  Params:      IN pa = struct student
               IN pb = struct student

  Returns:     positive int, zero, negative int 
*/
int compareGradesDesc(const void *pa, const void *pb)
{
  const struct student *p1 = pa;
  const struct student *p2 = pb;
  return p2->grade - p1->grade;
} /* compareGrades */

/*
  Name:        sort_by_grade

  Purpose:     Sort desc with qsort the array of structs

  Params:      OUT    st   - pointer to structure array of students
               IN     n    - number of students

  Returns:     Nothing
*/
void sort_by_grade(struct student *st, int n)
{
  qsort(st, n, sizeof(st[0]), compareGradesDesc);
} /* sort_by_grade */

/*
  Name:        display_promoted

  Purpose:     Display promoted students (grade>=50)

  Params:      IN    st   - pointer to structure array of students
               IN     n    - number of students

  Returns:     Nothing
*/
void display_promoted(struct student *st, int n)
{
  int i;

  printf("\n\nName\tSurname\t\tGrade\n");
  for (i = 0; i < n; i++)
  {
    if (st[i].grade >= 50)
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

  Params:      IN    st   - pointer to structure array of students
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

/*
  Name:        new_student

  Purpose:     Read student data from keyboard

  Params:      Nothing

  Returns:     student struct with read data
*/
struct student new_student()
{
  struct student st;
  st.name = (char*)malloc(sizeof(char) * 45);
  st.surname = (char*)malloc(sizeof(char) * 45);

  printf("Enter student name: ");
  scanf("%s", st.name);
  printf("Enter student surname: ");
  scanf("%s", st.surname);
  printf("Enter student grade: ");
  scanf("%le", &st.grade);

  return st;
} /* new_student */

/*
  Name:        add_students

  Purpose:     Insert student to student_array and checks possible errors

  Params:      students  -  students array
               student_counter  -  student arr index
               student_to_add  -  student to append to char array   
               number_of_students - max number of students

  Returns:     0 if student is added successfuly, 1 if student array is full, 2 if params are invalid
*/
int add_students(struct student *students, int *student_counter, struct student student_to_add, int number_of_students)
{ 
  int core_error = ADD_INSUCCESS;
  if (student_to_add.grade < 0 || student_to_add.grade > 100)
  {
    core_error = PARAMS_INVALID;
    return core_error;
  }

  if(*student_counter >= number_of_students)
  {
    core_error = ARRAY_FULL;
    return core_error;
  }

  students[*student_counter] = student_to_add;
  ++*student_counter;
  core_error = ADD_SUCCESS;
  
  return core_error;
} /* add_students */
