/**
@author Saheb Singh Arora
Student id 3742233
*/

#include <stdio.h>
#include <stdlib.h>

void printArr(char a[], int n) {
    for (int i = 0; i < n; i++) {
        putchar(a[i]);
    }
}

int main() {
    char hello[] = "Hello, World!\n";
    int length = sizeof(hello) / sizeof(hello[0]); 
    
    printArr(hello, length);

    return EXIT_SUCCESS;
}
