#include<stdio.h>
int findFactorial(int n){
    if(n==1)
            return 1;
    else if (n==0)
        return 1;
    else
       return n*findFactorial(n-1);
}

int main(){
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    int fact=findFactorial(num);
    printf("The factorial of %d is %d",num,fact);
    return 0;
}
