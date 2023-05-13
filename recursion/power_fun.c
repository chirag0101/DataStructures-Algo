#include<stdio.h>
int power_fun(int a,int n){
    int p=a;
    for(int i=0;i<n-1;i++){
        p=p*a;                 // =2*2,4*2,8*2,16*2
    }
    return p;
}
void main(){
    int a,n;
    printf("Enter Number:");
    scanf("%d",&a);

    printf("\nEnter Powerr:");
    scanf("%d",&n);

    printf("\nAnswer: %d ",power_fun(a,n));
}