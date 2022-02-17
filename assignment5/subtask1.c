#include <stdio.h>
#define M 1000000007

int a[5][5];
int m, n;
// int ct;
int recur(int i,int j)
{   
    // printf("%d >",ct++);
    if(i==n-1 && j==m-1)
        return a[i][j];
    // int flag=0;
    long long int sum=0;
    if(i<n-1)
    {   
        if(a[i+1][j]!=0)
        {   
            long long int x= recur(i+1,j)%M;
            
            sum+=(a[i][j]*x)%M;
            // printf("%d(sum) + =(a[%d][%d])%d  * (recur(%d,%d)) %d\n",sum,i,j,a[i][j],i+1,j,x);

        }
    }
    if(j<m-1)
    {
        if(a[i][j+1]!=0)
        {   
            int x= recur(i,j+1)%M;
            sum+=(a[i][j]*x)%M;
            // printf("%d(sum) + =(a[%d][%d])%d  * (recur(%d,%d)) %d\n",sum,i,j,a[i][j],i,j+1,x);

        }
    }
    // printf("\n");
    return (sum%M);
}

int main()
{
    int q;
    scanf("%d",&q);
    scanf("%d %d",&n,&m);
    //(1,1) ==>(n,m)
    for(int i=0;i<n;i++)
    {   
        long long int temp;
        scanf("%lld",&temp);
        int j=m-1;
        while (temp!=0)
        {
            a[i][j]=temp%10;
            temp=temp/10;
            j--;
        }
    }
    long long int ans = recur(0,0);   
    printf("%lld",ans);    
}