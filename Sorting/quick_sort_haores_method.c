//for distinct elements

#include<stdio.h>        

void swap(int *ptr1,int *ptr2){
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}

int partition(int arr[],int start,int end){
    int pivot=arr[start];                           //pivot at start index in this method
    int i=start-1;
    int j=end+1;
    while(1){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j){
            return j;
        }
        swap(&arr[i],&arr[j]);
    }
}

void quick_sort(int arr[],int start,int end){
    if(start<end){
        int pivot=partition(arr,start,end);         //dividing whole array as 1st array contains array elements<pivot && pivot<array elements
        quick_sort(arr,start,pivot);
        quick_sort(arr,pivot+1,end);      
    }
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
    
    quick_sort(arr,0,size-1);                       //merging 2 arrays + comparing both array elements so that elements are stored in sorted manner
    
    printf("\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}