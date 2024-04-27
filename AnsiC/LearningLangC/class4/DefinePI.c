#define PI 3.1415926
#include <stdio.h>
#include <math.h>
/* sqrt(x):开根号，pow(x,y)：x的y次方，exp(x)，fab(x)：浮点型绝对值
abs(x)：绝对值，sin(x)：弧度的sin值，log(x)：lg */

int main()
{
    printf("r=?\n");
    float r,s;
    scanf("%f",&r);
    s = PI * r * r;
    printf("%f",s);
}