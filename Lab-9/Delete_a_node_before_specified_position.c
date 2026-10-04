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

void delete_before_position(int position)
{
    struct node *ptr, *del;

    if(start == NULL)
    {
        printf("List is Empty.");
        return;
    }

    if(position <= 1)
    {
        printf("Invalid Position.");
        return;
    }

    ptr = start;
	int i;
	
    for(i = 1; i < position; i++)
    {
        if(ptr == NULL)
        {
            printf("Invalid Position.");
            return;
        }

        ptr = ptr->next;
    }

    del = ptr->prev;

    if(del == NULL)
    {
        printf("No node before position.");
        return;
    }

    if(del->prev != NULL)
        del->prev->next = ptr;
    else
        start = ptr;

    ptr->prev = del->prev;

    printf("%d is deleted.\n", del->data);

    free(del);
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
    int n, value, position, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        insert_end(value);
    }

    printf("\nBefore Deletion:\n");
    display();

    printf("\n\nEnter position: ");
    scanf("%d", &position);

    delete_before_position(position);

    printf("\nAfter Deletion:\n");
    display();

    return 0;
}
