
/* 
  Name:      file.c 

  Purpose:   File manipulation
*/

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/*
  Name:        display_stats

  Purpose:     Displays statistic struct

  Params:      IN stats - statistic struct             

  Returns:     Nothing
*/
void display_stats(statistic *stats)
{
  printf("\n");
  printf("Total characters = %d\n", stats->characters);
  printf("Total words      = %d\n", stats->words);
  printf("Total lines      = %d\n", stats->lines);
  printf("Total digits     = %d\n", stats->digits);
} /* display_stats */

/*
*/
void parse_file(FILE *f_ptr, statistic *stats)
{
  char ch;
  while ((ch = fgetc(f_ptr)) != EOF)
  {
    stats->characters++;

    if (ch == '\n' || ch == '\0')
    {
      stats->lines++;
    }

    if(isdigit(ch))
    {
      stats->digits++;
    }

    if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
    {
      stats->words++;
    }    
  }

  if (stats->characters > 0)
  {
    stats->words++;
    stats->lines++;
  }
} /* parse_file */
