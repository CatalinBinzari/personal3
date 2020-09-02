
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
  int student_counter = 0;
  int number_of_students;
  struct student students[100];
  struct student student_to_add;
  int return_code;

  printf("Insert number of students: ");
  scanf("%d", &number_of_students);

  while (student_counter < number_of_students)
  {
    student_to_add = new_student();
    return_code = add_students(students, &student_counter, student_to_add, number_of_students);
    switch (return_code)
    {
    case -1:
      printf("Unknown error!\n\n");
      break;
    case 0:
      printf("Added with success!\n\n");
      break;
    case 1:
      printf("Student array is full!\n\n");
      break;
    case 2:
      printf("Contain invalid parameters, try again!\n\n");
      break;

    default:
      break;
    }
  }
  printf("Sorted by grade:\n");
  sort_by_grade(students, number_of_students);
  display_promoted(students, number_of_students);
  printf("\nArithmetic mean: %.2f\n", arithmetic_mean(students, number_of_students));

  for (int i = 0; i < number_of_students; ++i)
  {
    free(students[i].name);
    free(students[i].surname);
  }

  return 0;
} /* main */
