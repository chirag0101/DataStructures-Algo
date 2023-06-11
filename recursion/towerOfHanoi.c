#include<stdio.h>
void TOH(int n,char from,char via,char to){
    if(n>0){
        TOH(n-1,from,to,via);
        printf("        %c->%c\n",from,to);
        TOH(n-1,via,from,to);
    }
}
void main(){
    int n;
    printf("Enter no of Disks:");
    scanf("%d",&n);
    printf("Steps:\n");
    TOH(n,'A','B','C');
}