
/*
  Header:  string.h

  Purpose: Contains function declarations from file.c file
*/

#ifndef FILE_H
#define FILE_H
#include <stdbool.h>

typedef enum
{
  INITIAL = -2,
  EXIT,
  ADD_STUDENT,
  ADD_GRADES,
  SHOW_GRADUATED,
  HELP
} command_id;

typedef struct user_command_t
{
  command_id id;
  char student_code[9];
  char f_name[30];
  char l_name[30];
  int age;
  double grade1;
  double grade2;
  double grade3;
} user_command;

typedef struct student_data_t
{
  char student_code[6];
  char f_name[30];
  char l_name[30];
  int age;
} student_data;

typedef struct student_grades_t
{
  char student_code[6];
  int grade1;
  int grade2;
  int grade3;
} student_grades;

enum return_code
{
  PARAMETERS_INVALID = -3,
  STUDENT_CODE_ALREADY_IN_FILE,
  FILE_DOES_NOT_EXIST,
  SUCCESS
};


void reset(user_command *command);
int parse_command(const char *user_input, user_command *command);
void get_student_info(student_data *student);
int add_student();
int verify_student_code_exists(FILE *f_ptr, char *code);
int append_to_file(FILE *f_ptr, char *str_to_append);
char* concat_and_format(const char *s1, const char *s2, const char *s3, const char *s4);
int verify_valid(student_data student);
int verify_grades(student_grades grades);
void get_student_grades(student_grades *grades);
int add_grades();
const char *grades_to_string(int grade);
#endif /* FILE_H */
