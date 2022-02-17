#include <stdio.h>
#include <string.h>
#define N 1000000007

void readArray(int d,long long int A[][d])
{   
    for(long long int i=0;i<d;i++)
        for(long long int j=0;j<d;j++)
        {
            scanf("%lld",&A[i][j]);
        }
}
/*
void printArray(int d,int A[][d])
{
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
}
*/
long long int detOfc(int d,long long int A[][d])
{   if(d>2)
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
                sum = ( (sum%N) + (((detOfc(d-1,b)%N)*(A[0][c]%N))%N) )%N;
            else
                sum = ( (sum%N) + (((detOfc(d-1,b)%N)*(A[0][c]%N))%N) )%N;  
        }
        return sum;
    }
    else
    {   
        long long int m=(( (A[0][0]%N)*(A[1][1]%N) )%N) + (( (A[1][0]%N)*(A[0][1]%N) )%N);
        return m;
    }
}
int printBase(long long int det,int b,char base[])
{   int i = 0;
    while(det>0)
    {
        int rem  = det%b;
        if(rem<=9)
        {
            base[i]= rem + 48;
            // printf(" %c ",base[i]);
            i++;
        }
        else
        {
            char c = rem-10 + 'a';
            base[i]=c;
            // printf(" %c ",base[i]);
            i++;
        }
        det=det/b;
    }
    return i;
}
int main(){
    int d,q,b;
    scanf("%d %d",&q,&d);
    if(q==1)
        scanf("%d",&b);
    long long int A[d][d];
    readArray(d,A);
    long long int det = detOfc(d,A);
    char base[1000];
    
    if(q==1)
    {  
        int i = printBase(det,b,base);
        printf("\n\n");
        while(i--)
           { printf("%c",base[i]);}
    }
    else
        printf("%lld",det);
    return 0;
}