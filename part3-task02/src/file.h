
/*
  Header:  string.h

  Purpose: Contains function declarations from file.c file
*/

#ifndef FILE_H
#define FILE_H

typedef struct statistic_t
{
  unsigned int words;
  unsigned int characters;
  unsigned int lines;
  unsigned int digits;  
} statistic;


void display_stats(statistic *stats);
void parse_file(FILE *f_ptr, statistic *stats);
#endif /* FILE_H */
