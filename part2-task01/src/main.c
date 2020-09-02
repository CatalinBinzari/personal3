
/* 
  Name:     main.c                                                            
  
  Purpose:  A C program that reads an array of integers 
            and call some algorithms 
*/


#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include <limits.h>

int main(int argc, char **argv)
{
  int array[MAX_SIZE] = {0};

  int size = 0;

  printf("Enter the size of an array\n");
  scanf("%d", &size);
 
  printf("Enter the array elements\n");
  for (int i = 0; i < size; i++) 
  {
    scanf("%d", &array[i]);
  }

  printf("Find largest: %d\n", find_largest(array, size));

  printf("Array of elements displayed: ");
  display_arr(array, 0, size);

  printf("\nUnique elements in the array are: ");
  display_unique(array, size);
  
  printf("Contain 3 near 3: %s\n", contains_digit_near_digit(array, size) ? "true" : "false");
  return 0;
} /* main */
