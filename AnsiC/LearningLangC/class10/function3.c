#include <stdio.h>
#include <stdlib.h>
int min(int x,int y)
{
    return(x<y?x:y); //三目运算：1.判断x<y 2.为真：取x 3.为假：取y
}

int main()
{
    int a[5],i,m;
    for(i=0;i<5;i++)
    {
        printf("input:");
        scanf("%d",&a[i]);
    }
    m=a[0];
    for(i=0;i<5;i++)
    {
        m=min(m,a[i]);
    }
    printf("minimum number = %d",m);
}