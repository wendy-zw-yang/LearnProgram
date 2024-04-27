#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c;
    for(a=1;a<=20;a++)
    {
        for(b=1;b<=33;b++)
        {
            c=100-a-b;
            if(5*a+3*b+c==100)
                printf("a=%d, b=%d, c=%d",a,b,c);
        }
    }
}