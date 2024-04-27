#include <stdio.h>
int main()
{
    int i;
    float sum;
    for(i=1,sum=0;i<100;i=i+2)
    {
        sum = sum+1.0/i;
    }
    printf("%f",sum);
}