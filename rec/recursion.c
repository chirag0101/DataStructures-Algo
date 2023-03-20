#include<stdio.h>
int sum_of(int x){
    static int sum=0;
    sum=sum+x;
    if(x!=1){
        sum_of(--x);
    }
    return sum;
}
void fun(int x){
    printf("Hello ");
    if(x!=1){
        fun(--x);
        printf("Bye ");
    }
    
}
void main(){
    int a=sum_of(10);
    printf("%d ",a);
    fun(5);
}