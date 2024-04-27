#include <stdio.h>
int main (void)
{
    printf("hello world!\n");
    int a,b,c;
    printf("please input one number:");
    scanf("%d",&a);
    printf("please input another number:");
    scanf("%d",&b);
    c = a + b;
    printf("%d+%d=%d",a,b,c);
    return 0;
}
int 