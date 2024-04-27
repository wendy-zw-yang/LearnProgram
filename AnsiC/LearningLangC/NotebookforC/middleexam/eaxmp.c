#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    FILE *t;
    int num,k,i,n=1;
    int a=0,b=0,c=0,d=0;
    int u;
    t=fopen("D:\\DocumentCenter\\namelist.txt","r+");
    printf("候选人名单如下:\n1--张晶晶\n2--侯明伟\n3--赵海涛\n4--王浩\n");
    printf("请输入参与投票的学生人数: ");
    scanf("%d",&num);
    srand(time(NULL));
    for(i=1;i<=num;i++)
    {
        k=rand() %4 +1;
        printf("\n%d学生选%d号\n",i,k);
        char ch='-';
        printf("投票进行中\n");
        for(u=1;u<=i;u++)
        {
            printf("-");
        }
        switch(k)
        {
            case 1:a++; break;
            case 2:b++; break;
            case 3:c++; break;
            case 4:d++; break;
        }
    }
    fprintf(t,"张晶晶%d票\n侯明伟%d票\n赵海涛%d票\n王浩%d票",a,b,c,d);
    fclose(t);
}