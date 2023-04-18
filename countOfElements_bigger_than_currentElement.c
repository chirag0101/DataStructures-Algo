//program to return total count of all elements if an element is bigger than the current element 
#include<stdio.h>
void main(){
    int arr[]={7,3,-2,1,4,5,1,4};
    int count=0;


    // bruteforce approach
    // for(int i=0;i<8;i++){
    //     for(int j=0;j<8;j++){
    //         if(arr[i]<arr[j]){
    //             count++;
    //             break;
    //         }
    //     }
    // }


    // optimised way
    // int max=arr[0];
    // for(int i=0;i<8;i++){
    //     if(arr[i]>max){
    //         max=arr[i];
    //     }
    // }
    // int max_count=0;
    // for(int i=0;i<8;i++){
    //     if(max==arr[i]){
    //         max_count++;
    //     }
    // }


    // same code for optimised way as time complexity of both of them is O(n)
    int max=arr[0];
    int max_count=0;
    for(int i=0;i<8;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]==max){
            max_count++;
        }
    }
    
    count=8-max_count;

    printf("%d\n",count);

}