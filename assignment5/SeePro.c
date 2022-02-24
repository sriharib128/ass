#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * p1,const void * p2) {
   return (* (long long int * )p2-*(long long int * )p1);
}

int main()
{
	long long int N,K;
	scanf("%lld %lld",&N,&K);
	long long int A[N];
	for(int i=0;i<N;i++)
		scanf("%lld",&A[i]);
	// qsort(A, N, sizeof(long long int), cmpfunc);

	long long int read=0;
	long long int rem =0;
	long long int minute =0;
	for(int i=0;i<N;i++)
	{
		if((rem+A[i])<=8)
		{
			read+=rem+A[i];
			rem=0;
		}
		else
		{
			read+=8;
			rem=A[i]+rem-8;
		}
		if(read>=K)
		{
			printf("%d",(i+1));
			break;
		}
	}
	if(read<K)
		printf("-1");
	return 0;
}
//i=0 , rem =2, read =8
//i=1 , read =16; rem =4
//i=2 , read = 24; rem =4;
