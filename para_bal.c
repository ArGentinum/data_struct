#include <Stdio.h>
#include <String.h>
char stack[100],a[100],peek;
int top=-1;

void pop(){
--top;
}


void push(char x){
++top;
stack[top]=x;
}

int para_bal(int size){
int i;

while(i<size){
    if(a[i]=='['||a[i]=='('||a[i]=='{')
    push(a[i]);

else if(a[i]=='}'||a[i]==']'||a[i]==')'){
    if(top>=0){
        if((stack[top]-a[i])>=2){
            return 0;
        }
    }
else
return 0;
}

else 
pop();


++i;
}
}

int main(){
printf("enter the paranthesis expression:");
scanf("%s",a);
int size=strlen(a);

int check=para_bal(size);

if(check==0){
    puts("\nnot a balanced paranthesis expresssion!");

}

else
puts("\nvalid balanced paranthesis expresssion");


}