include<stdio.h>        

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
