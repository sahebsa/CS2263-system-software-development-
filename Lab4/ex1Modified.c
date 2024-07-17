// ex1_modified.c 

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
  
  for (i = 0; i < 5; i++) {
    a[i] = i + 1;
    printf("main: a[%d] = %d %p \n", i, a[i], &a[i]);
  }
  
  dummy_frame();
  
  free(a); 
  return EXIT_SUCCESS;
}