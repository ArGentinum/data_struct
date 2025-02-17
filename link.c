#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int data;
    struct node *link;
};
struct node *head=NULL;
struct node *prev;


void str_to_arr(char c[],int size,int a[]){
    int i,j;
    char k;
    for(i=0;i<size;++i){
        for(j=0,k='0';j<=9;++j,++k){
            if(k==c[i]){
            a[i]=j;
            break;
            }
        }
    }
    /*for(i=0;i<size;++i)
    printf("%d",a[i]);*/
}

int arr_to_var(int arr[],int size){
    int var=0,i,ten=1;
    for(i=size-1;i>=0;--i,ten*=10){
        var+=ten*arr[i];
    }
    return var;


}

char insert(){
    char c[10000];
    int arr[10000],var,str_cnt=0;
    struct node *p=(struct node *)malloc(sizeof(struct node));
    printf("enter data(press enter to terminate):");
    fgets(c,sizeof(c),stdin);
    if(c[0]=='\n')
    return c[0];
    while(c[str_cnt]!='\n')
    ++str_cnt;
    str_to_arr(c,str_cnt,arr);
    var=arr_to_var(arr,str_cnt);
//printf("\n%d\n",var);
p->data=var;

if(head==NULL){
head=p;
}

else
prev->link=p;


p->link=NULL;
prev=p;
return 0;
}

void print(){
prev=head;
puts("\nlinked list:");
while(prev!=NULL){
    printf("%d->",prev->data);
    prev=prev->link;
}
printf("NULL");
}
int main(){
    char enter,term;
    printf("Instructions:\n1.press enter to start entering data\n2.press double enter to stop execution\n");
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
