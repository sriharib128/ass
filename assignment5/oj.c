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
int find_max(int N,int i_min,int i,int j,int * row,int * column)
{

    int max =0;
    int count=0;
    for(int x=i;x>i_min;x--)
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
    return max;
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
/*
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
*/
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
/*  
    for(int i=0;i<i_temp;i++)
    {   
        printf("%lld ",prefix[i][0]);
        for(int j=1;j<=N;j++)
        {
            printf("%lld ",prefix[i][j]);
        }      
        printf("\n");
    }
    printf("\n");
*/
// we have created an array which shows the max number of buildings 
// we can go to from all building

// sales man does not go to his frieds house or goes to his friends 
// and his friend throws him to a lower building
    int flag =0;
    int count =0;
    int i=i_temp;
    int j;
    for(j=0;j<N;)
    {   
        int row,column;
        // printf("\n%d %d\n",i-1,j+1);
        find_max(N,0,i-1,j+1,&row,&column);
        if(row == (-1)  && column==(-1))
        {
            flag=1;
            break;
        }
        else
        {
            count++;
            // printf("from %d %d to",i-1,j+1);
            i=row;j=column;
            // printf("% d %d\n",i,j);
        }
    }
    if(flag==1)
    {
        for(i=i-1;i>0;i--)
        {   
            int b=0;
            for(j=j+1;j<=N;j++)
                if(heights[i][j]==1)
                {
                    count++;
                    b=1;
                    break;
                }
            if(b==1)
                break;
        }
    }
    // printf("%d\n",count);
    // printf("i_temp = %d\n",i_temp);
    // printf("-----------------------------------------------------\n");
    // printf("-----------------------------------------------------\n");
// sales man goes to his friends house

    int k;
    for(k=0;k<i_temp;k++)
        if(heights[k][M]==1)
            break;
    flag =0;
    int ct =0;
    i=i_temp;
    for(j=0;j<M;)
    {   
        int row,column;
        // printf("\n%d %d %lld\n",i-1,j+1,prefix[k][0]);
        find_max(M,(k-1),i-1,j+1,&row,&column);
        if(row == (-1)  && column==(-1))
        {
            flag=1;
            break;
        }
        ct++;
        // printf("from %d %d to ",i-1,j+1);
        i=row;j=column;
        // printf("%d %d\n",i,j);
    }
    if(k==(i_temp-1))
    {
        // printf("k=%d i_temp=%d M=%d\n",k,i_temp,M);
        for(int l=1;l<M;l++)
            if(heights[i_temp-1][l]==1)
            {
                if(prefix[i_temp-1][l]!=0)
                {   
                     if(flag==0) 
                    {   ct=1;
                        break;  }
                    else
                    {
                        ct=0;
                        break;
                    }  
                  }
            }
    }
    // printf("\ncount till now = %d\n\n",ct);
    // printf("---------went to Mth building---------------------\n\n");
    if(flag==1)
    {
        // printf("flag ==01");
        //no smaller buildin after mth building
        // printf("jumped from %d %d to ",i,j);
        i=k;j=M;
        // printf("%d %d\n\n",i,j);
        ct++;
        // printf("\ncount till now = %d\n\n",ct);
        flag=0;
    }
// sales man must decide which house he must
// go to from friend's house
    int row,column;
    int flag2=0;

    find_max(N,0,(i_temp-1),(M+1),&row,&column);
    // printf("jumped from %d %d to ",i,j);
    // printf("%d %d\n\n",row,column);

    if(row == (-1)  && column==(-1))
        flag2=1;
    else
        ct++;
    // printf("count till now = %d\n\n",ct);
// from the building he jumped to
    // printf("---------------------------\n");
    if(flag2==0)
    {   
        // printf("flag2 ==00");
        flag=0;
        i=row;
        for(j=column;j<N;)
        {   
            // printf("\n%d %d\n",i-1,j+1);
            find_max(N,0,i-1,j+1,&row,&column);
            if(row == (-1)  && column==(-1))
            {
                flag=1;
                // printf("breaked in flag2=0\n");
                break;
            }
            else
            {
                ct++;
                // printf("from %d %d to",i-1,j+1);
                i=row;j=column;
                // printf("% d %d\n",i,j);
                // printf("count till now = %d\n",ct);
            }
        }
    }
    else
    {
        // printf("flag2=1\n");
        int b=0;
        for(i=N-1;i>0;i--)
        {
            for(j=M+1;j<=N;j++)
                if(heights[i][j]==1)
                {
                    ct++;
                    // printf("count became %d\n",ct);
                    b=1;
                    break;
                }
            if(b==1)
                break;
        }
        flag=0;
    }

    if(flag==1)
    {
        int temp =j+1;
        // printf("flag = 1\n");
        for(i=i-1;i>0;i--)
        {   
            int b=0;
            for(j=temp;j<=N;j++)
            {
                // printf("%d %d\n",i,j);
                if(heights[i][j]==1)
                {
                    ct++;
                    // printf("count became %d\n",ct);
                    b=1;
                    break;
                }
            }
            if(b==1)
                break;
        }
    }
    // printf("%d\n",ct);
    if(ct>count)
        printf("%d",ct);
    else
        printf("%d",count);
    return 0;
}
