#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    float sum;
    sum=0;
    n=1;
    while(fabs(1.0/n)>=1e-7)
    {
        sum=sum+1.0/n;
        n=n+2;
    }
    printf("%f",sum);
}