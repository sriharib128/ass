#include "include.h"
extern char * f_name;
char *L[N], *R[N];

void merge(char *arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

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
			free(arr[k]);
			arr[k]=(char*)malloc(strlen(L[i])+1);
			strcpy(arr[k],L[i]);
			free(L[i]);
			i++;
		}
		else {
			free(arr[k]);
			arr[k]=(char*)malloc(strlen(R[j])+1);
			strcpy(arr[k],R[j]);
			free (R[j]);
			j++;
		}
		k++;
	}

	while (i < n1) {
		free(arr[k]);
		arr[k]=(char*)malloc(strlen(L[i])+1);
		strcpy(arr[k],L[i]);
		free(L[i]);
		i++;
		k++;
	}
	while (j < n2) {
		free(arr[k]);
		arr[k]=(char*)malloc(strlen(R[j])+1);
		strcpy(arr[k],R[j]);
		free (R[j]);
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