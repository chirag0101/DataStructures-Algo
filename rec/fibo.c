#include<stdio.h>
// void fibo(int x){
//     int a=0,b=1,c=0;
//     printf("%d %d ",a,b);
//     for(int i=2;i<x;i++){
//         c=a+b;
//         printf("%d ",c);
//         a=b;
//         b=c;
//     }
// }
int fibo(int x){
    if(x==0){
        return 0;
    }
    if(x==1){
        return 1;
    }
    return fibo(x-1)+fibo(x-2);
}
void main(){
    int x=fibo(10);
    printf("%d ",x);

}