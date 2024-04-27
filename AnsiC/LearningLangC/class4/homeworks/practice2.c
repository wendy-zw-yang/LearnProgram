#include <stdio.h>
#include <math.h>
int main()
{
    int num;
    int a,b,c;
    printf("输入一个10-1000的整数:\n");
    scanf("%d",&num);
    if(num<=10 || num>=1000)
    {
        printf("error");
        return 0;
    }
    a=num/100;
    b=(num-a*100)/10;
    c=(num-a*100-b*10);
    if(a<1)
    {
        printf("num为两位数\n");
        printf("这两位数分别为%d,%d\n",b,c);
        if(b==c)
            printf("这两位数逆序相等\n");
        else
            printf("这两位数逆序不相等\n");
    }
    else
    {
        printf("num为三位数\n");
        printf("这三位数分别为%d,%d,%d\n",a,b,c);
        if(a==c)
            printf("这三位数逆序相等\n");
        else
            printf("这三位数逆序不相等");
    }
}