#include <stdio.h>

int main()
{

    int dim1;
    scanf("%d", &dim1);
    long int a[dim1][dim1];

        // Taking inut for vector 1

        for (int i = 0; i < dim1; i = i + 1)
            for (int j = 0; j < dim1; j = j + 1)
            {   
                scanf("%ld", &a[j][i]);
            }

        /*
        for (int i = 0; i < dim1; i++)
        {
            for (int j = i+1; j < dim1;j++)
            {
                long int s= a[j][i];
                a[j][i] = a[i][j];
                a[i][j] = s;
            }
        }*/

        for (int i = 0; i < dim1; i = i + 1)
        {
            for (int j = 0; j < dim1; j = j + 1)
                printf("%ld ", a[i][j]);
            printf("\n");
        }
}
