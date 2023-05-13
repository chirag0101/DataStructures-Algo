#include<stdio.h>
void counting_sort(int arr[],int size){
    int max=arr[0];
    for(int i=1;i<size;i++){
        if(max<arr[i]){
            max=arr[i];
        }

        int countArr[max+1];
        
        for(int i=0;i<=max;i++){
            countArr[i]=0;
        }
    
        for(int i=0;i<size;i++){
            countArr[arr[i]]++;
        }

        for(int i=1;i<=max;i++){
            countArr[i]=countArr[i]+countArr[i]-1;
        }

        int op[size];

        for(int i=size-1;i>=0;i++){
            op[countArr[arr[i]]-1]=arr[i];
            countArr[arr[i]]--;
        }

        for(i=0;i<size;i++){
            arr[i]=op[i];
        }
    }
}
void main(){
    
    int arr[]={3,7,2,1,8,2,5,2,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    counting_sort(arr,size);

    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}