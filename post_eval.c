#include <stdio.h>
#include <stdlib.h>
int stack[100],top=-1;
char exp[100];
void pop();
void push(char);
void eval(char);
void parse();
//int return_stack_top();
int char_to_int(char);
void int_push(int);

int main(){
    printf("enter the postfix expression:");
    scanf("%s",exp);
    parse();
}

void parse(){
    int i=0;
    while(exp[i]!='\0'){
        if(exp[i]>='0'&&exp[i]<='9')
        push(exp[i]);
    else
    eval(exp[i]);

++i;
    }

    printf("the result is %d",stack[top]);
}

void push(char x){
    int y=char_to_int(x);
    ++top;
    stack[top]=y;
}

void eval(char op){
int y=stack[top];
pop();
int x=stack[top];
pop();

switch(op){
    case '*':int_push(x*y);
    break;

    case '/':int_push(x/y);
    break;

    case '+':int_push(x+y);
    break;

    case '-':int_push(x-y);
    break;
}

printf("\nstack[top]=%d",stack[top]);
}

/*
int return_stack_top(){
return stack[top];
}
*/



void pop(){
    --top;
}

int char_to_int(char x){
return x-'0';
}

void int_push(int x){
++top;
stack[top]=x;
}