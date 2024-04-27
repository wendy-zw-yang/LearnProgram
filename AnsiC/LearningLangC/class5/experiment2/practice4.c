#include <stdio.h>
int main()
{
    int a,b,s;
    char opr;

    printf("请输入一个数字: ");
    scanf("%d",&a);

    printf("\n请输入运算符:");
    rewind(stdin);
    scanf("%c", &opr);

    printf("\n请输入另一个数字: ");
    scanf("%d",&b);
    
    if(opr=='+')
        s=a+b;
    else if(opr=='-')
        s=a-b;
    else if(opr=='*')
        s=a*b;
    else if(opr=='/'||opr==':')
    {
        if(b==0)
        {
            printf("error: 除数不能为0");
            return 0;
        }
        else
            s=a/b;
    }
    else
    {
        printf("error: the operator is unsupported!");
        return 0;
    }
    printf("\n%d %c %d = %d",a,opr,b,s);
}