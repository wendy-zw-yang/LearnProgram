#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int x;
    float y;
    printf("x=");
    scanf("%d",&x);
    if (x>1)
    {
        y=x*x+1;
    }
    else if (-1<=x&&x<=1)
    {
        y=exp(x)+x+1;
    }
    else
    {
        y=log(abs(x))+1;
    }
    printf("%f",y);
}