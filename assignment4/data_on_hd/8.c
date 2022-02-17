#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000010

int main ( int argc, char *argv[] ) 
{ 
    FILE * f1=fopen(argv[1],"r");
    FILE * f2=fopen(argv[2],"r");
    FILE * op=fopen(argv[3],"w");

    int flag1=0,flag2=0;
    char temp1[20];char temp2[20];
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
            fprintf(op,"%s\n",temp1);
            flag1=0;
            flag2=1;
        }
        else if(strcmp(temp1,temp2)>0)
        {
            fprintf(op,"%s\n",temp2);
            flag1=1;flag2=0;
        }
        else 
        {
            fprintf(op,"%s\n%s\n",temp1,temp2);
            flag1=0;flag2=0;
        }
    }
    if(check==1)
    {
        if(flag2==1)
            fprintf(op,"%s\n",temp2);
        while(fscanf(f2,"%s",temp2)!=EOF)
        {   fprintf(op,"%s\n",temp2);}
    }
    else
    {   
        fprintf(op,"%s\n",temp1);
        while(fscanf(f1,"%s",temp1)!=EOF)
        {   fprintf(op,"%s\n",temp1);}
    }

    return 0;
}