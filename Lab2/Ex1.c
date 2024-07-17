/**
@author Saheb Singh Arora
Student id: 3742233
*/

#include <stdio.h>
#include <stdlib.h>
 
int g1(int a, int b)
{
   int c = (a + b) * b;
   printf("g1: %d %d %d\n", a, b, c);
   printf("    a's address is %p\n", (void*)&a);
   printf("    b's address is %p\n", (void*)&b);
   printf("    c's address is %p\n", (void*)&c);
   return c;
}
 
int g2(int a, int b)
{
   int c = g1(a + 3, b - 11);
   printf("g2: %d %d %d\n", a, b, c);
   printf("    a's address is %p\n", (void*)&a);
   printf("    b's address is %p\n", (void*)&b);
   printf("    c's address is %p\n", (void*)&c);
   return c - b;
}
 
int main(int argc, char* argv[])
{
   int a = 5;
   int b = 17;
   int c = g2(a - 1, b * 2);
   printf("main: %d %d %d\n", a, b, c);
   printf("    a's address is %p\n", (void*)&a);
   printf("    b's address is %p\n", (void*)&b);
   printf("    c's address is %p\n", (void*)&c);
   return EXIT_SUCCESS;
}
