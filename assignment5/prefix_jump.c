#include <stdio.h>
#include <stdlib.h>

long long int heights[1001][1001]={};
long long int prefix_1[1001][1001]={};
long long int prefix[1001][1001]={};

int cmp(const void * p1,const void * p2) {
  long long int* arr1 = (long long int*)p1;
  long long int* arr2 = (long long int*)p2;
  long long int diff1 = arr1[0] - arr2[0];
  return diff1;
}
int find_min(int i,int j)
{   
    int ct =0;
    for(int x=i;x>0;x--)
        if(prefix_1[x][j]!=0)
            ct++;
    return ct;
}

void find_max(int N,int i,int j,int * row,int * column)
{

    int max =0;
    int count=0;
    for(int x=i;x>0;x--)
        for(int y=j;y<=N;y++)
        {
            if(prefix[x][y]>max)
            {   
                // printf("comparing %lld and %d ==>",prefix[x][y],max);
                max=prefix[x][y];
                // printf("max became %d\n",max);
                *row=x;*column=y;
                count++;
                if(count==2)
                    break;
            }
        }
    if(max==0)
    {*row=-1;*column=-1;}
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    long long int h_p[N+1][2];
    for(int i=0;i<=N;i++)
        for(int j=0;j<2;j++)
            h_p[i][j]=0;
    for(int i=1;i<=N;i++)
    {
        scanf("%lld",&h_p[i][0]);
        h_p[i][1]=i;
    }
    qsort(h_p, (N+1), (2)*sizeof(long long int), cmp);

    // long long int heights[1001][1001]={};
    int i_temp=0;
    
    for(int i=0;i<=N;)
    {   
        int temp =i;
        while(h_p[temp][0]==h_p[temp+1][0])
        {
            temp++;
        }
        heights[i_temp][0]=h_p[i][0];
        heights[i_temp][h_p[i][1]]=1;
        for(int j=i+1;j<=temp;j++)
        {
            heights[i_temp][h_p[j][1]]=1;
        }
        i=temp+1;
        i_temp++;
    }

    for(int i=0;i<i_temp;i++)
    {   
        printf("%lld %lld ",heights[i][0],heights[i][1]);
        for(int j=2;j<=N;j++)
        {
            // heights[i][j]+=heights[i][j-1];
            printf("%lld ",heights[i][j]);
        }      
        printf("\n");
    }
    printf("\n");

    // long long int prefix_1[100][100]={};
    for(int i=0;i<i_temp;i++)
    {   
        prefix_1[i][0]=heights[i][0];
        prefix_1[i][N]=heights[i][N];
        for(int j=N-1;j>=1;j--)
            prefix_1[i][j]=heights[i][j]+prefix_1[i][j+1];
    }
    // for(int i=1;i<i_temp;i++)
    // {   
    //     printf("%2lld %lld ",prefix_1[i][0],prefix_1[i][1]);
    //     for(int j=2;j<=N;j++)
    //     {
    //         printf("%lld ",prefix_1[i][j]);
    //     }      
    //     printf("\n");
    // }
    // printf("\n");

    // long long int prefix[100][100]={};
    for(int i=1;i<i_temp;i++)
    {   
        prefix[i][0]=prefix_1[i][0];
        for(int j=1;j<N;j++)
        {   
            if(heights[i][j]==1)
                prefix[i][j]=find_min(i-1,j+1);
        }
    }
    for(int i=0;i<i_temp;i++)
    {   
        printf("%2lld ",prefix[i][0]);
        for(int j=1;j<=N;j++)
        {
            printf("%lld ",prefix[i][j]);
        }      
        printf("\n");
    }
    printf("\n");

    int flag =0;
    int count =0;
    int i=i_temp;
    int j;
    for(j=0;j<N;)
    {   
        int row,column;
        printf("\n%d %d\n",i-1,j+1);
        find_max(N,i-1,j+1,&row,&column);
        if(row == (-1)  && column==(-1))
        {
            flag=1;
            break;
        }
        else
        {
            count++;
            printf("from %d %d to",i-1,j+1);
            i=row;j=column;
            printf("% d %d\n",i,j);
        }
    }
    if(flag==1)
    {
        for(i=i-1;i>0;i--)
            for(j=j+1;j<=N;j++)
                if(heights[i][j]==1)
                {
                    count++;
                    break;
                }
    }
    printf("%d\n",count);
    return 0;
}

/*
12 5
1 6 3 15 5 4 5 4 4 6 3 2
*/