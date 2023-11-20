//write the postfix expression from infix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[100];
char infix[100];
char postfix[100];
int top=-1;

void push(char c){
    if (top == 99){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

char pop(){
    char c;
    if (top == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}

int isEmpty(){
    if (top == -1)
        return 1;
    else
        return 0;
}

int precedence(char symbol){
    switch(symbol){
    case '^':
        return 3;
    case '*' :
    case '/' :
        return 2;
    case '+':
    case '-':
        return 1;
    default :
        return 0;
    }
}

void infix_to_postfix(){
    int j=0;
    char symbol,next;
    for(int i=0;i<strlen(infix);i++){
        symbol= infix[i];
        switch(symbol){
            case '(' : push(symbol);
                       break;
            case ')' :
                while((next = pop()) != '(')
                        postfix[j++]=next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                    postfix[j++]=pop();
                push(symbol);
                break;
            default : postfix[j++]=symbol;
        }
    }
    while(!isEmpty())
        postfix[j++]=pop();
    postfix[j]='\0';
}

void print(){
    int i=0;
    printf("\nThe postfix expression is: ");
    while(postfix[i])
        printf("%c", postfix[i++]);
    printf("\n");
}

int main(){
    printf("Enter the expression: ");
    gets(infix);
    infix_to_postfix();
    print();
    return 0;
}
