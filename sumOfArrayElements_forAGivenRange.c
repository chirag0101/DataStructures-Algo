#include<stdio.h>
void main(){
    int arr[]={1,2,3,4,5,6,7,8};

    for(int i=0;i<3;i++){
        printf("Enter Start:");
        int start;
        scanf("%d",&start);
    
        printf("\nEnter End:");
        int end;
        scanf("%d",&end);
    
        int sum=0;
    
        for(int j=start;j<=end;j++){
            if(start==end){
                sum=arr[j];
            }else{
                sum=sum+arr[j];
            }
        }
        printf("\nSum: %d\n",sum);
    }
}