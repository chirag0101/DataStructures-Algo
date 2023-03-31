#include<stdio.h>
int main(){
/*    int arr[]={10,20,30,40,50};
    for(int i=4;i>-1;i--){
        printf("%d ",arr[i]);
    }*/
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int start=0;
    int end=size;

    while(start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    for(int i=1;i<size+1;i++){
        printf("%d ",arr[i]);
        }
        return 0;
    }

