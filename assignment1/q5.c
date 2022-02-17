#include <stdio.h>

void main()
{
    printf("Enter the no of dim u wnat in the vector1");
    int dim1, dim2;
    scanf("%d", &dim1);
    scanf("%d", &dim2);
    int a[dim1][dim2];
    printf("Enter the no of dim u wnat in the vector2");

    int dim_1, dim_2;
    scanf("%d", &dim_1);
    scanf("%d", &dim_2);
    int b[dim1][dim2];
    // CHeking if dot product is possible
    if (dim_1 != dim2)
    {
        printf("the dot product is not possible");
    }
    else
    {
        // Taking inut for vector 1
        for (int i = 0; i < dim1; i = i + 1)
        {

            for (int j = 0; j < dim2; j = j + 1)
            {
                printf("enter the %dth  row and %dth column in vector 1", i, j);
                scanf("%d", &a[i][j]);
                // a[i][j] = 1;
            }
        }
        // Talking input for vector 2
        for (int i = 0; i < dim_1; i = i + 1)
        {
            for (int j = 0; j < dim_2; j = j + 1)
            {
                printf("enter the %dth  row and %dth column in vector 2", i, j);
                scanf("%d", &b[i][j]);
                // b[i][j]=1;
            }
        }
        // Storting the dot product in a new array
        int c[dim1][dim_2];
        int z=0;
        for (int i = 0; i < dim1; i = i + 1)
        {
            for (int j = 0; j < dim_2; j = j + 1)
            {
                int s = 0;               
                
                for(int q=0;q<dim_2;q++){
                    for (int k =0 ; k<dim2 ; k++){
                        s += a[z][k]*b[k][q];
                    }                       
                c[i][j] = s;
                
                }
            }
            z++;
        }
        //Printing the product array
        for(int i = 0 ; i<dim1;i=i+1 )
        {
            for (int j =0 ; j<dim_2;j=j+1)
            {
                printf("%5d" , c[i][j]); // 5d ==> 5colums are allocated to prnt that value
            }   
            printf("\n");
        }
    }
}
