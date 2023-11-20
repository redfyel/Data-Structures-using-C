/*Binary search program using numbers*/
#include<stdio.h>
int binarysearch(int a[],int n,int target){
    int low=0;//points to lowest index
    int high=n-1;//points to highest index
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==target)
            return mid;
        if(target>a[mid])//eliminates the left side or elements lower than target
            low=mid+1;
        else            //moves to the left side of array
            high=mid-1;
    }
    return -1;//not found
}

int main(){
    int arr[100];
    int size;
    int find;
    printf("Enter size:");
    scanf("%d",&size);
    printf("Enter %d elements",size);
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("Enter element to search");
    scanf("%d",&find);
    int res=binarysearch(arr,size,find);
    if(res==-1)
        printf("Element not found");
    else
        printf("Element is present at %d index",res);
    return 0;
}
