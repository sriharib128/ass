/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void printArray(char *A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%s ", A[i]);
	printf("\n");
}

int main()
{
	char *arr[] = { "Hello", "World", "My","Name", "Is","Bye"};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size-1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}
