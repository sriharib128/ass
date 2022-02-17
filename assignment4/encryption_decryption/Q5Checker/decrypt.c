#include <stdio.h> 
#include <stdlib.h>

int main ( int argc, char *argv[] ) 
{ 
    if ( argc != 4 ) /* argc should be 2 for ./a.out and filename.txt */ 
        printf( "usage: %s %s %s %s is provided, 3 file names are not provided\n", argv[0],argv[1],argv[2],argv[3]);
    
    else  
    { 
        FILE *key = fopen( argv[1], "r" );
        FILE *file = fopen( argv[2], "r" ); 
        FILE *fisol = fopen( argv[3], "w" ); 
        if ( file == 0 ) 
            printf( "Could not open file\n" ); 
        
        else  
        { 
            int a[257];
            char b[129];
            
            int j=1;
            char x;
            
            while  ( ( b[j++] = fgetc( key ) ) != EOF );
            fclose(key);
            
            for(int i=1;i<128;i++)
                a[i]=b[i]-'0';
            
            for(int i=128;i<256;i++)  
                a[i]=a[i-1]^a[i-127];

            int ct=1;
            int y=0,z=128,n=0;
            while  ( ( x = fgetc( file ) ) != EOF ) 
            { 
                if(ct==129)
                {
                    for(int i=1;i<128;i++)
                        a[i]=a[i+128];
                    for(int i=128;i<256;i++)
                        a[i]=a[i-1]^a[i-127];
                    ct=1;
                }
                int bit = (int)(x-'0');
                n++;
                if(n<=8)
                {
                    y+=(bit^a[ct+127])*z;
                    z=z/2;
                    ct++;
                }
                if(n==8)
                {
                    fprintf(fisol,"%c",(char)y);
                    y=0;z=128;n=0;
                }
            } 
            fclose(fisol);
            fclose(file); 
        } 
    } 
}