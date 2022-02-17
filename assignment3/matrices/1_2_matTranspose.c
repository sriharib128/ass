#include <stdio.h>

int main()
{
    int dim1,dim2;
    scanf("%d %d", &dim1, &dim2);
    int a[dim1][dim2];
    for(int i=0;i<dim1;i++)
        for(int j=0;j<dim2;j++)
            scanf("%d",&a[i][j]);

    int y=0;
    while(y<(dim2))
    {
        int * ptr = &a[0][y];
        
        while(ptr != &a[(dim1-1)][y])
        {   
            printf("%d ",*ptr);
            ptr+=dim2;
        }
        printf("%d\n",*ptr);
        y++;
    }
return 0;
}

/*
3 5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15

5 3
1 6 11
2 7 12
3 8 13
4 9 14
5 10 15
*/