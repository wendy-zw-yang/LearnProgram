#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("输入两个整数：\n");
    scanf("%d",&a);
    scanf("%d",&b);
    if(a<=b)
        printf("max=%d",b);
    else
        printf("max=%d",a);
}