#include<stdio.h>
	int main(){
		int arr[]={1,2,3,4,5};
		int store=0;
		for(int i=0;i<=3;i++){
			for(int j=i+1;j<=4;j++){
				if(arr[i]<arr[j]){
					store=arr[j];	
				}
			}
		}
		printf("%d ",store);
		return 0;
	}
