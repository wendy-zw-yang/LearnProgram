#include <stdio.h>
#include <stdlib.h>
void menu() //函数体
{
    printf("1----square\n");
    printf("1----triangle\n");
    printf("1----exit\n");
}

void square() //void表示无参无返回值的函数定义
{
    int i,j,n=5,m=6;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            printf("*"); //==>可以用 putchar('') 来代替，括号内用单引号''
        }
        printf("\n");    
    }
}

void triangle()
{
    int i,j,n;
    printf("输入行: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("*");//putchar('*')  
        }
        printf("\n");
    }
}


int main()
{
    int choice,flag=0;
    menu();
    while(flag==0)
    {
        printf("input your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: square(); flag==1; break; //自定义square()和triangle()函数
            case 2: triangle(); flag==1; break;
            case 3: exit(0); break; //exit(0)退出整个程序
            default: continue;
        }
    }
    }
    