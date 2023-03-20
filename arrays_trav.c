#include<stdio.h>
void main(){
    int a[50],size;
    int i;
    printf("Enter size:");
    scanf("%d",&size); 
    printf("Enter elements:");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<size;i++){
    printf("Normal array: ");
    printf("%d \n",a[i]);
    }

    int pos=3;
    int num=10;
    size++;
    {
        for(i=size-1;i>=pos-1;i--){
        a[i+1]=a[i];
    }
    a[pos-1]=num;
    
    for(i=0;i<size;i++){
        printf("New array: ");
        printf("%d \n",a[i]);
    }
    }
}