#include <stdio.h>
int add(int chinese,int maths,int english)
{
    int m;
    m = chinese + maths + english;
    return(m);
}
int main(void)
{
    int chinese,maths,english;
    int sum;
    int z;
    scanf("%d",&chinese);
    scanf("%d",&maths);
    scanf("%d",&english);
    sum = add(chinese,maths,english);
    z = sum/3;
    printf("高考总分为:%d\n三门平均分为: %d",sum,z);
}
