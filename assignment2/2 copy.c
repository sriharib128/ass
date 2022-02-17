#include <stdio.h>
int main(){
    char hotel[100][32];
    int m_f[100][1];
    int f_f[100][1];
    int m_h=0,f_h=0;
    int max=0;
    for(int i=0;i<100;i++)
    {   
        printf("Enter members of floor %d",i);
        printf("\nEnter m for man and f for female\n");
        int m=0,f=0;
        for (int j=0;j<32;j++)
        {
            scanf("%c",&hotel[i][j]);
            
            if (hotel[i][j]=='m')
            {
                if(max<hotel[i][j]) max=i;
                m+=1;
            }   
            else if (hotel[i][j]=='f')
                f+=1;
        }
        m_h+=m;
        f_h+=f;
        m_f[i][0]=m; 
        f_f[i][0]=f;
        // if(i==2) break;                 
    }
    printf("the percentage of males = %f\n",(float)m_h*100/( m_h+f_h));
    printf("the percentage of females = %f\n",(float)f_h*100/(m_h+f_h));
    printf("Floor with maximum number of males = %d",max);
    
    for( int i=0;i<100;i++){
        printf("percentage of males in floor %d = %f",i,(float)m_f[i][0]*100/(m_f[i][0] + f_f[i][0]));
        printf("percentage of females in floor %d = %f",i,(float)f_f[i][0]*100/(m_f[i][0] + f_f[i][0]));
    }
    if(m_h%32 == 0){
        for (int i=0;i<=(m_h/32);i++){
            for (int j=0;j<32;j++)
            {   hotel[i][j] = 'm';
                hotel[100-i][j] ='f';
            }

        }}
    else {printf("It is not possible to redistribute");}
    
    return 0;
    
}