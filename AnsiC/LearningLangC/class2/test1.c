#include <stdio.h>
#include <studlib.h>

int add(int x,int y)
{
    int z;
    z = x*x + y*y;
    return(z);
}

int main() //主函数
{
    int a,b,sum;
    a = 10;
    b = 24;
    sum = add(a,b);
    printf("%d\n", sum);

}