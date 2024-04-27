//文件的读入与写入
#include <stdio.h>
int main()
{
    int a;
    FILE *t;  //指针变量："FILE"为变量类型加*，t为变量
    t = fopen("D:\\data.txt","r+");
    if(t==NULL)
    {
        printf("file errpr");
        return -1;
    }
    fscanf(t,"%d",&a);
    a = a + 2
    printf("%d",a);
    fclose(t);
    return 0;
}
/*
    带"*"后的变量只能储存地址
    e.g.int a;
        a1=12;
        int *a2 = &a1 
*/