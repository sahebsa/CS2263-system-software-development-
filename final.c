#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodelist {
    struct nodelist *next;
    char *data;
} Node;

Node* genNode(char *data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Error creating a new node.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = strdup(data);  
    newNode->next = NULL;
    return newNode;
}

Node* linkedListArgv(int argc, char** argv) {
    if (argc == 0) {
        return NULL;
    }

    Node *head = genNode(argv[0]);
    Node *current = head;
    int i = 1; 

    while (i < argc) { 
        current->next = genNode(argv[i]);
        current = current->next;
        i++; 
    }

    return head;
}

int main(int argc, char** argv) {
    Node* argvList = linkedListArgv(argc, argv);
    
    printf("%s\n", argv[0]);       // Print the original first argument
    printf("%s\n", argvList->data); // Print the first argument from the list

    // Free the linked list
    Node* temp;
    while (argvList != NULL) {
        temp = argvList;
        argvList = argvList->next;
        free(temp->data);  // Free the duplicated string
        free(temp);        // Free the node
    }

    return 0;
}