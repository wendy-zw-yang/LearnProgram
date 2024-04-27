#include <stdio.h>
#include <math.h>
int prime(int x)
{
    int n;
    for(n=2;n<x;n++)
    {
        if(x%n==0)
            return 0;
    }
    return 1;
}

int main()
{
    int i=3;
    while(i<=300)
    {
        if(prime(i)==1)
            printf("%d\n",i);
        i=i+1;
    }
}