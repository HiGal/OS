#include <limits.h>
#include <float.h>
#include <stdio.h>

int main(){
    int a = INT_MAX;
    double b = DBL_MAX;
    float c = FLT_MAX;
    printf("Size of integer is: %lu\n bytes", sizeof(int));
    printf("Size of double is: %lu\n bytes", sizeof(float));
    printf("Size of float is: %lu\n bytes", sizeof(double));

    printf("Value of max integer is: %d\n", a);
    printf("Value of max double is: %f\n", b);
    printf("Value of max float is: %f\n", c);
}

