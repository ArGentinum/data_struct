#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *head=NULL,*temp,*lastnode=NULL;

void print(){
temp=head;
while(temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->link;
}
printf("NULL");
}

void del_at_beg(){
temp=head;
head=temp->link;
free(temp);
}

void del_at_end(){
//temp=head;
lastnode->link=NULL;
free(temp);
}

void del_at_n(){
//temp=head;
lastnode->link=temp->link;
free(temp);
}

void insert_at_beg(int data){
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->link=head;
head=newnode;
}

void traverse_till_key(int key,int node_count){
    temp=head;
    int count=1;
    while(temp->data!=key){
        lastnode=temp;
        ++count;
        temp=temp->link;
    }

    if (count==1)
     del_at_beg();

    if(count==node_count)
    del_at_end();
    
    if(count<node_count&&count!=1)
    del_at_n();

}

int count(){
    temp=head;
    int count;
    while(temp!=NULL){
        ++count;
        temp=temp->link;
        }
        return count;
}

int main(){
    int key,node_count;
    insert_at_beg(1);
    insert_at_beg(2);
    insert_at_beg(3);
    insert_at_beg(4);
    insert_at_beg(5);
    puts("linked list before deletion:");
    print();
    printf("\nenter the data of the node that is to be deleted:");
    scanf("%d",&key);
    node_count=count();
    traverse_till_key(key,node_count);
    puts("\n linked list after deletion:");
    print();

    }