#include <stdio.h>

int main()
{
    long int L,k,m;
    scanf("%ld %ld %ld",&L,&k,&m);
    char D[L+1];
    scanf("%s",D);
    long int a=0;
    long int ct=0;
    while(D[a]!='\0')
    {
        printf("%c",D[a]);
        ct++;
        if(ct==k)
        {
            if(D[a+1]=='\0')
                break;
            printf("\n");
            a=a-m;
            ct=0;
        }
        a++;
    }
    return 0;
}