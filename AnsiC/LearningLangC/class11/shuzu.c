#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 2
int main()
{
    int b[M][N];
    int i,j;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            //printf("输入一个数：");
            scanf("%d",&b[i][j]);
        }
            
    }

    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
            printf("%d\t",b[i][j]);
        printf("\n");
    }
}