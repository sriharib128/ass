#include <stdio.h>

long int ab(long int a)
{
    if(a>=0)
        return a;
    else
        return (a*(-1));
}

void prettyprint(int n,long int A[n])
{
    int i=n-1;
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

int main()
{
    int n;
    scanf("%d",&n);
    long int A[n];
    for(int i=0;i<=n-1;i++)
        scanf("%ld",&A[i]);
    long int B[n];
    for(int i=1;i<=n-1;i++)
        B[i-1] = A[i]*i;
    prettyprint(n-1,B);
}