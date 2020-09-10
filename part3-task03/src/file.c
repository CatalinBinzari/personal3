
/* 
  Name:      file.c 

  Purpose:   File manipulation
*/

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>

/*
  Name:        add_student

  Purpose:     Get info from user and add the student to student.txt if is valid and not exist

  Params:      IN command - user_command struct    

  Returns:     Nothing
*/
int add_student()
{
  bool err_code = 0;
  student_data student;

  get_student_info(&student);

  err_code = verify_valid(student);

  if (err_code == 0)
  {
    FILE *f_ptr = fopen("/home/user/workspace/part3-task03/src/student.txt", "r");
    err_code = verify_student_code_exists(f_ptr, student.student_code);
    fclose(f_ptr);
  }

  if (err_code == 0)
  {
    FILE *f_ptr = fopen("/home/user/workspace/part3-task03/src/student.txt", "a");
    char age_as_str[4];
    sprintf(age_as_str, "%d", student.age);
    char *str_to_append = concat_and_format(
        student.student_code, student.f_name, student.l_name, age_as_str);

    err_code = append_to_file(f_ptr, str_to_append);
    fclose(f_ptr);
    free(str_to_append);
  }

  return err_code;
} /* add_student */

/*
  Name:        get_student_info

  Purpose:     Get info from user and store to student_data struct

  Params:      OUT student - student_data struct    

  Returns:     Nothing
*/
void get_student_info(student_data *student)
{
  printf("Student code: ");
  scanf("%s", student->student_code);
  printf("Name: ");
  scanf("%s", student->f_name);
  printf("Surname: ");
  scanf("%s", student->l_name);
  printf("Age: ");
  scanf("%d", &student->age);
} /* get_student_info */

/*
  Name:        verify_student_code_exists

  Purpose:     Based on student_code, verify if student exists in file

  Params:      IN code - student code from struct
               IN f_ptr - pointer to file where to verify     

  Returns:     0 if does not exist, -1 if file not found, -2 if student code is in file
*/
int verify_student_code_exists(FILE *f_ptr, char *code)
{
  char buffer[100];
  if (f_ptr == NULL)
  {
    printf("File does not exists or location is invalid.\n");
    return FILE_DOES_NOT_EXIST;
  }
  while ((fgets(buffer, 100, f_ptr)) != NULL)
  {
    buffer[5] = '\0';
    if (strcmp(code, buffer) == 0)
    {
      return STUDENT_CODE_ALREADY_IN_FILE;
    }
  }

  return SUCCESS;
} /* verify_student_code_exists */

/*
  Name:        append_to_file

  Purpose:     Append given string to the end of the given file

  Params:      IN f_ptr - pointer to file where to verify  
               IN str_to_append - string to appent to file   

  Returns:     -1 if file does not exist, 0 if string is appended
*/
int append_to_file(FILE *f_ptr, char *str_to_append)
{
  if (f_ptr == NULL)
  {
    printf("File does not exists or location is invalid.\n");
    return FILE_DOES_NOT_EXIST;
  }

  fputs(str_to_append, f_ptr);

  return SUCCESS;
} /* append_to_file */

/*
  Name:        concat_and_format

  Purpose:     Conact 4 strings

  Params:      IN s1 - code
               IN s2 - name
               IN s3 - surname
               IN s4 - age

  Returns:     Char pointer, meaning the concatenated string
*/
char *concat_and_format(const char *s1, const char *s2, const char *s3, const char *s4)
{
  int result_size = strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4) + 9;
  char *result = malloc(result_size);
  if (result == NULL)
  {
    printf("Not enought memory.\n");
    exit(EXIT_SUCCESS);
  }
  snprintf(result, result_size, "%s, %s, %s, %s\n", s1, s2, s3, s4);

  return result;
} /* concat_and_format */

