#include <stdio.h>
#include <string.h>
int top=-1;
char stack[100];

void push(char x){
    ++top;
    stack[top]=x;
}

void pop(){
    --top;
}

void str_rev(int size,char *str){
    int i=0;
    while(i<size){
        push(str[i]);
        ++i;
    }
    i=0;
    while(top>=0){
        str[i]=stack[top];
        pop();
        ++i;
    }
}

void print_rev(char *str,int size){
    int i=0;
    while(i<size){
        printf("%c",str[i]);
        ++i;
    }
}

int main(){
    char str[]="aeiouAEIOU";
    int size=strlen(str);
    str_rev(size,str);
    print_rev(str,size);
}
