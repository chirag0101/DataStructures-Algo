#include<stdio.h>
	int main(){
		int arr[]={1,2,3,4,4,5};
		int count=0,i=0,j=0;
		for(i=0;i<6;i++){
			for(j=i+1;j<6;j++){
				if(arr[i]==arr[j]){
						printf("%d ",arr[i]);
					}
			}
		}
		return 0;
	}	
