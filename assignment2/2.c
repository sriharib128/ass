#include <stdio.h>
int main(){
    char hotel[100][32];
            
    int max_sum=0,max_f=0;
    int sum_m =0;

    for(int i=0;i<100;i++)
    {   
        printf("Enter members of floor %d",i);
        printf("\nEnter m for man and f for female\n");
        int m=0,f=0;
        for (int j=0;j<32;j++)
        {
            scanf("%c",&hotel[i][j]);
            
            if (hotel[i][j]=='m')
                m+=1;
             
            else if (hotel[i][j]=='f')
                f+=1;
        }
        sum_m += m;
        //Finding floor with maximum males
        if (max_sum<m) { max_sum=m;  max_f=i; }

        //Percentage of males and females in each floor
        printf("(D)The percentage of males and females in this floor(%d) are %f and %f",i,( float) m*100/(m+f) , (float) f*100/(m+f) );              
    }
    printf("\n(C)Floor with maximum number of males is %d with %d number of men ",max_f,max_sum);
    printf("\n(A)Total percentage of men in the hotel is %f and women is %f",((float)sum_m*100/3200) , 100-((float)sum_m*100/3200) );

//(D) Redistributing everyone so that there ara only males or females in a floor
    if(sum_m%32 == 0)
    {
        for (int i=0;i < sum_m/32 ;i++ )
            for(int j=0;j<32;j++)    
            {
                hotel[i][j] = 'm';
                hotel[100-i][j] = 'f';    
            }
    }
    else 
        printf("It is not possible to redistribute");    
    return 0;    
}
