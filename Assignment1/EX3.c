/**
@author Saheb Singh Arora
Student id 3742233
*/
#include <stdio.h>
#include <stdlib.h>

int convertInt(char a[], int n) {
    int result = 0;
    int multiplier = 1;

    for (int i = 0; i < n; i++) {
        result += (a[i] - '0') * multiplier;
        multiplier *= 10;
    }

    return result;
}

int main() {
    char digits[] = {'3', '2', '1'};
    int numDigits = sizeof(digits) / sizeof(digits[0]);

    int result = convertInt(digits, numDigits);
    printf("Integer value: %d\n", result);

    return EXIT_SUCCESS;
}
