#include<stdio.h>
int sumArr(int arr[],int size){
    if(size==0){
        return arr[size-1];
    }
    return sumArr(arr,size-1)+arr[size-1];
}
void main(){
    int arr[]={10,20,30,40,50};
    int size=5;
    int sum=sumArr(arr,size);
    printf("%d ",sum);
}