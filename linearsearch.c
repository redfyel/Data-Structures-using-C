/*Program on linear search on numbers*/
#include<stdio.h>
int linsearch(int ar[],int size, int target){//function for lin search
    for(int i=0;i<size;i++){
        if(ar[i]==target)//sequential checking of entire list to find target
            return i;
    }
   return -1;
}
int main(){
    int a[100];
    int n;
    int target;
    printf("Enter no of elements");
    scanf("%d",&n);
    printf("Enter %d elements",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter element to find");
    scanf("%d",&target);
    int res=linsearch(a,n,target);
    if(res!=-1)
    printf("Element found at index-%d",res);
    else
        printf("Element not found");
    return 0;
}

