
/*
  Header:  operations.h

  Purpose: contains function declarations from operations.c file
*/

#ifndef OPERATIONS_H
#define OPERATIONS_H


#include <stdbool.h>

#define TRUE  1
#define FALSE 0
#define MAX_SIZE 20
#define DIGIT 3

struct min_max
{
    int min;
    int max;
};

int find_largest(int arr[], int size);
void display_arr(int arr[], int start, int size);
bool contains_digit_near_digit(int arr[], int size);
void display_unique(int arr[], int size);
struct min_max min_and_max(int arr[], int size);

#endif /* OPERATIONS_H */
