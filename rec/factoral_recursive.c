#include<stdio.h>
// int fact(int x){
//     int i=x;
//     int factorial=1;
//     while(i!=0){
//         factorial=factorial*i;
//         --i;
//     }
//     return factorial;
// }
int fact1(int a){
    int fact2=a;
    if(a!=1){
        fact2=fact1(--a)*fact2;
    }
    return fact2;
}
int main(){
    int f=fact1(5);
    printf("%d\n",f);
    return 0;
}