#include<stdio.h>
void main(){
/*	int arr[]={10,20,30,40,50};
	for(int i=4;i>-1;i--){
		printf("%d ",arr[i]);
	}*/

	int arr[]={10,20,30,40,50};
	int start=0;
	int end=4;

	while(start<end){
			int temp=arr[start];
			arr[start]=arr[end];
			arr[end]=temp;
			start++;
			end--;
		}
	for(int i=0;i<5;i++){
		printf("%d",arr[i]);
		}
	}

