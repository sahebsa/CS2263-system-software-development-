#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x = -2;
    int arr[] = {0, 1, 2, 3, 4};
    int y = 15;

    printf("&x      = %p, &y      = %p\n", (void *)&x, (void *)&y);
    printf("&arr[0] = %p, &arr[4] = %p\n", (void *)&arr[0], (void *)&arr[4]);
    printf("x = %d, y = %d\n", x, y);

    for (int i = -1; i <= 7; i++) {
        printf("&arr[%d] = %p\n", i, (void *)&arr[i]);
    }

    arr[-1] = 7;
    printf("x = %d, y = %d\n", x, y);
    arr[5] = -23;
    printf("x = %d, y = %d\n", x, y);
    arr[6] = 108;
    printf("x = %d, y = %d\n", x, y);
    arr[7] = -353;
    printf("x = %d, y = %d\n", x, y);

    return EXIT_SUCCESS;
}
