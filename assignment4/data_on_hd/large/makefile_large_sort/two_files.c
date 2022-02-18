#include "include.h"

void merge_two_files(FILE *f1,FILE *f2,FILE *f3) 
{ 
    int flag1=0,flag2=0;
    char temp1[110];char temp2[110];
    int check=0;
    while(1)
    {
        if(flag1==0)
        {
            if(fscanf(f1,"%s",temp1)==EOF)
                {check=1;break;}
        }
        if(flag2==0)
        {
            if(fscanf(f2,"%s",temp2)==EOF)
                {check=2;break;}
        }    
        if(strcmp(temp1,temp2)<0)
        {
            fprintf(f3,"%s\n",temp1);
            flag1=0;
            flag2=1;
        }
        else if(strcmp(temp1,temp2)>0)
        {
            fprintf(f3,"%s\n",temp2);
            flag1=1;flag2=0;
        }
        else 
        {
            fprintf(f3,"%s\n%s\n",temp1,temp2);
            flag1=0;flag2=0;
        }
    }
    if(check==1)
    {
        if(flag2==1)
            fprintf(f3,"%s\n",temp2);
        while(fscanf(f2,"%s",temp2)!=EOF)
        {   fprintf(f3,"%s\n",temp2);}
    }
    else
    {   
        fprintf(f3,"%s\n",temp1);
        while(fscanf(f1,"%s",temp1)!=EOF)
        {   fprintf(f3,"%s\n",temp1);}
    }
}