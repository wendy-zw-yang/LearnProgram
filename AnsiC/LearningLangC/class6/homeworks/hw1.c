#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    float s;
    s=0;
    n=1;
    while(fabs((2.0*n+1.0)/(2*n*2*n))>1e-3)
    {
        s=s+pow(-1,n-1)*(2.0*n+1.0)/(4*n*n);
        n=n+1;
    }
    printf("%f",s);
}
/* sqrt(x):开根号，pow(x,y)：x的y次方，exp(x)，fabs(x)：浮点型绝对值
abs(x)：绝对值，sin(x)：弧度的sin值，log(x)：lg */