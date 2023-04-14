#include<stdio.h>
int ipSearch(int arr[],int size,int key){
    int start=0,end=size-1,mid;
    mid=start+((key-arr[start])/(arr[end]-arr[start]))*(end-start);
    if(arr[mid]==key){
        return mid;
    }
    return -1;
}
void main(){
    int arr[]={1,3,5,7,9,11,13};
    int size=7;
    int key=9;
    printf("%d\n",ipSearch(arr,size,key));
}