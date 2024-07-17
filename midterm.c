/**
@author Saheb Singh Arora
Student id: 3742233
*/
#include <stdio.h>

void noVowels(char s[]) {
    int i, j;

    for (i = 0, j = 0; s[i] != '\0'; i++) {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0'; 
}

