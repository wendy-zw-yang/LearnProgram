#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int sum(int a)
{
    int s=0,t;
    while(a!=0)
    {
        t=a%10;
        s+=t;
        a=a/10;
    }
    return s;
}
//定义任意一个整数各数位之和的函数

int main()
{
    int num,s;
    srand((unsigned)time(NULL));
    num = rand() % (9999-1000+1) + 1000; //产生一个1000-9999的随机数
    s=sum(num);
    printf("%d",s); //printf("%d",sum(num));
    return 0;
}