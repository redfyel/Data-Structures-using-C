//balanced parenthesis
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    char st[100];
    int top;
}s;

void push(char item){
    if(s.top==99)
        printf("Stack is full\n");
    else{
        s.top++;
        s.st[s.top]=item;
    }
}

void pop(){
    if(s.top==-1)
        printf("Stack is empty\n");
    else
        s.top=s.top-1;
}
int checkpair(char x,char y){
    return((x=='(' && y==')') || (x=='{'&& y=='}') || (x=='[' && y==']'));
}
int checkIfBalanced(char exp[], int n){
    for(int i=0;i<n;i++){
        if(exp[i]=='('|| exp[i]=='{'|| exp[i]=='['){
                push(exp[i]);
           }
        else{
            if(s.top==-1)
                return 0;
            else if(checkpair(s.st[s.top],exp[i])){
                pop();
                continue;
            }
            return 0;
        }
    }
    return 1;
}
int main(){
    char str[100];
    printf("Enter the expression: ");
    scanf("%s",str);
    int i=0;
    s.top=-1;
    int len =strlen(str);
    checkIfBalanced(str,len)?printf("Balanced Parenthesis"):printf("Unbalanced parenthesis");
    return 0;
}
