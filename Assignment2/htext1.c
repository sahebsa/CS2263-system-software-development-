/**
@author Saheb Singh Arora
Student id: 3742233
*/
#include <stdio.h>
#include <stdbool.h>

int main() {
    int character;
    bool insideTag = false;
    bool insideComment = false;

    for (; ;) {
        character = getchar();
        if (character == EOF)
            break;

        if (character == '<') {
            insideTag = true;
            if ((character = getchar()) == '!') {
                if ((character = getchar()) == '-' && (character = getchar()) == '-') {
                    insideComment = true;
                    insideTag = false;
                    continue;
                } else {
                    ungetc(character, stdin);
                    character = '<';
                }
            } else {
                ungetc(character, stdin);
                continue;
            }
        }
        if (character == '>') {
            if (insideComment) {
                insideComment = false;
            } else {
                insideTag = false;
            }
            continue;
        }
        if (!insideTag && !insideComment) {
            putchar(character);
        }
    }
    return 0;
}
