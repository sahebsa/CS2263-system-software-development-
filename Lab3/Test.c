#include <stdio.h>

void printArrayTwice(int arr[], int size) {
    int *aptr = arr; 

    printf("index\tarray_element_value\taddress\t\tarray_element_value:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%p\t%d\n", i, arr[i], &arr[i], *aptr);
        aptr++; 
    }
}

int main() {
    int arr[] = {10, 11, 12, 13, 14, 15, 16};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArrayTwice(arr, size);

    return 0;
}
