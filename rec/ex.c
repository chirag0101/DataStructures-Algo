#include<stdio.h>
int fun(int N){
    // if(N<=1){
    //     return 1;
    // }
    // int x=fun(N-1);
    // int y=fun(N-2);
    // printf("%d ",x);
    // printf("%d ",y);
    printf("%d ",N);
    if(N<=1){
        return 1;
    }
    return fun(N-1)+fun(N-2);
}
void main(){
    fun(3);
}