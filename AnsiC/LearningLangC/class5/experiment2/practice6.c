#include <stdio.h>
int main()
{
    int a,b,c,s;
    printf("a = ");
    scanf("%d",&a);

    printf("b = ");
    scanf("%d",&b);

    printf("c = ");
    scanf("%d",&c);
    
    if(a>=b && a>=c)
    {
        if(b>c)
        printf("%d<%d<%d",c,b,a);
        else if(b==c)
        printf("%d=%d<%d",c,b,a);
        else
        printf("%d<%d<%d",b,c,a);
    }
    
    else if(b>=a && b>=c)
    {
        if(a>c)
        printf("%d<%d<%d",c,a,b);
        else if(a==c)
        printf("%d=%d<%d",c,a,b);
        else
        printf("%d<%d<%d",a,c,b);
    }
    
    else if(c>=a && c>=b)
    {
        if(a>b)
        printf("%d<%d<%d",b,a,c);
        else if(a==b)
        printf("%d=%d<%d",b,a,c);
        else
        printf("%d<%d<%d",a,b,c);
    }
}