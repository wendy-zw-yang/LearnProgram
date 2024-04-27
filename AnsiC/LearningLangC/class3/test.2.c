#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    char name[50];
    int age;
    char sex[50];
    printf("请问您的姓名?\n");
    scanf("%s",name);
    printf("您好,%s,请问您的年龄是?\n",name);
    fflush(stdin);
    scanf("%d",&age);
    printf("您的性别?\n");
    fflush(stdin);
    scanf("%s",sex);
    
    if(strcmp(sex,"男")==0)
        printf("您好, %s先生",name);
    else if(strcmp(sex,"女")==0)
        printf("您好, %s女士",name);
    else
        printf("您好, %s",name);
    return 0;
}