/*#include <stdio.h>
int main()
{
    int m,n,i,j;
    printf("输出列和行:\n");
    scanf("%d",&m);
    scanf("%d",&n);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            printf("*");
        printf("\n");
    }
}
*/
#include <stdio.h> //打印三角形
int main()
{
    int n,i,j;
    printf("输出行:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=2*i-1;j++)
            printf("*");
        printf("\n");
    }
}