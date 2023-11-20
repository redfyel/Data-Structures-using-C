//linear search on characters
#include<stdio.h>
#include<string.h>
//int charlin(char [],int , char);
int charlin(char a[],int n,char *target){
    for(int i=0;i<n;i++){
        if(a[i]==target)
            return i;
    }
    return -1;
}
int main(){
    char arr[100];
    int size;
    char *search;
    printf("Enter size of your char array ");
    scanf("%d",&size);
    printf("Enter %d characters ",size);
    for(int i=0;i<size;i++)
        scanf("%c",&arr[i]);
    printf("Enter char to search ");
    getc(search);
    int res=charlin(arr,size,search);
    if(res!=-1)
        printf("Element found at %d index",res);
    else
        printf("Element is not present");
    return 0;
}

