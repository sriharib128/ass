#include "include.h"

char * name(long long int temp)
{   
    char * f_name = (char *)malloc(100);
    strcpy(f_name,"f_");
    long long int n=0;
    if(temp%10==0 && temp>0)
    {
        while ( (temp%10) == 0 ) 
        {
            temp /= 10;
            n++;
        }
    }
        long long int reverse=0;
        while (temp != 0) 
        {
            int remainder = temp % 10;
            reverse = reverse * 10 + remainder;
            temp /= 10;
        }
        temp = reverse;
        while(temp!=0)
        {
            int rem = temp%10;
            temp=temp/10;
            if(rem==0)
                strcat(f_name,"0");
            else if(rem==1)
                strcat(f_name,"1");
            else if(rem==2)
                strcat(f_name,"2");
            else if(rem==3)
                strcat(f_name,"3");
            else if(rem==4)
                strcat(f_name,"4");
            else if(rem==5)
                strcat(f_name,"5");
            else if(rem==6)
                strcat(f_name,"6");
            else if(rem==7)
                strcat(f_name,"7");
            else if(rem==8)
                strcat(f_name,"8");
            else if(rem==9) 
                strcat(f_name,"9");
        }
    while(n>0)
    {
        strcat(f_name,"0");
        n--;
    }
    strcat(f_name,".txt");
    return f_name;
}



