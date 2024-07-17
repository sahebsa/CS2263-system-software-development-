#include <stdio.h>

int arrindex(int a[], int *p) {
    return p - a;
}

int main() {
    int arr[] = {10, 11, 12, 13, 14, 15, 16};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        printf("%d   %d\n", i, arrindex(arr, &arr[i]));
    }

    return 0;
}
