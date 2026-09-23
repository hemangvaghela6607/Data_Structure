#include<stdio.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL,*ptr,*nn;
int value;
void push(){
    nn=(struct node*)malloc(sizeof(struct node));
    if(nn==NULL)
        printf("Stack Overflow.");
    else{
        printf("Enter a Value:");
        scanf("%d",&value);
        nn->data=value;
        nn->next = top;
        top=nn;
    }
}
void pop(){
    if(top==NULL)
        printf("Stack Underflow.");
    else{
        ptr=top;
        printf("%d is deleted.",top->data);
        top=top->next;
        free(ptr);
    }
}
void peep(){
    if(top==NULL)
        printf("Stack is Empty.");
    else
        printf("%d is Topmost Element.",top->data);
}
void display(){
    if(top==NULL)
        printf("Stack is Empty.");
    else{
        printf("Stack is: ");
        for(ptr=top;ptr!=NULL;ptr=ptr->next)
            printf("%d ",ptr->data);
    }
}
void main(){
    int choice;
    while(1){
            printf("\n\nStack using Linked List");
            printf("\n1. Push\n2. Pop\n3. Peep\n4. Display\n5. Exit");
            printf("\nEnter your choice:");
            scanf("%d",&choice);
            switch(choice){
                case 1: push();     break;
                case 2: pop();      break;
                case 3: peep();     break;
                case 4: display();  break;
                case 5: exit(0);
                default: printf("Invalid Choice..");
            }
    }
}
