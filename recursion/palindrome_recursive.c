#include<stdio.h>
#include<string.h>
// int isPal(char str[],int size){
//     int i=0,j=size-1;
//     while(i<j){
//             if(str[i]!=str[j]){
//                 return 0;
//             }
//             i++;
//             j--;
//         }
//     return 1;
// }

int isPal(char str[],int size,int i,int j){
int i,j=size-1;
    if(str[i]!=str[j]){
        return 0;
    }else if(i<j){
        isPal(str,strlen(str),i++,j--);        
    }
    return 1;
}
void main(){
    char str[10];
    printf("Enter string:");
    gets(str);
    if(isPal(str,strlen(str),0,0)){
        printf("\nis palindrome\n");
    }else{
        printf("\nisnt a palindrome\n");
    }
}