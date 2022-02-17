#include <stdio.h>

void main(){
    int a,b;
    printf("Enter two numbers a and b");
    scanf("%d",&a);
    scanf("%d",&b);
    int is_co = 1;
    for (int i=2; i<=a && i<=b ; i++ )
    {
        if(a%i==0 && b%i==0) 
            is_co=1;
        else 
            is_co =0;
    }
    if(is_co == 0) printf("They are coprimes");
    else printf("they are not coprimes");
}