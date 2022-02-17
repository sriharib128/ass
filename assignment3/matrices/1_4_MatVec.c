#include <stdio.h>

int main()
{
    int dim1, dim2;
    scanf("%d", &dim1);
    scanf("%d", &dim2);
    long int a[dim1][dim2];

    int dim_1, dim_2;
    dim_1=dim2;
    scanf("%d", &dim_2);
    long int b[dim_1][dim_2];

    // Taking inut for vector 1
        for (int i = 0; i < dim1; i = i + 1)
            for (int j = 0; j < dim2; j = j + 1)
                scanf("%ld", &a[i][j]);
       
    // Talking input for vector 2
        for (int i = 0; i < dim_1; i = i + 1)
            for (int j = 0; j < dim_2; j = j + 1)
                scanf("%ld", &b[i][j]);

    // Storting the dot product in a new array
        long long int c[dim1][dim_2];
        for (int i = 0; i < dim1; i = i + 1)
        {
            for (int j = 0; j < dim_2; j = j + 1)
            {
                long long int s = 0;               
                for (int k =0 ; k<dim2 ; k++)
                    s +=a[i][k]*1LL*b[k][j];
                c[i][j] = s;
            }
        }

    //Printing the product array
        for(int i = 0 ; i<dim1;i=i+1 )
        {
            for (int j =0 ; j<dim_2;j=j+1)
                printf("%lld " , c[i][j]);
            printf("\n");
        }
    return 0;
}
