//evaluate the postfix exp
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Stack{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack* createStack(unsigned capacity){
    struct Stack* stack =(struct Stack*) malloc(sizeof(struct Stack));
    if(!stack)
        return NULL;
    stack->top=-1;
    stack->capacity= capacity;
    stack->array=(int*)malloc(stack->capacity * sizeof(int));
    if(!stack->array)
        return NULL;
    return stack;
}

int isEmpty(struct Stack* stack){
    return stack->top==-1;
}

char peek(struct Stack * stack ){
    return stack->array[stack->top];
}

char pop(struct Stack * stack ){
    if(!isEmpty(stack))
       return stack->array[stack->top--];
    return '$';
}

void push(struct Stack * stack,char ope){
    stack->array[++stack->top]=ope;
}

int eval(char *exp){
    struct Stack* stack = createStack(strlen(exp));
    int i;
    if(!stack)
        return -1;
    for(i=0;i<strlen(exp);++i){
        if(isdigit(exp[i]))
            push(stack, exp[i]-'0');
        else{
            int op1=pop(stack);
            int op2= pop(stack);
            switch(exp[i]){
                case '+': push(stack,op2+op1);
                        break;
                case '-' : push(stack,op2-op1);
                        break;
                case '/' : push(stack,op2/op1);
                        break;
                case '*' : push(stack,op2*op1);
                        break;
                case '^' : push(stack,op2^op1);
                        break;
            }
        }
    }
    return pop(stack);
}

int main(){
    char input[100];
    printf("Enter the postfix expression: ");
    gets(input);
    printf("Solution : %d", eval(input));
    return 0;
}
