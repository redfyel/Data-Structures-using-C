//stacks- linked lists
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top;
int count;

void push(){
    int value;
    struct node *temp;
    temp= (struct node*)malloc(sizeof(struct node));
    printf("Enter value to insert: ");
    scanf("%d",&value);
    temp->data=value;
    if(top==NULL){
        temp->next=NULL;
    }
    else{
        temp->next=top;
    }
    top=temp;
    count++;
}

void pop(){
    if(top==NULL)
        printf("Stack is empty\n");
    else if(top->next!=NULL){
        struct node *p;
        p=top;
        printf("%d is removed from stack\n",top->data);
        top=top->next;
        free(p);
        count--;
    }
    else{//single node
        struct node *p;
        p=top;
        printf("%d is removed from stack\n",top->data);
        top=NULL;
        free(p);
        count--;
    }
}

void peek(){
    if(top==NULL)
        printf("Stack is empty\n");
    else
        printf("%d is top element in stack\n",top->data);
}

void isEmpty(){
    if(top==NULL)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}

void display(){
    if(top==NULL)
        printf("Stack is empty\n");
    else{
        struct node *p;
        p=top;
        while(p->next!=NULL){
            printf("%d->",p->data);
            p=p->next;
        }
        printf("%d\n",p->data);
    }
}

void total(){
    if(top==NULL)
        printf("Stack is empty\n");
    else
        printf("Count: %d\n",count);
}
void main(){
    int choice;
    while(1){
        printf("Option 1- push\n");
        printf("Option 2- pop\n");
        printf("Option 3- peek\n");
        printf("Option 4- isEmpty\n");
        printf("Option 5- Display\n");
        printf("Option 6- count\n");
        printf("\nEnter your choice[1-6]: ");
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
            case 5: display();
                break;
            case 6: total();
                break;
            default: exit(0);
        }
    }
}
