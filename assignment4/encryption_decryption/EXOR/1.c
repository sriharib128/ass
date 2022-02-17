#include <stdio.h>
#include <stdlib.h>
#define N 1000000

int main()
{   
    int seed =1000; // use for randomize number   
    srand (seed);
    
    int a[N+10];
    int b[N+10];
    long int ct_ex=0;
    long int ct_ra=0;
    
    for(int i=1;i<=N;i++)
    {  
        int x = rand()%2;
        if(i<128)
        {
            a[i]=x;
            if(a[i]&1)
                ct_ex++;
            b[i]=a[i];
        }
        else if(i>127)
        {
            a[i]=a[i-1]^a[i-127];
            if(a[i]&1)
                ct_ex++;
            b[i]=x;
        }
        if(x&1)
            ct_ra++;
    }

    printf("using exor ==>");
    printf("P(0) =%lf ; P(1) =%lf\n",(N-ct_ex)*100.0/N,(ct_ex)*100.0/N);
    printf("using random ==>");
    printf("P(0) =%lf ; P(1) =%lf\n",(N-ct_ra)*100.0/N,(ct_ra)*100.0/N);
    return 0;
}