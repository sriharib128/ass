#include <stdio.h>
#include <stdlib.h>

int main(int argc , char *argv[])
   {
    int count;  
    unsigned int seed =20; // use for randomize number   
    srand (seed);

    FILE *in = fopen(argv[1],"r");
    FILE *m = fopen(argv[2],"w");
    FILE *r = fopen(argv[3],"w");
    double x;
    double p[1000];
    long long int n=0;
    long long int ct=0;
    double sum=0;
    while(fscanf(in,"%lf",&x)!=EOF)
    {   
        n++;
        sum+=x;
        double mean=1.0*sum/n;
        if( (x<=(1.2*mean)) && (x>=(0.8*mean)) ) 
            ct++;
        
        if(n<1000) //only for cases where we are dealing with small data
            p[n]=x;
    }
    double mean=1.0*sum/n;
    fprintf(m,"%lf",mean);
    double percent =(ct*100.0/n);
    
    if(n<1000)
    {   ct=0;
        for(int i=0;i<n;i++)
        {
            if( (p[i]<=(1.2*mean)) && (p[i]>=(0.8*mean)) )
                ct++;
        }
        percent=(ct*100.0/n);
    }

    fprintf(r,"%lf",percent);
    fclose(in);
    fclose(m);
    fclose(r);
}