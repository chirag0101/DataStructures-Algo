#include<stdio.h>
void main(){
    int size;

    printf("Enter Size:");
    scanf("%d",&size);
    
    int arr[size];
    printf("\nEnter Elements:");
    
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("\n");
    
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                int temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
    for(int i=0;i<size;i++){
        printf("%d\n",arr[i]);
    }
}