#include <stdio.h>
#include <stdlib.h> 
#define N 100000
int main(int argc , char *argv[])
   {

    FILE *in = fopen(argv[1],"r");
    FILE *m = fopen(argv[2],"w+");
    long long int x;
    long long int n=0;
    long long int sum=0;
    long long int square=0;
    double app_var=0;
    double actual_var=0;
    fprintf(m,"N,Approx,Actual\n");
    while(fscanf(in,"%lld",&x)!=EOF)
    {
        n++;
        sum+=x;
        double app_mean = 1.0*sum/n;
        square+=(x*x);
        app_var+=((x-app_mean)*(x-app_mean));
        actual_var = ((1.0*square)/n) - (app_mean*app_mean);
        fprintf(m,"%lld,%lf,%lf\n",n,(app_var/n),actual_var);
    }    
    fclose(in);
    fclose(m);
}