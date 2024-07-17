#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listnode {
    struct listnode *next;
    char *tag;
} Node;

Node *head = NULL;
int totalAllocatedMemory = 0;

int isComment(const char *line) {
    return (line[0] == '<' && line[1] == '!' && line[2] == '-' && line[3] == '-');
}

Node *Node_construct(char *tag) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    new_node->next = NULL;
    new_node->tag = strdup(tag);
    if (new_node->tag == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return new_node;
}

void List_add(Node **head_ref, Node *n) {
    if (*head_ref == NULL) {
        *head_ref = n;
        return;
    }
    Node *current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = n;
}

int List_search(Node *head, Node *n) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->tag, n->tag) == 0)
            return 1;
        current = current->next;
    }
    return 0;
}

void List_print(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%s\n", current->tag);
        current = current->next;
    }
}

void freeMemory(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->tag);
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-m] <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int memory_tracking = 0;
    if (argc == 3 && strcmp(argv[1], "-m") == 0)
        memory_tracking = 1;

    FILE *file = fopen(argv[argc - 1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[BUFSIZ];
    while (fgets(line, sizeof(line), file)) {
        const char *start = line;
        while ((start = strchr(start, '<')) != NULL) {
            const char *end = strchr(start, '>');
            if (end == NULL)
                break;
            if (!isComment(start)) {
                int length = end - start + 1;
                char *tag = strndup(start, length);
                if (tag != NULL) {
                    Node *new_node = Node_construct(tag);
                    if (!List_search(head, new_node)) {
                        List_add(&head, new_node);
                        if (memory_tracking) {
                            totalAllocatedMemory += (sizeof(Node) + strlen(tag) + 1);
                            printf("Allocated %d bytes. Total allocated memory: %d bytes.\n", (int)(sizeof(Node) + strlen(tag) + 1), totalAllocatedMemory);
                        }
                    } else {
                        free(new_node->tag);
                        free(new_node);
                    }
                } else {
                    perror("Memory allocation failed");
                }
                start = end + 1;
            }
        }
    }
    fclose(file);

    List_print(head);
    freeMemory(head);

    return EXIT_SUCCESS;
}
