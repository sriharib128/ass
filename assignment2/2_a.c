#include <stdio.h>

int main(){
    long long int m,n; //n- floors , m- rooms
    scanf("%lld %lld",&n,&m);

    int hotel[n][m];
            
    long long int max_b_f=-1,max_f_f=-1;
    long long int max_b_n=-1,max_f_n=-1;

    for(int i=0;i<n;i++)
    {   
        long int b=0,f=0,e=0;
        for (int j=0;j<m;j++)
        {
            scanf("%d",&hotel[i][j]);
            
            if (hotel[i][j]==0)
                b+=1;
            else if (hotel[i][j]==1)
                f+=1;
            else if (hotel[i][j]==-1)
                e+=1;
        }

        //Finding floor with maximum males
        if(b!=0)
            {if (max_b_n<b) { max_b_n=b;  max_b_f=i;}}
        else if(b==0 && max_b_f==-1)
            max_b_f=-2;

        if(f!=0)
           { if (max_f_n<f) { max_f_n=f;  max_f_f=i;}}
        else if (f==0 && max_f_f==-1)
            max_f_f=-2;
    }

    printf("%lld %lld",(max_b_f+1),(max_f_f+1));
    return 0;
}