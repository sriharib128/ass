#include <stdio.h>

void main(){
    int a,b,c;
    printf("enter a number");
    scanf("%d",&a);
    printf("enter a number");
    scanf("%d",&b);
    printf("enter a number");
    scanf("%d",&c);
    if ((a*a) == (b*b) + (c*c)){
            printf("%d,%d,%d are a pythagorean triplets",a,b,c);
        }

    else if ((b*b) == (a*a) + (c*c)){
            printf("%d,%d,%d are a pythagorean triplets\n",a,b,c);
        }

    else if ((c*c) == (a*a) + (b*b)){
            printf("%d,%d,%d are a pythagorean triplets\n",a,b,c);
        }
    else {
        printf("%d,%d,%d are not a pythagorean triplets\n",a,b,c);
        }

    //Challenge Problem
    printf("enter the number of pythgorean triplets u want");
    int n;
    scanf("%d",&n);
    for (int i =1;n>0;i++){
        for (int j=1;j<i && n>0 ; j++){
            for (int k=1;k<j&&n>0;k++){
                if((k*k + j*j) == i*i){
                    printf("\n(%d,%d,%d)\n",k,j,i);
                    n--;
                }
            }
        }
    }
    }




    
    