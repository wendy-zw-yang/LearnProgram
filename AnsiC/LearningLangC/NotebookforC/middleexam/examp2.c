#include <stdio.h>
#include <math.h>
int main()
{
    int a,n,sum=0,s;
    int i,j;
    printf("输入一个数字: ");
    scanf("%d",&a);
    printf("\n输入项数: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        s=a;
        for(j=1;j<=i-1;j++)
        {
            s=s*10+a;
        }
        sum=sum+s;
    }
    printf("%d",sum);
}