#include <stdio.h>
int A[10][10];
int d;
/*
4x - 3y + z = - 10
2x + y + 3z = 0
- x + 2y - 5z = 17

(x, y, z) = (1, 4, - 2)
*/

void readArray(int d,int A[][d])
{
    for(int i=0;i<d-1;i++)
        for(int j=0;j<d;j++)
            scanf("%d",&A[i][j]);
}
void printArray(int d,int A[][d])
{
    for(int i=0;i<d-1;i++)
    {
        for(int j=0;j<d;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
}

int main()
{
    int d;
    scanf("%d",&d);//no of variables + 1
    readArray(d,A);
    printArray(d,A);
    return 0;
}