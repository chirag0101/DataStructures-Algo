#include<stdio.h>
#include<string.h>

int strcmp1(char ch[]){
    int count=0;
    while(*ch!='\0'){
        count++;
        ch++;
    }
    return count;
}

void main(){
    char ch[10];
    
    printf("Enter 1st string:");    
    gets(ch);
    int x=strcmp1(ch);
    printf("%d",x);

    }
