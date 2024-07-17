/**
@author Saheb Singh Arora 
Student id 3742233
*/
#include <stdio.h>

unsigned long long calcTrib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;
    else {
        unsigned long long a = 0, b = 0, c = 1, next;
        for (int i = 3; i <= n; ++i) {
            next = a + b + c;
            a = b;
            b = c;
            c = next;
        }
        return c;
    }
}

int main() {
    int n = 0;
    unsigned long long trib;

    for (int i = 0; i < 10; ++i) {
        trib = calcTrib(n);
        printf("Tribonacci(%d) = %llu\n", n, trib);
        n += 2; 
    }

    return 0;
}
