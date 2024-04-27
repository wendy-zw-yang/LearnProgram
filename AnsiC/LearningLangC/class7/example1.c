#include <stdio.h>
#include <math.h>
int main()
{
    int n,i,j;
    int s=1;
    printf("输入行:%d",n);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
           printf("%-4d",s); //分隔4个空格且左对齐
           s=s+2; 
        }
        printf("\n");
    }
}