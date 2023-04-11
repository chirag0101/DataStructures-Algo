#include<stdio.h>
int i_sort(int arr[],int size){

    for(int i=1;i<=size-1;i++){        //for sorted list
        int store=arr[i];
        int j=i-1;
        for(;j>=0 && store<arr[j];j--){    //for unsorted list
            arr[j+1]=arr[j];
        }
        arr[j+1]=store;
    }
    return 0;
}

int main(){
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    
    int arr[size];
    
    printf("\nEnter elements:");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    i_sort(arr,size);
    
    printf("\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}