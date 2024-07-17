/**
@author Saheb Singh Arora
Student id: 3742233
*/
#include <stdio.h>

void printArr(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        putchar(arr[i]);
    }

}

int main() {
    int c;
    int inside_comment = 0;
    char tag[100]; 

    while ((c = getchar()) != EOF) {
        if (c == '<') {
            int i = 0;
            tag[i++] = c;
            while ((c = getchar()) != EOF && c != '>') {
                if (!(inside_comment)) { 
                }
                tag[i++] = c;
            }
            if (!inside_comment) {
                printArr(tag, i);
                putchar('>'); 
                putchar('\n');
            }
        }
    }

    return 0;
}
