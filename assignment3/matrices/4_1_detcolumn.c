#include <stdio.h>
#define N 1000000007

void readArray(int d,long long int A[][d])
{   
    for(int i=0;i<d;i++)
        for(int j=0;j<d;j++)
            scanf("%lld",&A[i][j]);
}
int mod(long long int a)
{
    long long int n = 1000000007;
    if(a>=0)
        return (a%n);
    else
        return ((a+n)%n);
}

long long int detOfc(int d,long long int A[][d])
{  
    if(d>2)
    {   
        long long int sum =0;
        for(int c=0;c<d;c++)
        {
            long long int b[d-1][d-1];
            int y=0;
            for(int j=0;j<d;j++)
            {   
                if(j==c)
                    continue;
                int x=0;
                for(int k=1;k<d;k++)
                {
                    b[x][y] = A[k][j];
                    x++;
                }
                y++;                    
            }

            if(c&1)
                // sum =mod(mod(sum) - mod( mod(detOfc(d-1,b))*mod(A[0][c]) ) );
                sum = (sum - (((detOfc(d-1,b)%N)*A[0][c])%N) )%N;
            else
                // sum =mod(mod(sum) + mod( mod(detOfc(d-1,b))*mod(A[0][c]) ) );
                sum = (sum + (((detOfc(d-1,b)%N)*A[0][c])%N) )%N;  
        }
        return sum;
    }
    else
    {   
        // long long int m=  mod(mod(mod(A[0][0])*mod(A[1][1])) - mod(mod(A[1][0])*mod(A[0][1]))) ;
        long long int m=  (( A[0][0]*A[1][1] )) - ((A[1][0]*A[0][1]));
        return m;
    }
}


int main(){
    long long int Q = 1000000007;
    int d;
    scanf("%d",&d);
    if(d>1)
    {
        long long int A[d][d];
        readArray(d,A);
        printf("%lld",((detOfc(d,A)+Q)%Q));
    }
    else
    {
        long long int x;
        scanf("%lld",&x);
        long long int ans = x%Q;
        if(x<0)
            ans = (x+Q)%Q;
        printf("%lld",ans); 
    }
    return 0;
}