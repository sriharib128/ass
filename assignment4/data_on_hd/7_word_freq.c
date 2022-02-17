#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000000

//Merge Sort
void merge(char *arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	char *L[n1], *R[n2];
	for (i = 0; i < n1; i++)
	{
		L[i]=(char*)malloc(strlen(arr[l+i])+1);
		strcpy(L[i],arr[l+i]);
	}
	for (j = 0; j < n2; j++)
	{	
		R[j]=(char*)malloc(strlen(arr[m+1+j])+1);
		strcpy(R[j],arr[m+1+j]);
	}

	i = 0;	j = 0; 	k = l;

	while (i < n1 && j < n2) {

		if (strcmp(L[i],R[j])<=0) {
			arr[k]=(char*)malloc(strlen(L[i])+1);
			strcpy(arr[k],L[i]);
			i++;
		}
		else {
			arr[k]=(char*)malloc(strlen(R[j])+1);
			strcpy(arr[k],R[j]);
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k]=(char*)malloc(strlen(L[i])+1);
		strcpy(arr[k],L[i]);
		i++;
		k++;
	}
	while (j < n2) {
		arr[k]=(char*)malloc(strlen(R[j])+1);
		strcpy(arr[k],R[j]);
		j++;
		k++;
	}
}

void mergeSort(char *arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

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
    temp = argc-1;
    long int ct=0;
    char *x[N];
    //reading each word into an array;
    while(temp!=1)
    {   char tempname[1000];
        while(fscanf(f[temp],"%s",tempname) != EOF )
        {
            x[ct]=(char*)malloc(strlen(tempname)+1);
            strcpy(x[ct++],tempname);
        }
        fclose(f[temp]);
        temp--;
    }
    // fprintf(f[temp],"%ld\n",ct);
    
    mergeSort(x, 0, ct-1);

    long int uq=0;
    int u_f[21000]={};
    char *u_w[21000];
    
    u_w[uq] = (char*)malloc(strlen(x[0])+1);
    strcpy(u_w[uq],x[0]);
    u_f[uq]++;

    for(int i=1;i<ct;i++)
    {
        if(strcmp(x[i],u_w[uq])==0)
            u_f[uq]++;
        else
        {   
            uq++;
            u_w[uq] = (char*)malloc(strlen(x[i])+1);
            strcpy(u_w[uq],x[i]);
            u_f[uq]++;
        }
    }

    for(int i=0;i<uq;i++)
    {
        fprintf(f[temp],"%s:%d\n",u_w[i],u_f[i]);
    }
    fprintf(f[temp],"%s:%d",u_w[uq],u_f[uq]);

    fclose(f[temp]);
    return 0;
}