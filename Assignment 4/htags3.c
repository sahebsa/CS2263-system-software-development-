#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 100

char **tags = NULL;
int tagsCount = 0;
int totalAllocatedMemory = 0;

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
            char *tag = (char *)malloc(length + 1);
            if (tag != NULL) {
                strncpy(tag, start, length);
                tag[length] = '\0';
                tagsCount++;
                tags = realloc(tags, tagsCount * sizeof(char *));
                tags[tagsCount - 1] = tag;
                totalAllocatedMemory += (length + 1);
                printf("Allocated %d bytes. Total allocated memory: %d bytes.\n", length + 1, totalAllocatedMemory);
            } else {
                printf("Memory allocation failed for tag: %s\n", start);
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

void freeMemory() {
    for (int i = 0; i < tagsCount; i++) {
        free(tags[i]);
    }
    free(tags);
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
    freeMemory();

    return 0;
}
