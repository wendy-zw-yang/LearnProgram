/*
3.for语句：
step1;  //step1可以在循环外执行
for(step1 ; step2 ; step4)
{
    step3;
}
##按step1,2,3,4的顺序执行
*/

//for循环多用于计数：
//100以内奇数之和
#include <stdio.h>
int main()
{
    int i,s;
    for(i=1,s=0;i<=100;i=i+2)
    {
        s=s+i;
    }
    printf("%d",s);
}