//斐波那契数列
#include <stdio.h>
#include <math.h>
int main()
{
    int i;
    int f1=1,f2=1;
    for(i=1;i<=9;i++)
    {
        f1=f1+f2;
        f2=f1+f2;
        printf("%d\n%d\n",f1,f2); //迭代算法
    }
}
