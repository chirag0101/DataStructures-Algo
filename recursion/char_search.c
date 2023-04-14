#include<stdio.h>
// int findChar(char arr[],int size,char find){
//     for(int i=0;i<size;i++){
//         if(arr[i]==find){
//             return i;
//         }
//     }
// }
int findChar(char arr[],int size,char find){
    if(size==0){
        return -1;
    }
    if(arr[size]==find){
        return size;
    }
    return findChar(arr,size-1,find);
}
void main(){
    char arr[]={'A','B','C','D','E'};
    int size=5;
    char find='F';
    int x=findChar(arr,size,find);
    printf("%d ",x);
}