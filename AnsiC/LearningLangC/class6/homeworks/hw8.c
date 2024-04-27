#include <stdio.h>
#include <math.h>
double func(double x)
{
    double y;
    y=2*pow(x,3)-4*x*x+3*x-6;
    return y;
}

int main()
{
    double x1=-10;
    double x2=10;
    double x0=(x1+x2)/2;
    while(fabs(func(x0))>1e-8)
    {
        if(func(x0)*func(x1)<0)
            x2=x0;
        else
            x1=x0;
        x0=(x1+x2)/2;
    }
    printf("%lf",x0);
}