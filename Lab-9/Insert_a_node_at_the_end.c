#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;

void insert_end(int value)
{
    struct node *nn, *ptr;

    nn = (struct node*)malloc(sizeof(struct node));

    nn->data = value;
    nn->next = NULL;

    if(start == NULL)
    {
        nn->prev = NULL;
        start = nn;
        return;
    }

    ptr = start;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = nn;
    nn->prev = ptr;
}

void display()
{
    struct node *ptr = start;

    while(ptr != NULL)
    {
        printf("%d <--> ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        insert_end(value);
    }

    printf("\nDoubly Linked List:\n");
    display();

    return 0;
}
