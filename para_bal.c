#include <stdio.h>
#include <stdlib.h>
char stack[100],str[100];
int size,top=-1;

void push(char x){
    ++top;
    stack[top]=x;
}

void pop(){
    --top;
}

int para_bal(){
    int i=0;
    while(i<size){
    if(str[i]=='('||str[i]=='['||str[i]=='{'){
        push(str[i]);
    }
    
   else if(str[i]=='}'||str[i]==')'||str[i]==']'){
        if((str[i]-stack[top])>2||(str[i]-stack[top])<1||top==-1)
        return -1;
        
        else 
        pop();
   }
    
    ++i;
    }
    if(top!=-1)
    return -1;
    
    return 0;
}

/*
void print(){
    
}
*/

int main(){
    printf("enter the paranthesis expression:");
    scanf("%s",str);
    size=sizeof(str);
    para_bal();
    int cond_check=para_bal();
    if(cond_check==-1)
    printf("not a valid parathesis expresssion!");
    
    else if(cond_check==0)
    printf("valid paranthesis expression!");
    
}
