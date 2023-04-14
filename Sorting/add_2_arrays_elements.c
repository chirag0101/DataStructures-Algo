#include<stdio.h>        

int add_ele(int arr1[],int arr2[],int size){
    
        for(int i=0;i<size;i++){
            int sum=arr1[i]+arr2[i];
            arr2[i]=sum;
        }

    return 0;
}

int main(){
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    
    int arr1[size];
    printf("\nEnter elements:\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr1[i]);
    }

    int arr2[size];
    printf("\nEnter elements:\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr2[i]);
    }

    add_ele(arr1,arr2,size);
    
    printf("\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr2[i]);
    }
    
    return 0;
}