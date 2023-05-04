#include<stdio.h>

void merge(int arr[],int start,int mid,int end){
    int ele1=mid-start+1;
    int ele2=end-mid;
    int arr1[ele1],arr2[ele2];

    for(int i=0;i<ele1;i++){            //adding arrays elements into divided sub arrays
        arr1[i]=arr[start+i];
    }
    for(int j=0;j<ele2;j++){
        arr2[j]=arr[mid+1+j];
    }

    int itr1=0,itr2=0,itr3=start;                 //sorting & merging 2 arrays
    while(itr1<ele1 && itr2<ele2){

        if(arr1[itr1]<arr2[itr2]){
            arr[itr3]=arr1[itr1];
            itr1++;
        }else{
            arr[itr3]=arr2[itr2];
            itr2++;
        }
        itr3++;

    }

    while(itr1<ele1){
        arr[itr3]=arr1[itr1];
        itr1++;
        itr3++;
    }

    while(itr2<ele2){
        arr[itr3]=arr2[itr2];
        itr2++;
        itr3++;
    }
}

void merge_sort(int arr[],int start,int end){
    int mid;
    if(start<end){
        mid=(start+end)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);      //dividing whole array until start<end
        merge(arr,start,mid,end);
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
    
    merge_sort(arr,0,size-1);      //merging 2 arrays + comparing both array elements so that elements are stored in sorted manner
    
    printf("\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
