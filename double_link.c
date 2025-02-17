#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *rptr;
    int data;
    struct node *lptr;
};

struct node *head = NULL, *temp, *lastnode = NULL;

void print() {
    temp = head;
    printf("\nNULL -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->rptr;
    }
    printf("NULL\n");
}

char insert() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    if (!newnode) {
        printf("Memory allocation failed!\n");
        return '\n';
    }

    printf("\nEnter data (press 'T' to terminate): ");

    if (scanf("%d", &newnode->data) != 1) {
        free(newnode);  // Prevent memory leak
        return '\n';  // Signal termination
    }

    newnode->rptr = NULL;

    if (head == NULL) {
        newnode->lptr = NULL;
        head = newnode;
    } else {
        lastnode->rptr = newnode;
        newnode->lptr = lastnode;
    }

    lastnode = newnode;
    return 'Y';  // Continue inserting
}

int main() {
    char enter, term;
    puts("Press Enter to start execution...");

    while (1) {
        scanf("%c", &enter);

        if (enter == '\n') {
            term = insert();
            if (term == '\n')
                break;
            print();
        } else {
            puts("Wrong key!\nTerminating program...");
            break;
        }
    }

    puts("\n\nFinal linked list:");
    print();

    return 0;
}
