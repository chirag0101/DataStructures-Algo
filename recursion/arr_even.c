#include<stdio.h>
#include<stdbool.h>
// int verify(int arr[],int size){
//     int count=0;
//     for(int i=0;i<size;i++){
//         if(arr[i]%2==0){
//             count++;
//         }
//     }
//     if(count>=2){
//             return 1;
//         }else{
//             return -1;
//         }
// }
int verify(int arr[],int size,int count){
    if(arr[size]%2==0){
        count++;
        if(count>=2){
            return 1;
        }else{
            return verify(arr,size-1,count);
        }
    }
   
}

void main(){
    int arr[]={1,3,4,5};
    int size=4;
    printf("%d",verify(arr,size,0));
}