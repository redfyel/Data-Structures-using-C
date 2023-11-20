#include<stdio.h>
int binarySearecur(int a[],int low,int high,int target)
{
    int mid=(low+high)/2;
    if(a[mid]==target){
        return mid;
     if(target>a[mid])
        return binarySearecur(a,low=mid+1,high,target);
    else if(target<a[mid])
        return binarySearecur(a,low,high=mid-1,target);
    }
    else
       return -1;
    }
int main()
{
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements of array:");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nThe array elements are: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }

    int target;
    printf("\nEnter target to search");
    scanf("%d",&target);
    int res=-1;
    res=binarySearecur(a,0,n-1,target);
    if(res!=-1)
    {
        printf("Element found at %d index",res);
    }
    else
    {
        printf("Element not found");
    }

    return 0;

}
