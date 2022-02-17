#include <stdio.h>

int main(){
    int c;
    scanf("%d",&c);
    int n=100;
    int a[n][3];
    int g=0;

    for (int i=1;n>0;i++)
    {
        for (int j=1;j<i && n>0 ; j++)
        {
            for (int k=1;k<j && n>0;k++)
            {
                if((k*k + j*j) == i*i)
                {
                    a[g][0]=k;
                    a[g][1]=j;
                    a[g][2]=i;
                    // printf("%d ",a[n-1][0]);
                    n--;g++;

                }
            }
        }
    }
    
    for (int i = 0; i < 100-1; i++)      
  
       // Last i elements are already in place   
       for (int j = 0; j < 100-i-1; j++) 

           if (a[j][0] > a[j+1][0])
            //swap(&arr[j], &arr[j+1]);
            {
                int temp=a[j][0];
                a[j][0]=a[j+1][0];
                a[j+1][0]=temp;

                temp=a[j][1];
                a[j][1]=a[j+1][1];
                a[j+1][1]=temp;

                temp=a[j][2];
                a[j][2]=a[j+1][2];
                a[j+1][2]=temp;
            }

            else if((a[j][0]==a[j+1][0]) && (a[j][1] > a[j+1][1]))
            {
                int temp=a[j][0];
                a[j][0]=a[j+1][0];
                a[j+1][0]=temp;

                temp=a[j][1];
                a[j][1]=a[j+1][1];
                a[j+1][1]=temp;

                temp=a[j][2];
                a[j][2]=a[j+1][2];
                a[j+1][2]=temp;
            }

    for (int i = 0; i < c; i++)
        printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);

    return 0;
}



    
    