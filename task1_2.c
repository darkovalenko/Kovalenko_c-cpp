#include <stdio.h>
#include <math.h>

int main() {
    float x = 0.0001f; 
    double x1 = 24.33E5; 
    long double x2 = 1e-4L; 

    printf("%.2g\n", x);
    printf("%.2lf\n", x1);
    printf("%.2Lf\n", x2);

    double pi = M_PI; 
    printf("%.2lf\n", pi);

    double e = M_E; 
    printf("%.2lf\n", e);

    long double sq5 = sqrtl(5.0L);
    printf("%.2Lf\n", sq5);

    long double ln100 = logl(100.0L); 
    printf("%.2Lf\n", ln100);

    return 0;
}