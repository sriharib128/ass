#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000000

int main ( int argc, char *argv[] ) 
{ 
    FILE * op=fopen(argv[1],"w");
    FILE * fp=fopen(argv[2],"r");
    char *x[N+10];
	int ret =0;
	int n=1;
	while(n--)
	{
		while(ret !=-1)
		{	
			char tempname[1000];
			ret = fscanf(fp,"%s",tempname);
			if(ret==(-1))
				break;
			fprintf(op,"%s\n",tempname);
		}
	fclose(fp);
	fp=fopen(argv[2],"r");
	ret=0;
	}
	//char name[100]="hi.txt" or "./hi.txt"
	//fopen(name,"w");
	//remove(name);
    fclose(fp);
    fclose(op);
}