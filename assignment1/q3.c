#include <math.h>
#include <stdio.h>

void main() {
   float number, squareRoot;

   printf("Enter a number: ");
   scanf("%f", &number);

   squareRoot = sqrt(number);

   printf("Square root of %f =  %f\n", number, squareRoot);

}