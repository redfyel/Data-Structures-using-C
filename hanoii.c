#include<stdio.h>
void hanoiTowers(int num,char source,char spare,char dest){
    if(num==1){
        printf("Move disc %d from %c to %c\n",num,source,dest);
        return ;
}
    else
        hanoiTowers(num-1,source,dest,spare);
        printf("Move disc %d from %c to %c\n",num,source,dest);
        hanoiTowers(num-1,spare,dest,source);
}
int main(){
    int n;
    char source='A',dest='C',spare='B';
    printf("Enter number of discs:");
    scanf("%d",&n);
    hanoiTowers(n,source,spare,dest);
    return 0;
}
