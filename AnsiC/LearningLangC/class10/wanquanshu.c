#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int wanquan(int a)
{
    int flag;
    int i,s=0;
    for(i=1;i<a;i++)
    {
        if(a%i==0)
            s=s+i;
    }
    if(a==s)
        flag=1;
    else
        flag=0;
    return flag;
}

int main()
{
    int a;
    for(a=1;a<=1000;a++)
    {
        if(wanquan(a)==1)
            printf("%4d",a);
    }
}