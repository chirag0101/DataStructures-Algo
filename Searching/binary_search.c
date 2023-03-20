#include<stdio.h>
int bSearch(int arr[],int size,int key){
    int start=0,end=size-1,mid;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]<key){
            start=mid+1;
        }else if(arr[mid]>key){
            end=mid-1;
        }
    }
    return -1;
}
void main(){
    int arr[]={3,7,11,13,14,17,19,25,35,50};
    int size=10;
    int key=20;
    printf("%d\n",bSearch(arr,size,key));
}