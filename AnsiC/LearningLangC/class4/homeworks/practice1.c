//计算BMI指数
#include <stdio.h>
#include <math.h>
int main()
{
    int weight;
    float BMI,height;
    printf("height = ");
    scanf("%f",&height);
    printf("\nweight = ");
    scanf("%d",&weight);
    BMI = weight / (height*height);
    if(BMI<18)
        printf("体重较轻");
    else if(BMI>=18 && BMI<25)
        printf("体重正常");
    else if(BMI>=25 && BMI<28)
        printf("超重");
    else
        printf("肥胖");
}