#include<stdio.h>
int lOcc(int arr[],int size,int key){
    // int i=size-1;
    // while(i>=0){
    //     if(arr[i]==key){
    //         return i;
    //     }else{
    //         i--;
    //     }
    // }return -1;

    int i=0,x=-1;
    while(i<size){
        if(arr[i]==key){
            x=i;
        }
        i++;
    }
    return x;
}

int slOcc(int arr[],int size,int key){
     int i=0,x=-1,x2=-1;
    while(i<size){
        if(arr[i]==key){
            x2=x;
            x=i;
        }
        i++;
    }
    return x2;
}

int fOcc(int arr[],int size,int key){
    int i=0;
    while(i<size){
        if(arr[i]==key){
            return i;
        }else{
            i++;
        }
    }return -1;
}

int main(){
    int arr[]={1,2,3,4,5,2};
    int size=6;
    int key=5;
    int x=fOcc(arr,size,key);
    printf("%d\n",x);

    key=2;  
    int y=lOcc(arr,size,key);
    printf("%d\n",y);

    key=2;  
    int z=slOcc(arr,size,key);
    printf("%d\n",z);
    
    return 0;
}