#include <stdio.h>
#include <math.h>

int main(){
    printf("Enter the no for student in a class");
    int n;
    scanf("%d",&n);
    int m[n];
    float b=0.0;
    float s=0;
    int max=0,min=100;
    printf("Enter n numbers");
    for (int i=0; i<n;i++){
        // scanf("%d",&m[i]);
        m[i]=i;
        //finding the max and min marks

        if(m[i]>max) max=m[i];
        else if(m[i]<min) min =m[i];

        //Finding the sum of numbers for mean
        s=s+m[i];
        if(m[i]<35){
            b++;
        }
    }
// Printing max and min
    printf("the max marks is %d and the min marks is %d",max,min);

// Pass percentage , class mean , variance , standard deviation
    float p = ((n-b)/n)*100;
    printf("\nthe class pass percentage is %f",p);
    float mean = s/n;
    printf("\nthe class mean is %f",mean);
    s=0;
    for(int i=0; i<n;i++)
        s+=((mean-m[i])*(mean-m[i]))/n;
    printf("\nthe class variance is %f",mean);
    float d = sqrt(s);
    printf("\nthe class SD is %f\n",d);

//One SD ,two SD, rest
    float x1 = mean-d;
    float x_1 = mean+d;
    float x2 = mean-(2*d);
    float x_2 = mean+(2*d);
    int s1=0,s2=0,s3=0;
    printf("%f %f %f %f",x2,x1,x_1,x_2);
    for (int i = 0; i<n;i++)
    {
        if(m[i]>x1 && m[i]<x_1)
            s1+=1;
        else if ((m[i]>x2 && m[i]<x1)||(m[i]<x_2 && m[i]>x_1))
            s2+=1;
        else 
            s3+=1;
    }
    printf("\nthe number of students falled within 1 SD are %d\n",s1);
    printf("the number of students falled within 2 SD are %d\n",s2);
    printf("the number of students falled within 2 SD are %d\n",s3);
    return 0;    
}