#include<stdio.h>
int refun(int arr[],int size){
    int start=0;
    int end=size-1;
    if(start<end){
        int mid=(start+end)/2;
        printf("mid: %d\n",mid);
        refun(arr,mid+1);
    }
    printf("Hello!\n");
}
void main(){
    int arr[]={7,2,4,1,9,6,5,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    refun(arr,size);
}