#include <stdio.h>

void readArray(int d,int A[][d])
{
    for(int i=0;i<d;i++)
        for(int j=0;j<d;j++)
            scanf("%d",&A[i][j]);
}
void printArray(int d,int A[][d])
{
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
}


int detOf(int d,int A[][d])
{   
    if(d>2)
    {
        int sum =0;
        int b[d-1][d-1];
        int x=0,y=0;
        for(int i=0;i<d;i++)
        {
            x=0;
            int n=0;
            for(int k=i+1;k<d+i+1;k++)
            {   
                if(x<(d-1))
                {
                    int z;
                    if(k<d)
                        z=k;
                    else{
                        z=n;
                        n++; } 

                    y=0;

                    for(int j=1;j<d;j++)
                    {
                        b[x][y] =A[z][j];
                        y++; 
                    }
                    x++;
                }
            }//we found out the M for each element & below we are multiplying it with (-1)^(p+q) to make it cofactor
            printArray(d-1,b);
            int p = detOf(d-1,b);
            printf("i=%d M=%d\n\n",i,p);
            if( (i+1) & 1 ) //checking if (i+1)+(j+1) is odd for cofactor ==> i+j ==> i+0 ==> i
                sum = sum - A[i][0]*p;
            else
                sum = sum + A[i][0]*p;
        }
        printf("Ans = %d \n",sum);
        return sum;
    }
    else
    {
        return ( (A[0][0]*A[1][1]) - (A[1][0]*A[0][1]) );
    }     
}

int main(){
    int d;
    scanf("%d",&d);
    int A[d][d];
    readArray(d,A);
    printArray(d,A);
    printf("\n");
    printf("%d",detOf(d,A));
    printf("\nDone");
    return 0;
}