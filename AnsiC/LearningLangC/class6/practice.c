#include <stdio.h>
int main()
{
    int age=10;
    int tree=1;
    int sum=1;
    do
    {
        tree = 2*tree + 1;
        sum = sum + tree;
        age = age + 1;
    } while (tree<100);
    printf("%d岁时, 认养%d棵, 共%d棵",age,tree,sum);
}