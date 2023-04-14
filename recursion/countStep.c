#include<stdio.h>
// int countStep(int a){
//     int count;
//     while(a){
//         if(a%2==0){
//             a=a/2;
//         }else{
//             --a;
//         }
//         count++;
//     }
//     return count;
// }
int countStep(int a,int count){
    if(a!=0){
        if(a%2==0){
            count++;
            return countStep(a/2,count);
        }else{
            count++;
            return countStep(--a,count);
        }
    }
    return count;
}
void main(){
    int a=14;
    printf("%d",countStep(a,0));

}