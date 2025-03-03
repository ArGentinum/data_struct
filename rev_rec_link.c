#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *head=NULL,*temp;

void insert(int data){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->link=head;
head=newnode;
}

void rec_print(struct node *p){
if (p==NULL){
    //printf("NULL");
  return;
}
else{
    rec_print(p->link);
    printf("%d->",p->data);
}
}

void main(){
    insert(10);
    insert(9);
    insert(8);
    insert(7);
    insert(6);
    temp=head;
    rec_print(temp);
}