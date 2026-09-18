#include <stdio.h>
#include <math.h>

int main(){

    double x,y;
    printf("Input real x: \n");
    scanf("%lf", &x);

    y=cosh(x);
    printf("Cosh: %lf\n", y);
}