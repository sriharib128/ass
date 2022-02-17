#include <stdio.h>
#define M 1000000007
long long int binexp(long long int a,long long int b)
{
    long long int result =1;
    while(b>0)
    {
        if(b&1)
            result=(result*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return result;
}
int main()
{
    long long int ans = binexp(2,M-2);
    printf("%lld\n",ans);
}