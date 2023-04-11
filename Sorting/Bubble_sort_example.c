//unsolved
#include<stdio.h>

int main(){
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    
    int arr[size];
    printf("\nEnter elements:");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    b_sort(arr,size);
    
    printf("\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}