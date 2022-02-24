#include "include.h"
char *x[N+10];

int main ( int argc, char *argv[] ) 
{ 
    FILE * fp=fopen(argv[1],"r");
	int ret =0;
	long long int ct=0;
	long long int round =0;
	int rem=1;
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
		{	round++;
			// printf("> First N started");
			char * f_name = name(round);
	    	FILE *f1=fopen(f_name,"w");
			mergeSort(x,0,ct-1);
			for(int i=0;i<N;i++)
        		fprintf(f1,"%s\n",x[i]);
			fclose(f1);	
			free(f_name);
			for(int i=0;i<N;i++)
				free(x[i]);
			// printf("==> completed round=1 \n");
			ct=0;
			rem=0;
        	break;
        }

	}
	
    //sorting after that
    if(rem==0)
	{
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
				// printf("> Starting %lld N ==> ",round);
				
				char * f_name = name(round);
				FILE *f2=fopen(f_name,"w");
				mergeSort(x,0,ct-1);
				for(int i=0;i<N;i++)
					fprintf(f2,"%s\n",x[i]);
				fclose(f2);
				free(f_name);
	// 			emptying the array and memory so that the next N elements can be sorted
				for(int i=0;i<N;i++)
					free(x[i]);
				ct=0;
				rem=0;
				// printf(">completed %lld N\n",round);
			}
		}
		

		if(rem==1)
		{	
			// printf("> remaining after %lld N ==> ",round);
			round++;
			char * f_name = name(round);
			FILE *f2=fopen(f_name,"w");
			mergeSort(x,0,ct-1);
			for(int i=0;i<ct;i++)
				fprintf(f2,"%s\n",x[i]);
			fclose(f2);
			free(f_name);
			for(int i=0;i<ct;i++)
				free(x[i]);
			// printf("> completed remaining %lld N\n",(round-1));
		}
	}
	else
	{
		// printf("> remaining after %lld N ==> ",round);
			round++;
			char * f_name = name(round);
			FILE *f2=fopen(f_name,"w");
			mergeSort(x,0,ct-1);
			for(int i=0;i<ct;i++)
				fprintf(f2,"%s\n",x[i]);
			fclose(f2);
			free(f_name);
			for(int i=0;i<ct;i++)
				free(x[i]);
			// printf("> completed remaining %lld N and now in round %lld\n",(round-1),round);	
	}
	
	fclose(fp);
//completed sorting N words taken at a time

// merging the n sorted files
mergeFiles(round,argv[2]);

	return 0;
}
