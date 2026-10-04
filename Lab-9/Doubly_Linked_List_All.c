//Doubly Linked List
#include<stdio.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start=NULL, *ptr=NULL, *preptr,*nn;
int value;
void create_dll(){
    printf("Enter -1 to stop; Enter a Value:");
    scanf("%d",&value);
    while(value!=-1){
        if(start==NULL){
            nn = (struct node*)malloc(1*sizeof(struct node));
            if(nn == NULL){
                printf("Memory Not Available");
                exit(0);
            }
            nn->data = value;
            nn->next = NULL;
            nn->prev = NULL;
            start=nn;
        }
        else
               insert_end(value);
        printf("Enter -1 to stop; Enter a Value:");
        scanf("%d",&value);
    }
}
void display(){
    if(start==NULL)
            printf("List is Empty.");
    else{
        for(ptr=start;ptr!=NULL;ptr=ptr->next)
                printf("%d <--> ",ptr->data);
    }
}

void insert_front(int value){
    nn = (struct node*)malloc(1*sizeof(struct node));
    if(nn == NULL){
        printf("Memory Not Available");
        exit(0);
    }
    nn->data = value;
    nn->prev = NULL;
    nn->next = start;
    if(start!=NULL)
        start->prev = nn;
    start = nn;
}


insert_end(int v){
    nn = (struct node*)malloc(1*sizeof(struct node));
    if(nn == NULL){
        printf("Memory Not Available");
        exit(0);
    }
    nn->data = v;
    nn->next = NULL;
    nn->prev = NULL;
    ptr=start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    nn->prev = ptr;
    ptr->next=nn;
}


void delete_first(){
    if(start==NULL){
        printf("List is Empty.");
        return;
    }
    ptr=start;
    printf("%d is deleted.",ptr->data);
    start=start->next;
    start->prev=NULL;
    free(ptr);
}


void delete_last(){
    if(start==NULL){
        printf("List is Empty.");
        return;
    }
    ptr=start;
    if(start->next==NULL){
        start=NULL;
        printf("%d is delete.",ptr->data);
        free(ptr);
    }
    else{
        while(ptr->next!=NULL){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=NULL;
        printf("%d is delete.",ptr->data);
        free(ptr);
    }
}





void delete_before_position(){
    int count,position;
    struct node *cur;
    if(start==NULL){
        printf("List is Empty.");
        return;
    }
    printf("Enter a Position:");
    scanf("%d",&position);
      if(position<=1){
        printf("Enter Valid position before to delete a Node.");
        return;
    }
   if(position==2){
        delete_first();
        return;
    }
    ptr=start;preptr=start;cur=start;
    for(count=1;cur!=NULL&&count<position;count++){
            preptr=ptr;
            ptr=cur;
            cur=cur->next;
    }
    preptr->next=cur;
    cur->prev=preptr;
    printf("%d is deleted.",ptr->data);
    free(ptr);
}

void main(){
    int ch;
    while(1){
        printf("\n\nDoubly Linked List");
        printf("\n1. Create a List\n2. Display\n3. Insert at Front");
        printf("\n4. Insert a Node at last");
        printf("\n5. Delete a First Node");
        printf("\n6. Delete a Last Node");
        printf("\n7. Delete a node before specified position");
        printf("\n8. Exit\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: create_dll();   break;
            case 2: display();  break;
            case 3: printf("Enter a Value:");
                    scanf("%d",&value);
                    insert_front(value);
                    break;
            case 4: printf("Enter a Value:");
                    scanf("%d",&value);
                    insert_end(value);
                    break;
            case 5: delete_first();  break;
            case 6: delete_last();  break;
            case 7: delete_before_position();   break;
            case 8: exit(0);
            default: printf("Invalid Choice..");
        }
    }
}
