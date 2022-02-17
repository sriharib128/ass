#include <stdio.h>

void printArray(int dim1,int dim2,int a[][dim2])
{
    for(int i=0;i<dim1;i++)
    {
            for(int j=0;j<dim2;j++)
            printf("%d ",a[i][j]);
       printf("\n");
    }
}

int main()
{
    int dim1,dim2;
    scanf("%d %d", &dim1, &dim2);

    int a[dim1][dim2];

    for(int i=0;i<dim1;i++)
        for(int j=0;j<dim2;j++)
            scanf("%d",&a[i][j]);

    printArray(dim1,dim2,a);
return 0;
}
