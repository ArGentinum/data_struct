#include <Stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
    //double dat_2;
};

struct node *stack[50],*head=NULL,*temp;
int top=-1;
//struct node *top=NULL;

void push(struct node *x){
    ++top;
    stack[top]=x;
}

void pop(){
    --top;
}

void rev_link(){
    temp=head;
    while(temp!=NULL){
        push(temp);
        temp=temp->link;
    }


    head=stack[top];
    while(top>0){
        temp=stack[top];
        pop();
        temp->link=stack[top]; 
    }
    temp=temp->link;
    temp->link=NULL;
}


void insert(int x){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=head;
    head=newnode; 
}

void print(){
    temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->link;
    }
    printf("NULL");
}

void main(){
    //printf("%d,%d,%d\n%d",sizeof(stack),sizeof(p),sizeof(struct node),sizeof(head));
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    puts("original linked list:");
    print();
    rev_link();
    puts("\n\nlinked list after reversal:");
    print();
    //puts("\nlinked list after reversal\n");
    //print();
    /*while(top>=0){
    printf("\n%p",stack[top]);
    --top;
    */
    
}


