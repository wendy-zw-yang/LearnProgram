#include <stdio.h>
#include <math.h>
int main()
{
    int i=1;
    float sum=0;
    while(i<=50)
    {
        sum = sum + 2.0/(i*i+i);
        i=i+1;
    }
    printf("%f",sum);
}