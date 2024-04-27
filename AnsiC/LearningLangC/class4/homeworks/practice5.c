#include <stdio.h>
#include <math.h>
int main()
{
    float s,m;
    int m1;
    printf("行驶里程：");
    scanf("%f",&s);
    if(s>0 && s<=3)
        m=14;
    else if(s>3 && s<=15)
        m=(s-3)*2.5 + 14;
    else if(s>15)
        m=(s-15)*3.6 + 44;
    else
        printf("error"); 
    m1=m+0.5;
    printf("应付：%d元",m1);
}