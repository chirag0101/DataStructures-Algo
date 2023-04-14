#include<stdio.h>
#include<string.h>
// int strcmp1(char ch[],char ch1[],int size){
//     int i=0;
//     while(i<size){
//         if(ch[i]==ch1[i]){
//             i++;
//         }else{
//             return -1;
//         }
//     }
//     return 1;
// }

int strcmp1(char ch[],char ch1[],int index,int size){
    
    if(index<size){
        return ch[index]==ch1[index] && strcmp1(ch,ch1,index+1,size);
    }
    return -1;
}

void main(){
    char ch[10],ch1[10];
    
    printf("Enter 1st string:");    
    gets(ch);

    printf("\nEnter 2nd string:");
    gets(ch1);

    if(strlen(ch)!=strlen(ch1)){
        printf("\nStrings dont match!");
    }else{

        if(strcmp1(ch,ch1,0,strlen(ch1))){
            printf("\nStrings Match!");
        }else{
            printf("\nStrings Don't match!");
        }
    }

    }
