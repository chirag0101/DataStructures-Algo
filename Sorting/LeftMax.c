//LeftMaxArray - Creating new array of max elements created from max element of left side of the current element in 1st array
#include<stdio.h>
int main(){
    int arr[]={5,2,1,-4,-2,9,3,4};
    int leftMax[9];
    int maxElement=0;

    //bruteforce approach
    // for(int i=0;i<9;i++){
    //     maxElement=arr[i];
    //     for(int j=0;j<=i;j++){
    //         if(maxElement<arr[j]){
    //             maxElement=arr[j];
    //         }
    //     }
    //     leftMax[i]=maxElement;
    // }


    //optimised code
    for(int i=0;i<9;i++){
        if(i==0){
            leftMax[0]=arr[0];
        }else{
            maxElement=leftMax[i-1];
            if(maxElement<=arr[i]){
                leftMax[i]=arr[i];
            }else{
                leftMax[i]=maxElement;
            }
        }
    }

    for(int i=0;i<9;i++){
        printf("%d ",leftMax[i]);
    }
}