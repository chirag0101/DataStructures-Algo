#include<stdio.h>
int arrRev(int arr[],int size){
    int i=0,j=size-1;
    int temp=0;
    while(i<=j){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        ++i;
        --j;
    }
    i=size-1;
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    arrRev(arr,5);
    return 0; 
}