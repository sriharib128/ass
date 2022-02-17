#include <stdio.h>

long int ab(long int a)
{
    if(a>=0)
        return a;
    else
        return (a*(-1));
}
int main()
{
    int n;
    scanf("%d",&n);
    long int A[n];
    for(int i=0;i<=n-1;i++)
        scanf("%ld",&A[i]);
    int i = n-1;

    while(A[i]==0)
    {
        i--;
    }
    if(i==-1)
        printf("%d",0);
    else
    {
        if(i>1)
            {
                if(A[i]==1)
                    printf("x^%d",i);
                else if(A[i]>1)
                    printf("%ldx^%d",A[i],i);
                else if(A[i]<-1)
                    printf("-%ldx^%d",ab(A[i]),i);
                else if(A[i]==-1)
                    printf("-x^%d",i);
            }
        else if(i==1)
            {
                if(A[i]==1)
                    printf("x");
                else if(A[i]>1)
                    printf("%ldx",A[i]);
                else if(A[i]<-1)
                    printf("-%ldx",ab(A[i]));
                else if(A[i]==-1)
                    printf("-x");
            }
        else if(i==0)
            {
                if(A[i]==1)
                    printf("%ld",A[i]);
                else if(A[i]>1)
                    printf("%ld",A[i]);
                else if(A[i]<-1)
                    printf("-%ld",ab(A[i]));
                else if(A[i]==-1)
                    printf("-%ld",ab(A[i]));
            }

        while(i--)
        {
            if(i>1)
            {
                if(A[i]==1)
                    printf(" + x^%d",i);
                else if(A[i]>1)
                    printf(" + %ldx^%d",A[i],i);
                else if(A[i]<-1)
                    printf(" - %ldx^%d",ab(A[i]),i);
                else if(A[i]==-1)
                    printf(" - x^%d",i);
                else if(A[i]==0)
                    continue;
            }
            else if(i==1)
            {
                if(A[i]==1)
                    printf(" + x");
                else if(A[i]>1)
                    printf(" + %ldx",A[i]);
                else if(A[i]<-1)
                    printf(" - %ldx",ab(A[i]));
                else if(A[i]==-1)
                    printf(" - x");
                else if(A[i]==0)
                    continue;
            }
            else if(i==0)
            {
                if(A[i]==1)
                    printf(" + %ld",A[i]);
                else if(A[i]>1)
                    printf(" + %ld",A[i]);
                else if(A[i]<-1)
                    printf(" - %ld",ab(A[i]));
                else if(A[i]==-1)
                    printf(" - %ld",ab(A[i]));
                else if(A[i]==0)
                    continue;
            }
        }
    }
}
/*
    0 => 0
    0,0 => 0
    0,-1,35,0 => -x^2+35x
    5,1,7,-9 => 5x^3+x^2+7x-9
    100,0,0,-1 => 100x^3-1
    931,21,-11,1 => 931x^3+21x^2-11x+1
*/