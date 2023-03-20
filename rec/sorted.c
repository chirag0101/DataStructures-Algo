#include<stdio.h>
// int sorted(int arr[], int size){
//     for(int i=0;i<size-2;i++){
//         if(arr[i]>arr[i+1]){
//             return 1;
//         }
//     }
//     return -1;
// }
int sorted(int arr[],int index, int size){
    if(index<=size){
            return arr[index]<arr[index+1] && sorted(arr,index+1,size);
    }return -1;
}
void main(){
    int arr[]={1,2,3,4,5};
    int size=5;
    printf("%d ",sorted(arr,0,size));
    int arr1[]={1,3,2,4,5};
    printf("%d",sorted(arr1,0,size));
}