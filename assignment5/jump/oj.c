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
        prefix_1[i][0]=heights[i][0];
        prefix_1[i][N]=heights[i][N];
        for(int j=N-1;j>=1;j--)
            prefix_1[i][j]=heights[i][j]+prefix_1[i][j+1];
    }
    for(int i=1;i<i_temp;i++)
    {   
        prefix[i][0]=prefix_1[i][0];
        for(int j=1;j<N;j++)
        {   
            if(heights[i][j]==1)
                prefix[i][j]=find_min(i-1,j+1);
        }
    }
// ==========================================================
int count = 0;
    // printf("i_temp=%d\n",i_temp);
    int row_temp=i_temp-1,col_temp=1;
    for(int b=0;b<=N;)
    {   
        int i,j;
        int row=-1, column=-1;
        int max = 0;

        int temp=0;
        for(j=col_temp;j<=N;j++)
        {   
            for(i = row_temp;i>temp;i--)
            {   
                if(max<prefix[i][j])
                {
                    row=i;column=j;
                    max=prefix[i][j];
                }
                else
                {
                    if(max!=0 && prefix[i][j]!=0)
                        temp=row;
                }
            }
            if(temp==(i_temp-1))
                break;
        }
        if(row==(-1))
        {   
            // printf("ended at %d %d\n",row_temp,col_temp);
            int flag=0;
            for(j=col_temp;j<=N;j++)
            {    
                for(i=row_temp;i>0;i--)
                    if(heights[i][j]==1)
                    {
                        count++;
                        // printf("added %d %d\n",i,j);
                        flag=1;
                        break;
                    }
                if(flag==1)
                    break;
            }
            break;
        }
        else
        {
            count++;
            b=column;
            col_temp=column+1;
            row_temp=row-1;
            // printf("jumped to %d %d\n",row,column);
        }
    }
    // printf("count = %d\n",count);  
    // ==========================================================
    // ==========================================================
    // ==========================================================
// crossed without talking his friend's help 
//------------------------------------------------------------
    int k;
    for(int i=i_temp-1;i>0;i--)
    {
        if(heights[i][M]==1)
            k=i;
    }
    // printf("k= %d heights[k][0]=%lld\n",k,heights[k][0]);
    //found the (k,M)height and position of hit friends building
//----------------------------------------------------------
// =======jumping on building before mth house
    int ct = 0;
    // printf("i_temp=%d\n",i_temp);
    row_temp=i_temp-1;col_temp=1;
    for(int b=0;b<M;)
    {   
        int i,j;
        int row=-1, column=-1;
        int max = 0;

        int temp=0;
        for(j=col_temp;j<M;j++)
        {   
            for(i = row_temp;i>k;i--)
            {   
                if(max<prefix[i][j])
                {
                    row=i;column=j;
                    max=prefix[i][j];
                }
                else
                {
                    if(max!=0 && prefix[i][j]!=0)
                        temp=row;
                }
            }
            if(temp==(i_temp-1))
                break;
        }
        if(row==(-1))
        {   
            // printf("ended at %d %d\n",row_temp,col_temp);
            break;
        }
        else
        {
            ct++;
            b=column;
            col_temp=column+1;
            row_temp=row-1;
            // printf("jumped to %d %d\n",row,column);
        }
    }
    // printf("count = %d\n\n",ct);  
    // ==============counted till before mth building===============
    row_temp=k;col_temp=M;
    // printf("jumped to %d %d\n",row_temp,col_temp);
    ct++;
    // printf("count = %d\n\n",ct);
    // ==============counted mth building==========================
    // find max building he can jump to from mth building
    row_temp=i_temp-1;
    col_temp=M+1;
    int i,j;
    int row=-1, column=-1;
    int max = 0;
    int temp=0;
    int terminate=0;
    for(j=col_temp;j<=N;j++)
    {   
        for(i = row_temp;i>temp;i--)
        {   
            if(max<prefix[i][j])
            {
                row=i;column=j;
                max=prefix[i][j];
            }
            else
            {
                if(max!=0 && prefix[i][j]!=0)
                    temp=row;
            }
        }
        if(temp==(i_temp-1))
            break;
    }
    if(row==(-1))
    {   
        // printf("ended at %d %d\n",row_temp,col_temp);
        int flag=0;
        for(j=col_temp;j<=N;j++)
        {    
            for(i=row_temp;i>0;i--)
                if(heights[i][j]==1)
                {
                    ct++;
                    // printf("added %d %d\n",i,j);
                    flag=1;
                    break;
                }
            if(flag==1)
                break;
        }
        terminate=1;        
    }
    else
    {
        ct++;
        // printf("jumped to %d %d\n",row,column);
        // printf("count = %d\n\n",ct);
        col_temp=column+1;
        row_temp=row-1;
        // printf("searching again from %d %d\n",row_temp,col_temp);        
    }
    // ==============counting from mth building===================
    if(terminate!=1)
    {
        for(int b=col_temp;b<=N;)
        {   
            row=-1;column=-1;
            max = 0;
            temp=0;
            for(j=col_temp;j<=N;j++)
            {   
                for(i = row_temp;i>temp;i--)
                {   
                    if(max<prefix[i][j])
                    {
                        row=i;column=j;
                        max=prefix[i][j];
                    }
                    else
                    {
                        if(max!=0 && prefix[i][j]!=0)
                            temp=row;
                    }
                }
                if(temp==(i_temp-1))
                    break;
            }
            if(row==(-1))
            {   
                // printf("ended at %d %d\n",row_temp,col_temp);
                int flag=0;
                for(j=col_temp;j<=N;j++)
                {    
                    for(i=row_temp;i>0;i--)
                        if(heights[i][j]==1)
                        {
                            ct++;
                            // printf("added %d %d\n",i,j);
                            flag=1;
                            break;
                        }
                    if(flag==1)
                        break;
                }
                break;
            }
            else
            {
                ct++;
                b=column;
                col_temp=column+1;
                row_temp=row-1;
                // printf("jumped to %d %d\n",row,column);
            }
        }
    }
    // printf("count_new = %d\n",ct); 
    if(ct>count)
        printf("%d",ct); 
    else
        printf("%d",count);
    return 0;
}