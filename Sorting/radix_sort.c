#include<stdio.h>
void countingSort(int arr[],int size,int pos){
    
    int countArr[10]={0};   //initilizes all elements of the array to 0
    
    for(int i=0;i<size;i++){
        countArr[(arr[i]/pos)%10]++;
    }

    for(int i=1;i<10;i++){
        countArr[i]=countArr[i]+countArr[i-1];
    }

    int op[size];

    for(int i=size-1;i>=0;i--){
        op[countArr[(arr[i]/pos)%10]-1]=arr[i];
        countArr[(arr[i]/pos)%10]--;
    }

    for(int i=0;i<size;i++){
        arr[i]=op[i];
    }
    
}
void radix_sort(int arr[],int size){

    int max=arr[0];
    for(int i=0;i<size;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    int cnt=0;
    
    while(max){
        max=max/10;
        cnt++;
    }

    for(int pos=1;max/pos>0;pos=pos*10){
        countingSort(arr,size,pos);
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
        }   
        printf("\n");
    }


}
void main(){
    
    int arr[]={235,5,12,3,470,313,65,20};
    int size=sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    radix_sort(arr,size);

    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}