/*
  Name:        verify_valid

  Purpose:     Verify input data from user

  Params:      IN student - student_data struct 

  Returns:     -3 if invalid data, else 0
*/
int verify_valid(student_data student)
{
  if (strlen(student.student_code) > 5 ||
      strlen(student.student_code) < 5 ||
      strlen(student.f_name) == 0 ||
      strlen(student.f_name) > 30 ||
      strlen(student.l_name) == 0 ||
      strlen(student.l_name) > 30 ||
      student.age < 1)
  {
    return PARAMETERS_INVALID;
  }

  return SUCCESS;
} /* verify_valid */

/*
  Name:        verify_grades

  Purpose:     Verify input data from user

  Params:      IN grades - student_grades struct 

  Returns:     -3 if invalid data, else 0
*/
int verify_grades(student_grades grades)
{
  if (strlen(grades.student_code) > 5 ||
      strlen(grades.student_code) < 5 ||
      grades.grade1 < 1 ||
      grades.grade1 > 10 ||
      grades.grade2 < 1 ||
      grades.grade2 > 10 ||
      grades.grade3 < 1 ||
      grades.grade3 > 10)
  {
    return PARAMETERS_INVALID;
  }

  return SUCCESS;
} /* verify_grades */

/*
  Name:        add_grades

  Purpose:     Get info from user and add student grades to grades.txt if is valid and not exist

  Params:      IN command - user_command struct    

  Returns:     Nothing
*/
int add_grades()
{
  bool err_code = 0;
  student_grades grades;

  get_student_grades(&grades);

  err_code = verify_grades(grades);

  if (err_code == 0)
  {
    FILE *f_ptr = fopen("/home/user/workspace/part3-task03/src/grades.txt", "r");
    err_code = verify_student_code_exists(f_ptr, grades.student_code);
    fclose(f_ptr);
  }

  if (err_code == 0)
  {
    FILE *f_ptr = fopen("/home/user/workspace/part3-task03/src/grades.txt", "a");

    char *str_to_append = concat_and_format(
        grades.student_code,
        grades_to_string(grades.grade1),
        grades_to_string(grades.grade2),
        grades_to_string(grades.grade3));

    err_code = append_to_file(f_ptr, str_to_append);
    fclose(f_ptr);
    free(str_to_append);
  }

  return err_code;
} /* add_grades */

/*
  Name:        get_student_grades

  Purpose:     Get info from user and store to student_grades struct

  Params:      OUT grades - student_grades struct    

  Returns:     Nothing
*/
void get_student_grades(student_grades *grades)
{
  printf("Student code: ");
  scanf("%s", grades->student_code);
  printf("Grade 1: ");
  scanf("%d", &grades->grade1);
  printf("Grade 2: ");
  scanf("%d", &grades->grade2);
  printf("Grade 3: ");
  scanf("%d", &grades->grade3);
} /* get_student_grades */

