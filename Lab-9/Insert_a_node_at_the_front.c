#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;

void insert_front(int value)
{
    struct node *nn;

    nn = (struct node*)malloc(sizeof(struct node));

    nn->data = value;
    nn->prev = NULL;
    nn->next = start;

    if(start != NULL)
        start->prev = nn;

    start = nn;
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
        insert_front(value);
    }

    printf("\nDoubly Linked List:\n");
    display();

    return 0;
}
