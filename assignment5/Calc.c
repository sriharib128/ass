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
    long long int n,m;
    scanf("%lld %lld",&n,&m);
    long long int a[n][m];//array
    long long int b[n][m];//hash array

    //accepting the array
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {   
            long long int temp;
            scanf("%lld",&temp);
            a[i][j]=temp%M;
            b[i][j]=a[i][j];
            if(j>0)
                b[i][j]=(b[i][j]*b[i][j-1])%M;//an element product of all numbers in that row 
        }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i>0)
                b[i][j]=(b[i][j]*b[i-1][j])%M;//an element is product of all numbers from (0,0)
            // printf("%lld ",b[i][j]);
        }
        // printf("\n");
    }

    long long int q;
    scanf("%lld",&q);

    while(q--)
    {
        long long int x1,y1,x2,y2;
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        
        long long int ans;
        
        if(x1==0 && y1 ==0)
            ans = b[x2][y2];
        else if(x1==0 && y1>0)
        {   
            ans = (b[x2][y2]*binexp(b[x2][y1-1],(M-2)))%M;
        }
        else if (x1>0 && y1==0)
        {
            ans = (b[x2][y2]*binexp(b[x1-1][y2],(M-2)))%M;
        }
        else if (x1>0 && y1>0)
        {
            long long int den= (b[x2][y1-1]*b[x1-1][y2])%M;
            long long int num=(b[x2][y2]*b[x1-1][y1-1])%M;
            ans =  (num*binexp(den,M-2))%M;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