/*
  Name:        grades_to_string

  Purpose:     Get grade as an int and convert to string

  Params:      int grade - grade   

  Returns:     Converted to string grade, or 'NaG' if  integer is not a grade
*/
const char *grades_to_string(int grade)
{
  const char *grades[] = {"NaG", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
  if (grade > 0 && grade < 11)
  {
    return grades[grade];
  }

  return grades[0];
} /* grades_to_string */

/*
  Name:        view_graduated

  Purpose:     Store to grades.txt students with average >= 5

  Params:      Nothing

  Returns:     TODO
*/
int view_graduated()
{
  graduated_students_t graduated;
  int gr1, gr2, gr3;
  char buffer[100];
  char double_to_str[6];
  char student_code[6];
  double average;
  int ret_code;
  bool gradesf_exists = false;

  if (cfileexists("/home/user/workspace/part3-task03/src/graduate.txt"))
  {
    gradesf_exists = true;
  }

  FILE *f_grades = fopen("/home/user/workspace/part3-task03/src/grades.txt", "r");
  FILE *f_students = fopen("/home/user/workspace/part3-task03/src/student.txt", "r");
  FILE *f_graduated = fopen("/home/user/workspace/part3-task03/src/graduate.txt", "a+");

  if (f_grades == NULL || f_students == NULL || f_graduated == NULL)
  {
    printf("File grades.txt/students.txt/graduated.txt does not exists or location is invalid.\n");
    return FILE_DOES_NOT_EXIST;
  }

  while ((fgets(buffer, 100, f_grades)))
  {
    sscanf(buffer, "%[^,], %d, %d, %d",
           student_code,
           &gr1,
           &gr2,
           &gr3);
    average = (double)(gr1 + gr2 + gr3) / 3;
    if (average >= 5)
    {
      strcpy(graduated.student_code, student_code);
      graduated.average = average;
      ret_code = get_name_surname_by_student_code(f_students, graduated.student_code, graduated.f_name, graduated.l_name);

      sprintf(double_to_str, "%.2f", graduated.average);
      char *str_to_append = concat_and_format(
          graduated.student_code,
          graduated.f_name,
          graduated.l_name,
          double_to_str);

      if (ret_code == 0 && gradesf_exists)
      {
        ret_code = verify_student_code_exists(f_graduated, graduated.student_code);

        if (ret_code == 0)
        {
          ret_code = append_to_file(f_graduated, str_to_append);
        }
      }
      else if (ret_code == 0 && !gradesf_exists)
      {
        ret_code = append_to_file(f_graduated, str_to_append);
      }
      printf("%s", meaningful(ret_code));
    }
  }

  fclose(f_grades);
  fclose(f_students);
  fclose(f_graduated);
  return 0;
} /* view_graduated */

/*
  Name:        get_name_surname_by_student_code

  Purpose:     Using student_code, get student name and surname from input file

  Params:      IN f_ptr - input file pointer
               IN code - student_code
               OUT fname - first name
               OUT lname - last name

  Returns:     0 if succesed, else -1
*/
int get_name_surname_by_student_code(FILE *f_ptr, char *code, char *fname, char *lname)
{
  char student_code_tmp[6];
  char f_name_tmp[30];
  char l_name_tmp[30];
  char buffer[100];

  if (f_ptr == NULL)
  {
    printf("File does not exists or location is invalid.\n");
    return FILE_DOES_NOT_EXIST;
  }

  while ((fgets(buffer, 100, f_ptr)) != NULL)
  {
    sscanf(buffer, "%[^,], %[^,], %[^,]",
           student_code_tmp,
           f_name_tmp,
           l_name_tmp);
    if (strcmp(code, student_code_tmp) == 0)
    {
      strcpy(fname, f_name_tmp);
      strcpy(lname, l_name_tmp);
      return SUCCESS;
    }
  }

  return STUDENT_NOT_FOUND;
} /* get_name_surname_by_student_code */

/*
  Name:        cfileexists

  Purpose:     Check if a file exist using stat() function

  Params:      IN filename - input file name

  Returns:     1 if succesed, else 0
*/
int cfileexists(const char *filename)
{
  struct stat buffer;
  return !stat(filename, &buffer);
} /* cfileexists */

/*
  Name:        meaningful

  Purpose:     Describe errors

  Params:      IN error_type - error_type

  Returns:     String
*/
const char *meaningful(int error_type)
{
  switch (error_type)
  {
  case SUCCESS:
    return "Executed succesful!\n";
    break;
  case FILE_DOES_NOT_EXIST:
    return "File error, location is invalid or file does not exist!\n";
    break;
  case STUDENT_CODE_ALREADY_IN_FILE:
    return "Student if already in file!\n";
    break;
  case PARAMETERS_INVALID:
    return "Input parameters are invalid!\n";
    break;
  case STUDENT_NOT_FOUND:
    return "Student not found!\n";
    break;

  default:
    return "Unknown error!\n";
    break;
  }
} /* meaningful */

void printf_info()
{
  printf("Help support:\n"
         " 'h' - help\n"
         " 's' - s - add one student in `student.txt`\n"
         " 'g' - add grades in `grades.txt` for one student\n"
         " 'a' - create a file `graduate.txt` for students with average > 5\n"
         " 'x' - close the program\n");
}