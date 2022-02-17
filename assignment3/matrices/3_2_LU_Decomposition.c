#include <stdio.h>
#define N 1000000007

void readArray(int d,double A[][d])
{
    for(int i=0;i<d;i++)
        for(int j=0;j<d;j++)
            scanf("%lf",&A[i][j]);
}
void printArray(int d,double A[][d])
{
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {   
            double ans = A[i][j] + 0.0000000001;
            printf("%0.5lf ",ans);
        }
        printf("\n");
    }
}

long int detOfc(int d,double A[][d])
{  
    if(d>2)
    {   
        long int sum =0;
        for(int c=0;c<d;c++)
        {
            double b[d-1][d-1];
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
                sum = (sum - (detOfc(d-1,b)*(int)A[0][c]))%N;
            else
                sum = (sum + (detOfc(d-1,b)*(int)A[0][c]))%N;    
        }
        return sum;
    }
    else if(d==2)
    {   
        long int m;
        m=(( (A[0][0])*(A[1][1]) )) - (( (A[1][0])*(A[0][1]) ));
        return m;
    }
    else if(d==1)
        return A[0][0];
}

int ispossible(int d, double A[][d])
{
    int flag =1;
    for(int i=1;i<=d;i++)
    {
        if(detOfc(i,A)==0)
        {
            flag =0;
            break;
        }
    }
    return flag;
}

void L_U(int d , double A[][d] , double B[][d])
{
    for(int i=0;i<=d-1;i++)  
        for(int j=i+1;j<=d-1;j++)
        {   
            double m; 
            if(A[i][i]!=0)
                m = A[j][i] / A[i][i] ;
            else
                m=0;
            B[j][i] = m;
            for(int k=0;k<=d-1;k++)
                A[j][k] = A[j][k] - (A[i][k] * m);
        }
}

int main()
{
    int d;
    scanf("%d",&d);//no of variables + 1
    double A[d][d];
    readArray(d,A);
    if(ispossible(d,A)&&(d>1))
    {
        double B[d][d];
        for(int i=0;i<d;i++)
            for(int j=0;j<d;j++)
            {
                if(i!=j)
                    B[i][j]=0;
                else
                    B[i][j]=1;
            }
        L_U(d,A,B);
        printArray(d,B);
        printArray(d,A);
    }
    else if(ispossible(d,A)&&(d==1))
    {
        printf("%0.5lf\n",1.0);
        printf("%0.5lf",A[0][0]);
    }
    else
        printf("No LU decomposition");
    return 0;
}
