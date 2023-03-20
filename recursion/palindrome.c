#include<stdio.h>
// int pal(char ch[],int size){
//     int i=0,j=size-1;
//     while(i<=j){
//         if(ch[i]==ch[j]){
//             i++;
//             j--;
//         }else{
//             return -1;
//         }
//     }
//     return 1;
// }
int pal(char ch[],int i,int j){
    if(ch[i]!=ch[j]){
        return -1;
    }
    if(i>=j){
        return 1;
    }
    if(ch[i]==ch[j]){
        return 1;
    }
}
void main(){
    char ch[]={'m','a','d','a','m'};
    int size=5;
    int x=pal(ch,0,5);
    printf("%d ",x);
}