
/*
  Header:  student.h

  Purpose: Contains function declarations from student.c file
*/

#ifndef STUDENT_H
#define STUDENT_H

struct student {
    char *name;
    char *surname;
    double grade;
};

enum student_add_result
{
  ADD_INSUCCESS = -1,
  ADD_SUCCESS = 0,
  ARRAY_FULL = 1,
  PARAMS_INVALID = 2
};


void sort_by_grade(struct student *st, int n);
void display_promoted(struct student *st, int n);
double arithmetic_mean(struct student *st, int n);
struct student new_student();
int add_students(struct student *students, int *student_counter, struct student student_to_add, int number_of_students);
int compareGradesDesc(const void *pa, const void *pb);

#endif /* STUDENT_H */
