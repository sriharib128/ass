#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    for (int i =1;n>0;i++){
        for (int j=1;j<i && n>0 ; j++){
            for (int k=1;k<j&&n>0;k++){
                {
                if( ((long int)k*k + j*j) == (long int)i*i ){
                    printf("%d %d %d\n",k,j,i);
                    n--;
                }
            }}
        }
    }
    return 0;
}

//     int a,b,c;
//     scanf("%d%d%d",&a,&b,&c);
//     // scanf("%d",&b);
//     // scanf("%d",&c);
//     if ((a*a) == (b*b) + (c*c)){
//             printf("YES");
//         }

//     else if ((b*b) == (a*a) + (c*c)){
//             printf("YES");
//         }

//     else if ((c*c) == (a*a) + (b*b)){
//             printf("YES");
//         }
//     else {
//         printf("NO");
//         }

//     return 0;
// }

    //Challenge Problem



    
    