#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;n>0;i++){
		for(int j=i;j<=200 && n>0;j++){
			long long int k=(long long int)i*i+ (long long int)j*j;
			// double x= sqrt(k);
				if(k<=40000){
			    if (ceil((double)sqrt(k)) == floor((double)sqrt(k))) {
        			printf("%d %d %d\n",i,j,(int)floor((double)sqrt(k)));
        			n--;
    				}
    			}
			}
		
	}
	return 0;
}