#include<stdio.h>
int sum(int x){
    static int sum1=0;
    sum1=x+sum1;
    if(x!=1){
        sum(--x);
    }
    return sum1;
}
int main(){
    int x=sum(10);
    printf("%d",x);
}