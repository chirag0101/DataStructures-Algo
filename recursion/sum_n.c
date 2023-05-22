#include<stdio.h>
int sum_n(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return n;
    }
    return n+sum_n(n-1);
}
void main(){
    int ip;
    printf("Enter the ip:");
    scanf("%d",&ip);
    printf("\n%d",sum_n(ip));
}