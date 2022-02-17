#include <stdio.h>
#include <stdlib.h>
#define N 1000000

int main ( int argc, char *argv[] ) 
{ 
    FILE * f[argc];
    int temp = argc-1;
    while(temp!=1)
    {    
        f[temp] = fopen( argv[temp], "r" );
        temp--;
    }
    f[temp] = fopen(argv[temp],"w");
    int a[256] = {};
    temp = argc-1;
    int ct=0;
    while(temp!=1)
    {   
        char x;
        while ( ( x = fgetc(f[temp])) != EOF ) 
        { 
            a[(int)x]++;    
        }
        fclose(f[temp]);
        temp--;
    } 
    for(int i=0;i<256;i++)
    {
        if((i>=48 && i<=57)||(i>=65 && i<=90) || (i>=97 && i<=122))
            fprintf(f[temp],"%c:%d\n",(char)i,a[i]);
    }
    fclose(f[temp]);
    return 0;
}