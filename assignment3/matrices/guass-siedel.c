#include <stdio.h>

void readArray(int d,double A[][d])
{
    for(int i=0;i<d-1;i++)
        for(int j=0;j<d;j++)
            scanf("%lf",&A[i][j]);
}
void printArray(int d,double A[][d])
{
    for(int i=0;i<d-1;i++)
    {
        for(int j=0;j<d;j++)
            printf("%0.0lf ",A[i][j]);
        printf("\n");
    }
}

double fabs(double x)
{
    if(x<=0)
        return (x*(-1));
    else 
        return x;
}

double maxOf(int d,double A[][d],int i )
{   
    double max = -1;
    int maxcolumn = -1;
    for(int j =0;j<=d-2;j++)
    {
        if(max<A[i][j])
            {max=A[i][j];maxcolumn = j;}
    }
    return maxcolumn;
}

void makeDiagDomi(int d , double A[][d])
{   
    int ct =0;
    int s[d-1];
    int stemp[d-1];
    for(int i=0;i<=d-2;i++)
        {
            s[i] = maxOf(d,A,i);
            stemp[i]=-1;
        }
    for(int i=0;i<=d-2;i++)
           stemp[s[i]] = i; 
    
    for(int i=0;i<=d-2;i++)
    {
        if(stemp[i]==-1)
            ct++;
    }

    if(ct==0)
    {
        double temp[d-1][d];

        for(int i=0;i<=d-2;i++)
            for(int j=0;j<=d-1;j++)
                    temp [s[i]][j] = A[i][j];

        for(int i=0;i<=d-2;i++)
            for(int j=0;j<=d-1;j++)
                A[i][j] = temp[i][j]; 

    }
}


void siedel(int d, double A[][d],double r[],double er_per_req)
{
    // double er_p = 1e4;
    // while (er_p>er_per_req)

    while(er_per_req--)
    {
        double max =-1;

        for(int i=0;i<=d-2;i++)
        {
            // double temp = r[i];

            r[i]=A[i][d-1];
            for(int j=0;j<=d-2;j++)
            {
                if(j==i)
                    continue;
                else
                    r[i] = r[i] - (A[i][j] * r[j] );
            }
            r[i]= r[i]/A[i][i];

            // er_p = relEr(temp,r[i]);
            // if(er_p>max)
            //     max = er_p;
        }   
    }
    // printf("%lf",er_p);
}

int main()
{
    int d;
    scanf("%d",&d); // d= no of variables + 1
    double A[d-1][d];
    double r[d-1];
    
    //Our first guess is (0,0,0)
    for(int i=0;i<d-1;i++)
        r[i]=0;
    readArray(d,A);
    double er_per_req;
    // scanf("%lf",&er_per_req);

    //make sure that A is diagonaly dominant ==> max number of ith row is in ith column
    makeDiagDomi(d,A);

    printArray(d,A);

    er_per_req = 6;
    siedel(d,A,r,er_per_req);

    //printing our asnwers
    printf("(x,y,z) = ( ");
    for(int i=0;i<d-1;i++)
        printf("%0.6lf " , r[i]);
    printf(")");

    return 0; 
}
/*
4
3 7 13 76
1 5 3 28
12 3 -5 1
*/