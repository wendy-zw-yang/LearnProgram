#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c,s;
    printf("a = ");
    scanf("%d",&a);
    
    printf("\nb = ");
    scanf("%d",&b);
    
    printf("\nc = ");
    scanf("%d",&c);
    if(a+b>c && a+c>b && b+c>a)
    {
        s=a+b+c;
        printf("该三角形的周长为%d",s);
        if(a==b && b==c)
            printf("\n为等边三角形");
        else if(a==b||b==c||a==c)
            printf("\n为等腰三角形");
        else if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
            printf("\n为直角三角形");
        else
            return 0;
    }
    else
    {
        printf("error: 不是三角形");
    }
}