#include<stdio.h>
#include<string.h>
// int strcmp1(char ch[],char ch1[],int npos){
//     int i=0;
//     int count=0;
//     while(i<npos){
//         if(ch[i]==ch1[i]){
//             ++i;
//             count++;
//         }else{
//             return -1;
//         }
//     }if(count!=npos){
//         return -1;
//     }return 1;
// }

int strcmp1(char ch[],char ch1[],int index,int npos){
    
    if(index<npos){
        return ch[index]==ch1[index] && strcmp1(ch,ch1,index+1,npos);
    }
    return -1;
}

void main(){
    char ch[10],ch1[10];
    
    printf("Enter 1st string:");    
    gets(ch);

    printf("\nEnter 2nd string:");
    gets(ch1);

    int n;
    printf("\nEnter nth place:");
    scanf("%d",&n);

        if(strcmp1(ch,ch1,0,n)==1){
            printf("\nStrings Match!");
        }else{
            printf("\nStrings Don't match!");
        }
    }

