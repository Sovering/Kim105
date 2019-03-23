#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a = 12.17f;
    float b = 7.03f;
    float x = 5.02f;

    double t = log(b-x);
    double s = a*x -t;

    double y = pow(s,0.2);

    printf("Result of f(%.5f,%.5f,%.5f) = %.5f\n", x,a,b,y);
    getchar();

    return 0;
}
