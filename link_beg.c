#include <stdio.h>
#include <stdlib.h> 
struct node{
    int data;
    struct node *link;
};
struct node *head=NULL,*temp;
char print(){
    temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->link;
        
    }
    printf("NULL\n");
    return '\n';

}
char insert(){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    printf("enter data(press T to terminate):");
    if(scanf("%d",&p->data)==1){
    if(head==NULL)
    p->link=NULL;
else
p->link=head;

head=p;

}
else
return 'F';
}
int main(){
    char term,enter;
    printf("instructions:\n1.press enter to start\n");
    while(1){
        enter=fgetc(stdin);
        if(enter=='\n')
        term=insert();
        
    if(term=='F')
    break;
print();
        //if (term=='\n');
}
puts("\n\nfinal linked list:");
print();
}