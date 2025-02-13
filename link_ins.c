#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *head=NULL;
struct node *lastnode,*prev,*temp;
short count=0;


void insert_at_beg(struct node *p){
    p->link=head;
    head=p;
}

void insert_at_end(struct node *p){
    lastnode->link=p;
    p->link=NULL;
    lastnode=p;
}


void traverse(int pos){
    temp=head;
    int i=1;
    while(i<pos){
      prev=temp;
    temp=temp->link;
    ++i;
    }
}
void insert_at_n(struct node *p,int pos){
    traverse(pos);
    prev->link=p;
    p->link=temp;
    //prev=temp;
}

char insert(){
    int pos;
    struct node *p=(struct node *)malloc(sizeof(struct node));
    if(count==0)
    printf("enter data for first node(press T to terminate):");
    else
    printf("\nenter data(press T to terminate):");
    if(scanf("%d",&p->data)==1)
    {
        ++count;
        printf("available positions:1-%d\nenter the position to insert the node at:",count);
        scanf("%d",&pos);
        
        if(pos>count)
        return '\n';
        
        if(head==NULL){
        head=p;
        lastnode=head;
        p->link=NULL;
        }
        
        if(pos==1)
        insert_at_beg(p);
        
        if(pos==count)
        insert_at_end(p);
        
        if(pos<count&&pos!=1)
        insert_at_n(p,pos);
        
        
        
        return 0;
}
else
return '\n';
}

void print(){
prev=head;
puts("\nlinked list:");
while(prev!=NULL){
    printf("%d->",prev->data);
    prev=prev->link;
}
printf("NULL\n");
}
int main(){
    char enter,term;
    printf("Instructions:\npress enter to start entering data\n");
    while(1){
        scanf("%c",&enter);
        if(enter=='\n'){
        term=insert();
        if(term=='\n')
        break;
        }
        else{
        printf("wrong instruction!read instruction\n");
        break;
        }
        print();
        
    }
    puts("final linked list:");
    print();
}