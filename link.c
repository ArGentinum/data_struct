//code needs to be improved...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int data;
    struct node *link;
};
struct node *head=NULL;
struct node *prev;

char insert(){
    char c;
    struct node *p=(struct node *)malloc(sizeof(struct node));
    printf("enter data(press enter to terminate):");
    scanf("%c",&c);
    if(c=='\n')
    return c;
else{
p->data=c;
if(head==NULL){
head=p;
}

else
prev->link=p;
}

p->link=NULL;
prev=p;
return 0;
}

void print(){
prev=head;
puts("\nlinked list:");
while(prev!=NULL){
    printf("%c->",prev->data);
    prev=prev->link;
}
printf("NULL");
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
        else
        printf("wrong instruction!read instruction\n");
    }
    print();
}

