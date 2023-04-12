#include<stdio.h>        

int b_sort(int arr[],int size){
    int temp;
    
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                j=-1;
            }
        }

    return 0;
}

int merge(int arr1[],int arr2[],int arr3[],int size1,int size2){
    int i,j;
    for(int i=0;i<size1;i++){
            arr3[i]=arr1[i];
    }

    for(int i=0;i<size2;i++){
        for(int j=size1;j<size2+size1;j++){
            arr3[j]=arr2[i];
            i++;
        }
        break;
    }

    b_sort(arr3,size1+size2);
    return 0;
}
int main(){
    int size1;
    printf("Enter size:");
    scanf("%d",&size1);
    
    int arr1[size1];
    printf("\nEnter elements:");
    for(int i=0;i<size1;i++){
        scanf("%d",&arr1[i]);
    }

    b_sort(arr1,size1);
    
    int size2;
    printf("Enter size:");
    scanf("%d",&size2);
    
    int arr2[size2];
    printf("\nEnter elements:");
    for(int i=0;i<size2;i++){
        scanf("%d",&arr2[i]);
    }

    b_sort(arr2,size2);

    printf("\n");
    for(int i=0;i<size1;i++){
        printf("%d ",arr1[i]);
    }
    
    printf("\n");
    for(int i=0;i<size2;i++){
        printf("%d ",arr2[i]);
    }

    int arr3[size1+size2];
    merge(arr1,arr2,arr3,size1,size2);
    
    printf("\n");
    for(int i=0;i<size1+size2;i++){
        printf("%d ",arr3[i]);
    }

    return 0;
}