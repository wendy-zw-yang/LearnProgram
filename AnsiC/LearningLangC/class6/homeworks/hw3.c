#include <stdio.h>
#include <math.h>
int main()
{
    int i,j;
    float sum=1;
    for(i=2;i<=20;i++)
    {
        sum=sum+1;
        for(j=2;j<=i;j++)
        {
            sum=sum+j*10+0.5;
        }
    }
    printf("%f",sum);
}