/**
@author Saheb Singh Arora
Student id 3742233
*/
#include <stdio.h>
#include <stdlib.h>

void printReversed(unsigned int n) {
    if (n == 0) {
        putchar('0');
        return;
    }

    while (n > 0) {
        int digit = n % 10; 
        putchar('0' + digit);
        n /= 10; 
    }
}

int main() {
    unsigned int number = 2263;
    
    printf("Original number: %u\n", number);
    printf("Reversed number: ");
    printReversed(number);
    printf("\n");

    return EXIT_SUCCESS;
}
