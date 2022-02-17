#include <stdio.h>

int main(int argc , char *argv[])
   {
    FILE *in = fopen(argv[1],"r");
    FILE *m = fopen(argv[2],"w");
    FILE *v = fopen(argv[3],"w");
    double x;
    long long int n=0;
    double sum=0;
    double square=0;
    while(fscanf(in,"%lf",&x)!=EOF)
    {
        n++;
        sum+=x;
        square+=(x*x);
    }
    double mean=1.0*sum/n;
    double var = ((1.0*square)/n) - ((1.0*sum)/n);
    printf("%lf",var);
    fprintf(m,"%lf",mean);
    fprintf(v,"%lf",var);
    fclose(in);
    fclose(m);
    fclose(v);
}