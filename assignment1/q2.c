#include <stdio.h>

void main(){
    int a,b,i;
    printf("enter a number");
    scanf("%d",&a);
    printf("how many rows do you want in the table");
    scanf("%d",&b);
    i = 1;
    while (i<=b){
        printf("%d x %d =%d\n",a,i,(a*i));
        i = i+1;
    }
    
}