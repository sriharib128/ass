#include <stdio.h>
# define N 1000000 //max value of an input
int main(int argc , char *argv[])
   {
    FILE *in = fopen(argv[1],"r");
    FILE *op = fopen(argv[2],"w");
    double x;
    long long int n=0;
    double sum=0;
    // long long int square=0;
    while(fscanf(in,"%lf",&x)!=EOF)
    {
        n++;
        sum +=x;
        // square+=(x*x);
    }
    double mean=sum/n;
    fprintf(op,"%lf",mean);
    fclose(in);
    fclose(op);
}