#include <stdio.h>

void readArray(int d,double A[][d])
{
    for(int i=0;i<d-1;i++)
        for(int j=0;j<d-1;j++)
            scanf("%lf",&A[i][j]);
    for(int i=0;i<d-1;i++)
        scanf("%lf",&A[i][d-1]);
}

void forwardElimination(int d , double A[][d])
{
    for(int i=0;i<=d-2;i++)
       
        for(int j=i+1;j<=d-2;j++)
           {    
                double m = A[j][i] / A[i][i] ;

                for(int k=0;k<=d-1;k++)

                    A[j][k] = A[j][k] - (A[i][k] * m);
           }
}

void backSubstitution(int d, double A[][d] , double r[])
{
    for(int i=d-2;i>=0;i--)
    {
        r[i] = A[i][d-1];
        
        for(int j=i+1;j<=d-2;j++)
        
            r[i] = r[i] - A[i][j]*r[j]; 
        
        r[i] = (double)r[i]/A[i][i];
    }
}

int main()
{
    int n;
    scanf("%d",&n);//no of variables
    int d=n+1;//d=no of variables+1
    double A[d-1][d];
    double r[d-1];//solution array
    
    readArray(d,A);

    forwardElimination(d,A);
    backSubstitution(d,A,r);    
 
    for(int i=0;i<d-1;i++)
        printf("%0.7lf\n" , r[i]);

    return 0;
}

/*
4x - 3y + z = - 10
2x + y + 3z = 0
- x + 2y - 5z = 17

(x, y, z) = (1, 4, - 2)

4                   
4 -3 1 -10
2 1 3 0
-1 2 -5 17

5
2 -3 5 1 41
7 2 -1 0 -28
-1 2 -7 -2 46
3 7 -6 1 31
*/