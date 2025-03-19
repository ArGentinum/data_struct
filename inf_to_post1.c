#include <stdio.h>
#include <string.h>

void push(char);
void pop_till_open();
void pop_till_proper(char);
void precedence(char, char);
void output(char);
void pop_everything();
void parse(char);
void pop();
void inf_to_post();

char stack[100], inf[100];
int top = -1;

// Function to determine precedence of operators
int get_precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;  // Exponentiation has the highest precedence
        default: return -1;  // Lower precedence for non-operators
    }
}

void main() {
    printf("Enter the infix expression: ");
    scanf("%s", inf);
    inf_to_post();
}

void output(char x) {
    printf("%c", x);
}

void push(char x) {
    stack[++top] = x;
}

void pop() {
    if (top != -1) 
        --top;
}

void pop_till_open() {
    while (top != -1 && stack[top] != '(') {
        output(stack[top]);
        pop();
    }
    if (top != -1) pop();  // Remove '(' from stack
}

void pop_till_proper(char scanned_char) {
    while (top != -1 && get_precedence(stack[top]) >= get_precedence(scanned_char)) {
        output(stack[top]);
        pop();
    }
    push(scanned_char);
}

void pop_everything() {
    while (top != -1) {
        output(stack[top]);
        pop();
    }
}

void parse(char scanned_char) {
    if (top == -1 || stack[top] == '(') {
        push(scanned_char);
        return;
    }

    if (get_precedence(scanned_char) > get_precedence(stack[top])) {
        push(scanned_char);
    } else {
        pop_till_proper(scanned_char);
    }
}

void inf_to_post() {
    int i = 0;
    while (inf[i] != '\0') {
        // If operand, output directly
        if ((inf[i] >= 'A' && inf[i] <= 'Z') || (inf[i] >= 'a' && inf[i] <= 'z')) {
            output(inf[i]);
        }
        // If opening parenthesis, push to stack
        else if (inf[i] == '(') {
            push(inf[i]);
        }
        // If closing parenthesis, pop until '('
        else if (inf[i] == ')') {
            pop_till_open();
        }
        // If operator, check precedence and push/pop accordingly
        else {
            parse(inf[i]);
        }
        i++;
    }

    // Pop remaining operators
    pop_everything();
}
