#include <stdio.h>
#include <math.h>
int main()
{
    int i=500;
    while(i<=600)
    {
        if(i%5==0 && i%7==0)
            printf("%d\n",i);
        i=i+1;
    }
}