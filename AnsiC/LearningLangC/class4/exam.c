/*给定三边长，海伦公式求三角形面积*/
#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c;
    int p,s;
    printf("input a b c \n");
    scanf("%d\n",&a);
    scanf("%d\n",&b);
    scanf("%d",&c);
    if((a+b>c)&&(a+c>b)&&(b+c>a)) //"&&"且；"||"或；
    {
        p = (a+b+c)/2 + (a+b+c)%2;
        s = sqrt(p*(p-a)*(p-b)*(p-c));
        printf("square=%d",s);
    }
    else
    {
        printf("can not be a triangle");
    }
}