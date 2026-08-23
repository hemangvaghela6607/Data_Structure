#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *head = NULL;

/* (a) Insert at front */
void insertFront() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &newnode->info);

    newnode->next = head;
    head = newnode;
}

/* (b) Insert at end */
void insertEnd() {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &newnode->info);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

/* (c) Insert in ascending order */
void insertAscending() {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &newnode->info);

    if (head == NULL || newnode->info < head->info) {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;

    while (temp->next != NULL &&
           temp->next->info < newnode->info) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

/* (d) Delete first node */
void deleteFirst() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted.\n");
}

/* (e) Delete last node */
void deleteLast() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Last node deleted.\n");
}

/* (f) Delete node before specified position */
void deleteBeforePosition() {
    int pos, i;
    struct node *temp, *del;

    if (head == NULL || head->next == NULL) {
        printf("Not enough nodes.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 1) {
        printf("No node exists before this position.\n");
        return;
    }

    if (pos == 2) {
        del = head;
        head = head->next;
        free(del);
        printf("Node before position %d deleted.\n", pos);
        return;
    }

    temp = head;

    for (i = 1; i < pos - 2 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL || temp->next->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;
    free(del);

    printf("Node before position %d deleted.\n", pos);
}

/* Display list */
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    do {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert in Ascending Order\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Node Before Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertFront();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                insertAscending();
                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                deleteBeforePosition();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 8);
}
