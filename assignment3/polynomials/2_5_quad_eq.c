#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    while(t--)
    {
        int a,b,c;
        scanf("%d %d %d",&a , &b , &c);
        double d = b*b - (4*a*c);
        double ans,real,imagi;
        if(d>=0)
        {
            ans = (-b + sqrt(d))/( (double)2*a );
            printf("%0.7lf %0.7lf\n",ans,0.0);
            ans = (-b - sqrt(d))/( (double)2*a );
            printf("%0.7lf %0.7lf\n",ans,0.0);
        }
        else
        {
            d*=-1;
            real = -b/((double)2*a);
            imagi = sqrt(d)/(2*a);
            printf("%0.7lf %0.7lf\n",real,imagi);
            imagi = -sqrt(d)/(2*a);
            printf("%0.7lf %0.7lf\n",real,imagi);
        }
    }
}