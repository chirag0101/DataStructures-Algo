#include<stdio.h>
//recursive:
// int power_fun(int a,int n){
//     if(n==0){
//         return 1;
//     }
//     if(n==1){
//         return a;
//     }
//     return a*power_fun(a,n-1);
// }

//recursive 2nd approach:
// int power_fun(int a,int n){
//     if(n==0){
//         return 1;
//     }
//     if(n%2==0){
//         return power_fun(a,n/2)*power_fun(a,n/2);
//     }else{
//         return power_fun(a,n/2)*power_fun(a,n/2)*a;
//     }
// }

//recursive 3rd approach:
int power_fun(int a,int n){
    if(n==0){
        return 1;
    }
    int x=power_fun(a,n/2);
    if(n%2==0){
        return x*x;
    }else{
        return x*x*a;
    }
}

// int power_fun(int a,int n){
//     int p=a;
//     for(int i=0;i<n-1;i++){
//         p=p*a;
//     }
//     return p;
// }


void main(){
    int a,n;
    printf("Enter Number:");
    scanf("%d",&a);

    printf("\nEnter Powerr:");
    scanf("%d",&n);

    printf("\nAnswer: %d ",power_fun(a,n));
}