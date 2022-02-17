#include <stdio.h> 
#include <stdlib.h>


int main ( int argc, char *argv[] ) 
{ 
    if ( argc != 4 ) /* argc should be 2 for ./a.out and filename.txt */ 
        printf( "usage: %s %s %s %s is provided, 3 file names are not provided\n", argv[0],argv[1],argv[2],argv[3]);
    
    else  
    { 
        FILE *file = fopen( argv[1], "r" );
        FILE *key = fopen( argv[2], "w" );   
        FILE *fisol = fopen( argv[3], "w" ); 
        if ( file == 0 ) 
            printf( "Could not open file\n" ); 
        
        else  
        { 
            int a[257];

            int seed =10000; // use for randomize number   
            srand (seed);
            
            for(int i=1;i<128;i++)
            {  
                a[i]=rand()%2;
                fprintf(key, "%d",a[i]);
            }
            fclose(key);
            for(int i=128;i<256;i++)
            {  
                a[i]=a[i-1]^a[i-127];
            }
            int x;
            int ct=1;
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
                int y=0;
                int z=128;
                for(int i=7;i>=0;i--)
                {   
                    int bit=( (x>>i)&1 );
                    fprintf(fisol, "%d", ( bit^a[ct+127] ) );
                
                    y+=(bit^a[ct+127])*z;
                    z=z/2;
                    ct++;

                }
            } 
            fclose(file);
            fclose(fisol); 
        } 
    } 
}