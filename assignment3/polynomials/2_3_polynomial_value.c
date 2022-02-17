#include <stdio.h>

int pro(int a,int i)
{   
    int x=1;
    while(i--)
        x*=a;
    return x;
}

int main()
{
    int n;
    scanf("%d",&n);
    long long int sum =0;
    int i=0;
    n++;
    long int A[n];
    for(int i=0;i<n;i++)
        scanf("%ld",&A[i]);

    long int a;
    scanf("%ld",&a);

    for(int i=0;i<n;i++)
        sum+=A[i]*pro(a,i);
    printf("%lld",sum);
    return 0;
}