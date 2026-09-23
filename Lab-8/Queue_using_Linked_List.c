#include<stdio.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL,*newnode,*ptr;
int value;
void insert(){
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Queue Overflow.");
        return;
    }
    printf("Enter a Value:");
    scanf("%d",&value);
    newnode->data = value;
    newnode->next = NULL;
    if(front==NULL)
        front=rear=newnode;
    else{
        rear->next = newnode;
        rear=newnode;
    }
}
void del(){
    if(front==NULL)
        printf("Queue underflow.");
    else{
        ptr=front;
        printf("%d is deleted.",ptr->data);
        if(front==rear)
            front=rear=NULL;
        else
            front=front->next;
        free(ptr);
    }
}
void display(){
    if(front==NULL){
        printf("Queue is Empty.");
        return;
    }
    printf("\nQueue is: ");
    for(ptr=front;ptr!=NULL;ptr=ptr->next)
        printf("%d ",ptr->data);

}
void main(){
    int ch;
    while(1){
        printf("\nQueue using Linked List");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert();   break;
            case 2: del();  break;
            case 3: display();  break;
            case 4: exit(0);
            default: printf("Invalid Choice..");
        }
    }
}
