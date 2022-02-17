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

int detOfc(int d,int A[][d])
{   if(d>2)
    {   
        int sum =0;
        for(int c=0;c<d;c++)
        {
            int b[d-1][d-1];
            int y=0;
            for(int j=0;j<d;j++)
            {   
                if(j==c)
                    continue;
                int x=0;
                for(int k=1;k<d;k++)
                {
                    b[x][y] = A[k][j];
                    x++;
                }
                y++;                    
            }

            if(c&1)
                sum = sum - detOfc(d-1,b)*A[0][c];
            else
                sum = sum + detOfc(d-1,b)*A[0][c];
        }
        return sum;
    }
    else
    {
        int m=( A[0][0]*A[1][1] ) - ( A[1][0]*A[0][1] );
        return m;
    }
}


int main(){
    int d;
    scanf("%d",&d);
    int A[d][d];
    readArray(d,A);
    printf(" \n Ans = %d \n",detOfc(d,A));
    return 0;
}