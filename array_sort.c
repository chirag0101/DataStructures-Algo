#include<stdio.h>
void main(){
    int arr[]={2,1,4,5,6,7};
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if(arr[i]>arr[j]){
                int temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<6;i++){
        printf("%d\n",arr[i]);
    }
}