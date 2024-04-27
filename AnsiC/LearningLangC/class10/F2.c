#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int fac(int n)
{
    int i;
    int f1=1,f2=1,f3;
    if(n==1||n==2)
        return n;
    else if(n>2)
        for(i=1;i<=n;i++)
        {
            f3=f1+f2;
            f1=f2;
            f2=f3;
        }
        return f3;
}

int main()
{
    int n,i;
    int a;
    printf("input:");
    scanf("%d",&n);
    if(n==1)
        printf("1");
    else
        printf("1");
        for(i=1;i<n;i++)
        {
            a=fac(i);
            printf(",%d",a);
        }
}