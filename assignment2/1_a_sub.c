#include <stdio.h>
#include <math.h>

int main(){
    long int N;
    scanf("%ld",&N);

    int m[N];
    int flag =0;

    int max=-1,min=101;

    for (int i=0; i<N;i++){

        scanf("%d",&m[i]);

        if(m[i]>100 || m[i]<0)
            {flag =1;break;}

        if(m[i]>max) {max=m[i];}
        if(m[i]<min) {min=m[i];}

    }
    if(flag==1)
        printf("INVALID INPUT");

    else
        printf("%d %d" , max , min);
    // if(flag !=1)
    // {
    // for(int j=0;j<11;j++)
    // {    
    //     int sum=0;

    //     for (int i = 0; i<N;i++)
    //     {
    //         if( ( m[i]<(10*(j+1)) ) && (m[i]>=10*(j)) )
    //           sum += 1;
    //     }
    //     printf("%d ",sum);
    // }
    // }
    

    
    return 0;
}