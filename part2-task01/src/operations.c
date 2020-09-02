
/*
  Name:     operations.c                                                      
  
  Purpose:  Contains algorithms to be done with an array               
*/

#include "operations.h"
#include <stdio.h>

/*
  Name:        find_largest

  Purpose:     Find the largest element of the array

  Params:      IN    arr - array with int elements
               IN    size - size of the array

  Returns:     An integer representing the largest element of the array
*/
int find_largest(int arr[], int size)
{
  int largest_element = arr[0];

  for (int i = 1; i < size; ++i)
  {
    if (largest_element < arr[i])
    {
      largest_element = arr[i];
    }
  }

  return largest_element;
} /* find_largest */

/*
  Name:        display_arr

  Purpose:     To display array elements using recursion

  Params:      IN    arr - array with int elements
               IN    start - element index to be printed
               IN    size - size of the array

  Returns:     Nothing
*/
void display_arr(int arr[], int start, int size)
{
  if (start >= size)
    return;

  printf(" %d", arr[start]);

  display_arr(arr, start + 1, size);
} /* display_arr */

/*
  Name:        contains_digit_near_digit

  Purpose:     Verify if array contains digit next to digit

  Params:      IN    arr - array with int elements
               IN    size - size of the array

  Returns:     return true if the array contains a 3 next to another 3 somewhere, else false
*/
bool contains_digit_near_digit(int arr[], int size)
{

  int result = false;
  for (int i = 0; i < size - 1; ++i)
  {
    if ((arr[i] == DIGIT) && (DIGIT == arr[i + 1]))
    {
      result = true;
      break;
    }
  }

  return result;
} /* contains_digit_near_digit */

/*
  Name:        display_unique

  Purpose:     Print unique elements in the array;

  Params:      IN    arr - array with int elements
               IN    size - size of the array

  Description: Initial frequency of element is 0.
               Algorithm finds frequency of each element and if frequency > 0,
               breaks the loop and prints the element.
               
  Returns:     Nothing
*/
void display_unique(int arr[], int size)
{
  int ctr = 0;

  for (int i = 0; i < size; i++)
  {
    ctr = 0;
    for (int j = 0, k = size; j < k + 1; j++)
    {

      if (i != j)
      {
        if (arr[i] == arr[j])
        {
          ctr++;
          break;
        }
      }
    }
    if (ctr == 0)
    {
      printf("%d ", arr[i]);
    }
    
  }
  printf("\n");
} /* display_unique */

/*
  Name:        max_and_min

  Purpose:     Find maximum and minimum elements in array;

  Params:      IN    arr - array with int elements
               IN    size - size of the array

  Returns:     return a struct with 2 elements, first is the min and second is the max
*/
struct min_max min_and_max(int arr[], int size)
{
  struct min_max result;
  result.min = arr[0];
  result.max = arr[0];

  for (int i = 1; i < size; i++)
  {

    if (arr[i] > result.max)
    {
      result.max = arr[i];
    }

    if (arr[i] < result.min)
    {
      result.min = arr[i];
    }
  }

  return result;
} /* max_and_min */
