/**
@author Saheb Singh Arora
Student id 3742233
*/
#include <stdio.h>
#include <stdlib.h>

void printArr(char a[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        putchar(a[i]);
    }
}

void reverseArr(char a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        char temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

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
    char num1[11], num2[11];
    int i = 0, j = 0;

    printf("Enter the first number (reversed): ");
    while ((num1[i++] = getchar()) != '\n');
    num1[i - 1] = '\0';

    printf("Enter the second number (reversed): ");
    while ((num2[j++] = getchar()) != '\n');
    num2[j - 1] = '\0';

    int sum = addReversedInt(num1, i - 1, num2, j - 1);

    printf("Result (reversed): ");
    char resultStr[11];
    int k = 0;
    while (sum != 0) {
        resultStr[k++] = (sum % 10) + '0';
        sum /= 10;
    }
    resultStr[k] = '\0';
    printArr(resultStr, k);
    printf("\n");

    printf("Result (reversed again): ");
    reverseArr(resultStr, k);
    printArr(resultStr, k);
    printf("\n");

   return EXIT_SUCCESS;
}
