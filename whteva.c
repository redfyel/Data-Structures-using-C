//stacks-all operations
#include<stdio.h>
#include<stdlib.h>
int size,top=-1;
int *a;

void push(){
    int data;
    printf("Enter value to insert: ");
    scanf("%d",&data);
    if(top==size-1)
        printf("Stack is full\n");
    else
        a[++top]=data;
}

void pop(){//O(1)
    if(top==-1)
        printf("Stack is empty, cannot pop");
    else{
        printf("%d is popped",a[top]);
        top--;
    }
}

void peek(){
    if(top==-1)
        printf("Stack is empty\n");
    else{
        printf("%d element is the top element\n", a[top]);
    }
}

void isEmpty(){
    if(top==-1)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}

void isFull(){
    if(top==size-1)
        printf("Stack is full\n");
    else
        printf("Stack is not full\n");
}

void display(){//O(n)
    if(top==-1)
        printf("Stack is empty");
    else{
        for(int i=0;i<=top;i++)
            printf("%d\n",a[i]);
    }
}

void count(){
    printf("Number of elements in stack : %d\n",top+1);
}

void main(){
    int choice;
    printf("Enter size of stack: ");
    scanf("%d",&size);
    a=(int*)malloc(sizeof(int)*size);
    while(1){
        printf("\nOption 1- push\n");
        printf("Option 2- pop\n");
        printf("Option 3- peek\n");
        printf("Option 4- isEmpty\n");
        printf("Option 5- isFull\n");
        printf("Option 6- Display\n");
        printf("Option 7- count\n");
        printf("\nEnter your choice[1-7]: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: peek();
                break;
            case 4: isEmpty();
                break;
            case 5: isFull();
                break;
            case 6: display();
                break;
            case 7: count();
                break;
            default: exit(0);
        }
    }
}

