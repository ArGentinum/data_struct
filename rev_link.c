#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

//global declaration
struct node *head=NULL,*prevnode=NULL,*nextnode,*temp;

void traverse_till_end(){
    nextnode=head;
    temp=head;
    while(temp->link!=NULL){
        temp=temp->link;
        nextnode->link=prevnode;
        prevnode=nextnode;
        nextnode=temp;
    }
    nextnode->link=prevnode;
    head=nextnode;
}

void print(){
    temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->link;
    }
    printf("NULL");
}

void insert_at_beg(int data){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->link=head;
head=newnode;
}

void revlink(){
    traverse_till_end();
    print();
}

int main(){
    //inserting data in the nodes at the beginning , every single time a function is called
    insert_at_beg(1);
    insert_at_beg(2);
    insert_at_beg(3);
    insert_at_beg(4);
    insert_at_beg(5);
    insert_at_beg(6);
    insert_at_beg(7);
    puts("original linked list:");
    print();
    
    //function call reverse the linked list
    printf("\nlinked list after reversal:\n");
    revlink();
}
