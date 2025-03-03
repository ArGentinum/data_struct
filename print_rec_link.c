#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *head=NULL,*prevnode,*temp;

void insert_at_end(int data){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->link=NULL;
if(head==NULL)
head=newnode;
else
prevnode->link=newnode;

prevnode=newnode;
}

void print_rec(){
if(temp==NULL){
    printf("NULL");
}

else{
    printf("%d->",temp->data);
    temp=temp->link;
    print_rec();
}
}

void main(){
    insert_at_end(1);
    insert_at_end(2);
    insert_at_end(3);
    insert_at_end(4);
    insert_at_end(5);
    temp=head;
    print_rec();

}