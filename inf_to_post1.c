#include <stdio.h>
#include <string.h>

void push(char);
void pop_till_open();
void pop_till_proper(char);
void pop_till_open();
void prec(char,char);
void output(char);
void pop_everything();
void parse(char);
void pop();
void inf_to_post();


char stack[100],inf[100],precedence[]={'^','0','/','*','0','-','+'};
int prec_size,inf_size,scan_prec,stack_prec;
int top=-1;





void main(){
    printf("enter the infix expresssion:");
    fgets(inf,sizeof(inf),stdin);
    inf_size=strlen(inf);
    prec_size=strlen(precedence);
    //printf("%d",inf_size);
    inf_to_post();
}

void output(char x){
    printf("%c",x);
}


void push(char x){
++top;
stack[top]=x;
}

void pop_till_open(){
while(stack[top]!='('){
    output(stack[top]);
    pop();
}
}

void pop_till_proper(char x){
output(stack[top]);
pop();
if(top==0)
push(x);

else
parse(char x);


}

void pop(){
--top;    
}



void prec(char stack_top,char scan_char){
    int i=0;
    while(i<prec_size){
        if(stack_top==precedence[i])
        stack_prec=i;

        if(scan_char==precedence[i])
        scan_prec=i;
    }

}

void pop_everything(){
while(top!=-1){
output(stack[top]);
pop();
}
}



void parse(char x){

    //if stack is empty push the operator
    if (top==-1)
    push(char x)

    prec(stack[top],x);
    //if scanned operator has higher prec than stack[top] operator,push[]
    else if(scan_prec-stack_prec>=2)
    push();

    else
    pop_till_proper();
}

}

void inf_to_post(){
    int i=0;
    while(i<inf_size){
        if((inf[i]>=65&&inf[i]<=90)||(inf[i]>=97&&inf[i]<=122))
        output(inf[i]);

        else if(inf[i]=='(')
        push(inf[i]);

        else if(inf[i]==')');
        pop_till_open();

        else
        parse(inf[i]);

        ++i;


    }

    if(top!=-1)
    pop_everything();
}


