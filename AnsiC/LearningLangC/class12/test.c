#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//定义平面坐标结构
typedef struct point{
    double x;
    double y;
}P;
int main()
{
    P a,b;
    double dis;
    printf("输入两点坐标：\n");
    printf("a:");
    scanf("%lf,%lf",&a.x,&a.y);
    //scanf("%lf",&a.y);
    printf("b:");
    scanf("%lf,%lf",&b.x,&b.y);
    //scanf("%lf",&b.y);
    dis = sqrt(powl((a.x-b.x),2)+powl((a.y-b.y),2));
    printf("distance = %lf",dis);
}