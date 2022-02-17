#include <stdio.h>
#include <stdlib.h>
#define N 1000000
#define PI 3.142857

float x[N+10];
float y[N+10];
int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1],"w");
    unsigned int seed =20; // use for randomize number   
    srand (seed);

    for(int i=1;i<=N;i++)
    {
        float a = ((float)rand()/(float)(RAND_MAX))*2;
        x[i]=a-1;
        float b = ((float)rand()/(float)(RAND_MAX))*2;
        y[i]=b-1;
    }
    
    long int count=0;
    fprintf(fp,"N,estimate,actual\n");
    
    for(long int i=1;i<=N;i++)
    {
        if( ((x[i]*x[i]) + (y[i]*y[i])) <= 1)
            count++;
        double estimate  = 4.0*count/i;
        fprintf(fp,"%ld,%lf,%lf\n",i,estimate,PI);
    }
}