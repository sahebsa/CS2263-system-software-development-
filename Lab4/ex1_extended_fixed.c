/* ex1_extended_fixed.c */
#include <stdio.h>
#include <stdlib.h>
 
void dummy_frame()
{
  return;
}
 
int main(int argc, char * * argv)
{
  int i;
  int *a = (int *)malloc(5 * sizeof(int)); 
  if (a == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return EXIT_FAILURE;
  }
  
  printf("Original array:\n");
  for (i = 0; i < 5; i++) {
    a[i] = i + 1;
    printf("main: a[%d] = %d %p \n", i, a[i], &a[i]);
  }
  
  int *temp = (int *)realloc(a, 8 * sizeof(int));
  if (temp == NULL) {
    fprintf(stderr, "Memory reallocation failed\n");
    free(a);
    return EXIT_FAILURE;
  } else {
    a = temp;
  }
  
  for (i = 5; i < 8; i++) {
    a[i] = i + 1;
  }
  
  printf("\nExtended array:\n");
  for (i = 0; i < 8; i++) {
    printf("main: a[%d] = %d %p \n", i, a[i], &a[i]);
  }
  
  free(a);
  
  return EXIT_SUCCESS;
}
