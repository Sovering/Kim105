#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void first_task(void);
double func(double);

int main(int argc, char *argv[])
{
    first_task();
    return 0;
}

void first_task()
{
    FILE *fp;
    fp = fopen("first_task.txt", "w");

    double a = -M_PI/2, b = M_PI/2, h = 0.3, s = (func(a) + func(b))/2;
    int n = (b - a)/h;

    fprintf(fp, "\tTabulation\n");
    fprintf(fp, "x:\t");
    for (double x = a; x <= b; x += h)
    {
        char c = x + h < b ? '\t' : '\n';
        fprintf(fp, "%.3f%c", x, c);
    }
    fprintf(fp, "y:\t");
    for (double x = a; x <= b; x += h)
    {
        char c = x + h < b ? '\t' : '\n';
        fprintf(fp, "%.3f%c", func(x), c);
    }

    for (int i = 1; i <= n-1; ++i)
  {
    s += func(a + i * h);
  }
  double integral = h * s;
  fprintf(fp, "\n\nIntegral [%.1lf, %.1lf]\t%lf", a, b, integral);

    fprintf(stderr, "The task completed without failure.\n\n");
}

double func(double x){
    if (x <= -M_PI/4){
        return sin(x*x-1);
    } else if (- M_PI/4 < x){
        return asin (x*2*cos(x)*sin(x));
    } else if(x >0){
        return sin(x-2);
    }
}
