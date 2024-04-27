#include <stdio.h>
#include <stdlib.h>
float fun_1(int x)
{
    float m;
    m = 2*x*x-x+1;
    return m;
}

float fun_2(int x,int y)
{
    float n;
    n = x*x +y*y;
    return n;
}

int main()
{
    float sum_1,sum_2;
    int a,b;
    printf("input a: ");
    scanf("%d",&a);
    
    printf("input b: ");
    scanf("%d",&b);
    
    sum_1 = fun_1(a);
    printf("sum = %.1f",sum_1);
    
    sum_2 = fun_2(a,b);
    printf("\nsum = %.1f",sum_2);
    return 0;
}