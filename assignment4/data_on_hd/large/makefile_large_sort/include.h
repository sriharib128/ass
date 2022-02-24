#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100000

void merge(char **,int,int,int);
void mergeSort(char**,int,int);
void merge_two_files(FILE *,FILE *,FILE *);
char * name(long long int);
void mergeFiles(long long int,char *);
