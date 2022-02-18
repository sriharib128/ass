#include "include.h"

void mergeFiles(long long int round,char * o_name)
{	
	// printf("starting merging \n");
	long long int t=1;
	long long int n_temp=0;
	if( (round&1) && (round!=1) ) //odd number of files as we are using 1 based indexing
	{	
		// printf("round = %lld is odd\n",round);
		char *namet=name(t);
		char *namet_1=name(t+1);
		char *name_00=name(-1);
		FILE *f1=fopen(namet,"r");
		FILE *f2=fopen(namet_1,"r");
		FILE *f3=fopen(name_00,"w");
		merge_two_files(f1,f2,f3);
		fclose(f1);
		fclose(f2);
		fclose(f3);
		// printf("merged %d-%s & %d-%s into %d-%s\n",t,name(t),t+1,name(t+1),M,name(M));
		remove(namet);
		remove(namet_1);
		// printf("t=%lld ; t+1 = %lld and name(t+1)=%s\n",t,(t+1),name(t+1));
		rename(name_00,namet_1);
		// printf("renamed %s into %s \n",name_00,namet_1);
		free(name_00);free(namet);free(namet_1);
		t+=1;
	}
	// printf("round = %lld is even t= %lld\n",round,t);
	long long int temp=round;
	for(long int i=t;i<round;i+=2)
	{	
		char *namet=name(i);
		char *namet_1=name(i+1);
		char *name_temp=name(++temp);
		FILE *f1=fopen(namet,"r");
		FILE *f2=fopen(namet_1,"r");
		FILE *f3=fopen(name_temp,"w");
		merge_two_files(f1,f2,f3);
		fclose(f1);
		fclose(f2);
		fclose(f3);
		remove(namet);
		remove(namet_1);
		free(namet);free(namet_1);free(name_temp);
		n_temp++;
	}

	t=round+1;
	while(n_temp>1)
	{	

		long int temp_round = t+n_temp-1;

		if( n_temp&1 ) 
		{	
			char *namet=name(t);
			char *namet_1=name(t+1);
			char *name_00=name(-1);
			FILE *f1=fopen(namet,"r");
			FILE *f2=fopen(namet_1,"r");
			FILE *f3=fopen(name_00,"w");			
			merge_two_files(f1,f2,f3);
			fclose(f1);
			fclose(f2);
			fclose(f3);
			remove(namet);
			remove(namet_1);
			rename(name_00,namet_1);
			free(name_00);free(namet);free(namet_1);
			t+=1;
		}
		n_temp=0;
		for(long int i=t;i<=temp_round;i+=2)
		{
		char *namet=name(i);
		char *namet_1=name(i+1);
		char *name_temp=name(++temp);
		FILE *f1=fopen(namet,"r");
		FILE *f2=fopen(namet_1,"r");
		FILE *f3=fopen(name_temp,"w");

			merge_two_files(f1,f2,f3);
			fclose(f1);
			fclose(f2);
			fclose(f3);
			remove(namet);
			remove(namet_1);
			free(namet);free(namet_1);free(name_temp);
			n_temp++; 
		}
		t=temp_round+1;
	}
	remove(o_name);
	rename(name(temp),o_name);
}
