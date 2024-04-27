#include <stdio.h>
#include <stdlib.h>
void menu()
{
    printf("儿童餐券(年龄<1=2岁)\n");
    printf("老人餐券(年龄>=60岁)\n");
    printf("普通餐券(12岁<年龄<60岁)\n");
}

int main()
{
    int age,num,pay;
    menu();
    printf("输入年龄和数量：");
    scanf("%d",&age);
    scanf("%d",&num);
    if(age<=12 && age>0)
    {
        pay = 30 * num;
        printf("您购买的是儿童餐券，需支付%d元",pay);
    }
        
    else if(age>12 && age<60)
    {
        pay = 90 * num;
        printf("您购买的是普通餐券，需支付%d元",pay);
    }

    else if(age>=60)
    {
        pay = 50 * num;
        printf("您购买的是老人餐券，需支付%d元",pay);
    }
}