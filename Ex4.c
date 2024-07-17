/**
@author Saheb Singh Arora
Student id 3742233
*/
#include <stdio.h>

int main() {
    int n = 20; 
    int fib[n]; 

    fib[0] = 0;
    fib[1] = 1;

    printf("Fibonacci Sequence (every second value of first %d values are as follows:\n", n);
    printf("%d\n", fib[0]);

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (i % 2 == 0) {
            printf("%d\n", fib[i]);
        }
    }

    return 0;
}
