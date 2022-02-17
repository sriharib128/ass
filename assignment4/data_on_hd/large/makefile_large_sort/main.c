#include "include.h"

int main ( int argc, char *argv[] ) 
{ 
    FILE * fp=fopen(argv[1],"r");
    char *x[N+10];
	int ret =0;
	long long int ct=0;

    //sorting the first N elements
	while(1)
	{	
		char tempname[110];
		ret = fscanf(fp,"%s",tempname);
		if(ret == (-1) )
		{ break; }
		x[ct]=(char*)malloc(strlen(tempname)+1);
		strcpy(x[ct++],tempname);
		if(ct==N)
		{	
			printf("> First N started");
	    	FILE *f1=fopen("f1.txt","w");
			mergeSort(x,0,ct-1);
			for(int i=0;i<N;i++)
        		fprintf(f1,"%s\n",x[i]);
			fclose(f1);	
			for(int i=0;i<N;i++)
				free(x[i]);
			printf("==> completed round=0 \n");
			ct=0;
        	break;
        }

	}
	
    //sorting after that
    long long int round =0;
    int rem=1;
    while(1)
	{	
		char tempname[110];
		ret = fscanf(fp,"%s",tempname);
		if(ret == (-1) )
		{	break; }
		rem=1;
		x[ct]=(char*)malloc(strlen(tempname)+1);
		strcpy(&x[ct++][0],tempname);
		if(ct==N)
		{	
			round++;
			printf("> Starting %lld N ==> ",round);
			
			FILE *f2=fopen("f2.txt","w");
			mergeSort(x,0,ct-1);
			for(int i=0;i<N;i++)
				fprintf(f2,"%s\n",x[i]);
			fclose(f2);
			
			f2=fopen("f2.txt","r");
			FILE *f1,*f3;
			
			if(round & 1)
			{
				f1=fopen("f1.txt","r");
                f3=fopen("f3.txt","w");
				merge_two_files(f1,f2,f3);
				fclose(f1);
				fclose(f2);
    			fclose(f3);
				remove("f1.txt");
				remove("f2.txt");
			}
			else
			{
				f1=fopen("f1.txt","w");
                f3=fopen("f3.txt","r");
				merge_two_files(f3,f2,f1);
				fclose(f1);
				fclose(f2);
    			fclose(f3);
				remove("f3.txt");
				remove("f2.txt");
			}
			
// 			emptying the array and memory so that the next N elements can be sorted
			for(int i=0;i<N;i++)
				free(x[i]);
			ct=0;
            rem=0;
			printf(">completed %lld N\n",round);
		}
	}

    if(rem==1)
    {	printf("> remaining after %lld N ==> ",round);
		FILE *f2=fopen("f2.txt","w");
		mergeSort(x,0,ct-1);
		for(int i=0;i<ct;i++)
			fprintf(f2,"%s\n",x[i]);
		fclose(f2);
		
		f2=fopen("f2.txt","r");
		FILE *f1,*f3;
        if(!(round&1))
		{
			f1=fopen("f1.txt","r");
            f3=fopen("f3.txt","w");
			merge_two_files(f1,f2,f3);
		}
		else
		{
			f1=fopen("f1.txt","w");
            f3=fopen("f3.txt","r");
			merge_two_files(f3,f2,f1);
		}
		fclose(f1);
		fclose(f2);
    	fclose(f3);
		printf("> completed remaining %lld N\n",round);
    }

	if(!(round&1))
	{	
		rename("f3.txt","o_p_sorted_file.txt");
		remove("f2.txt");
		remove("f1.txt");
	}
	else
	{	
		rename("f1.txt","o_p_sorted_file.txt");
		remove("f2.txt");
		remove("f3.txt");
	}
	for(int i=0;i<ct;i++)
		free(x[i]);
    fclose(fp);
	return 0;
}