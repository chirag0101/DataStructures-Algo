//Anagram strings: if all the alphabets in str1 are present in str2 then they both are anagram to each other.
//Method:Sorted both strings and then compared both of them
#include<stdio.h>
#include<string.h>

void ssort(char str[],int size){
    int store,i,j;
    for(i=0;i<size+1;i++){
        for(j=0;j<size-1;j++){
            if(str[j]>str[j+1]){
                store=str[j];
                str[j]=str[j+1];
                str[j+1]=store;
            }
        }
    }
}

int main(){
    int i,j,count=0;

    char str1[10];
    printf("Enter 1st:");
    gets(str1);
    
    char str2[10];
    printf("Enter 2nd:");
    gets(str2);
    
    printf("\nStrings:");
    printf("%s %s\n",str1,str2);
    
    if(strlen(str1)==strlen(str2)){
        ssort(str1,strlen(str1));
        ssort(str2,strlen(str2));
        printf("%s %s",str1,str2);
        for(i=0;i<strlen(str1)+1;i++){
            if(str1[i]==str2[i]){
                count++;
            }else{
                break;
            }
        }
        if(count-1==strlen(str1)){
            printf("\nStrings are anagrams!\n");
        }else{
            printf("\nStrings aren't anagrams!\n");
        }
    }else{
        printf("\nStrings aren't of equal size!\n");
    }

    //reversed a string
    i=0,j=strlen(str1)-1;
    char temp;
    while(i<j){
        temp=str1[i];
        str1[i]=str1[j];
        str1[j]=temp;
        ++i;
        --j;
    }
    printf("\nStr Rev: %s\n",str1);
}