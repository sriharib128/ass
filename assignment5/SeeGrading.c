#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * p1,const void * p2) {
   return (* (long long int * )p1-*(long long int * )p2);
}

int main()
{
	long long int n,m;
	scanf("%lld %lld",&n,&m);
	long long int A[n];
	long long int B[m];
	for(int i=0;i<n;i++)
		scanf("%lld",&A[i]);
	for(int i=0;i<m;i++)
		scanf("%lld",&B[i]);

	qsort(A, n, sizeof(long long int), cmpfunc);
	qsort(B, m, sizeof(long long int), cmpfunc);

	for(int i=0;i<n;i++)
		printf("%lld ",A[i]);
	printf("\n");
	for(int i=0;i<m;i++)
		printf("%lld ",B[i]);
	printf("\n");

	long long int a=0;
	long long int b=0;
	long long int ct=0;

	int check_a=0,check_b=0;

	while(1)
	{
		if(A[a]==B[b])
		{ct++;a++;b++;}
		else if(A[a]<B[b])
		{a++;}
		else
		{b++;}
		if(a==n || b==m)
			break;
	}
	printf("%lld\n",ct);
}