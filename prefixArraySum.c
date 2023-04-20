//prefix sum problem for a given range , prefix sum: prefix sum of prev element of current element + current element 
#include<stdio.h>
void main(){
    int arr[]={-7,11,21,-4,-3,5,8,2,-12};
    int queries;
    int psum[9];
    printf("Enter no. of queries:");
    scanf("%d",&queries);
    psum[0]=arr[0];    

    for(int j=1;j<9;j++){
        psum[j]=psum[j-1]+arr[j];
    }

    int start=0,end=0,sum=0;

    for(int i=0;i<queries;i++){
        printf("\nEnter Start:");
        scanf("%d",&start);
        printf("\nEnter End:");
        scanf("%d",&end);
        
        if((start==0)||(start==end)){
            printf("\n%d",psum[end]);
        }else{
            for(int j=start;j<=end;j++){
                sum=psum[end]-psum[start-1];
            }       
        printf("\n%d",sum);
        }
    }
}