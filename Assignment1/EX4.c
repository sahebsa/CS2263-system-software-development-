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

int addReversedInt(char a[], int n, char b[], int m) {
    int num1 = convertInt(a, n);
    int num2 = convertInt(b, m);
    return num1 + num2;
}

int main() {
    char num1[] = {'3', '2', '1'};
    char num2[] = {'6', '5', '4'};
    int numDigits1 = sizeof(num1) / sizeof(num1[0]);
    int numDigits2 = sizeof(num2) / sizeof(num2[0]);

    int result = addReversedInt(num1, numDigits1, num2, numDigits2);
    printf("Sum: %d\n", result);

    return EXIT_SUCCESS;
}
