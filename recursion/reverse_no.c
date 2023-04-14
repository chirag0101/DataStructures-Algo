#include<stdio.h>
int revNum(int rem,int rev,int num){
    if(num!=0){
        // rem=num%10;
        // rev=rev*10+rem;
        return revNum(num%10,rev*10+(num%10),num/10);
    }return rev;
}
// int revNum(int num){
//     int rem,rev=0;
//     while(num>0){
//         rem=num%10;
//         rev=rev*10+rem;
//         num=num/10;
//     }
//     return rev;
// }
void main(){
    int num=321;
    printf("%d",revNum(0,0,num));
}