#include<stdio.h>
int sum;
int mergesort(int arr[],int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        sum=sum+mid;        
    }
    return sum;
}
void main(){
    int arr[]={7,1,4,-5,-3,10,8,9,3,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,9);
    printf("%d",sum);
}