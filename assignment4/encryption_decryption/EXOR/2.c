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
            b[i]=a[i];
        }
        else if(i>127)
        {
            a[i]=a[i-1]^a[i-127];
            b[i]=x;
        }
    }

    long int n_00=0,rn_00=0;
    long int d_00=0,rd_00=0;
    long int n_01=0,rn_01=0;
    long int d_01=0,rd_01=0;

    for(int i=2;i<=N;i++)
    {
        if(a[i-1]==0)
        {   
            if(a[i]==0)
                n_00++;
            d_00++;
        }
        if(a[i-1]==1)
        {   
            if(a[i]==0)
                n_01++;
            d_01++;
        }


        if(b[i-1]==0)
        {   
            if(b[i]==0)
                rn_00++;
            rd_00++;
        }
        if(b[i-1]==1)
        {   
            if(b[i]==0)
                rn_01++;
            rd_01++;
        }
    }
    
    printf("using exor ==>");
    printf("P(0/0) =%lf ; P(0/1) =%lf\n", n_00*100.0/d_00 , n_01*100.0/d_01 );
    printf("using random ==>");
    printf("P(0/0) =%lf ; P(0/1) =%lf\n", rn_00*100.0/rd_00 , rn_01*100.0/rd_01 );
    return 0;
}