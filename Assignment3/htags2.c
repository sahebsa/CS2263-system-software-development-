/**
@author Saheb Singh Arora
Student id: 3742233
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAGS 100
#define MAX_TAG_LENGTH 100

char tags[MAX_TAGS][MAX_TAG_LENGTH];
int tagsCount = 0;

int isComment(const char *line) {
    return (line[0] == '<' && line[1] == '!' && line[2] == '-' && line[3] == '-');
}

void extractTags(const char *line) {
    const char *start = line;
    while ((start = strchr(start, '<')) != NULL) {
        const char *end = strchr(start, '>');
        if (end == NULL)
            break;
        if (!isComment(start)) {
            int length = end - start + 1;
            if (length < MAX_TAG_LENGTH) {
                strncpy(tags[tagsCount++], start, length);
                tags[tagsCount - 1][length] = '\0';
            }
        }
        start = end + 1;
    }
}

void printUniqueTags() {
    for (int i = 0; i < tagsCount; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (strcmp(tags[i], tags[j]) == 0)
                break;
        }
        if (i == j)
            printf("%s\n", tags[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char line[BUFSIZ];
    while (fgets(line, sizeof(line), file)) {
        extractTags(line);
    }
    fclose(file);

    printUniqueTags();

    return 0;
}