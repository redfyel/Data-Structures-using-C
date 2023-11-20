//linear search on strings
#include<stdio.h>
#include<string.h>
int stringlin(char s[][6],int n,char *tar){
    for(int i=0;i<n;i++){
        if(strcmp(s[i],tar)==0)
            return i;
    }
    return -1;
}

int main(){
    char s[][6]={"hey","ssup","tired","cool"};
    int size=sizeof(s)/sizeof(s[0]);
    char *tar;
    printf("Enter string to search");
    scanf("%s",tar);
    int res=stringlin(s,size,tar);
    if(res==-1)
    printf("String absent");
    else
        printf("String found at %d",res);
    return 0;
}
