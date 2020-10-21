#include <stdio.h>
int main()
{
 int contestants[] = {3, 9, 27, 1000};

 printf("Contestants %d\n", contestants[4]);
 printf("Contestants %d\n", *(contestants + 4));
 printf("Contestants %d\n", *(4 + contestants));
  printf("Contestants %d\n", 4[contestants]);
 
 return 0;
}