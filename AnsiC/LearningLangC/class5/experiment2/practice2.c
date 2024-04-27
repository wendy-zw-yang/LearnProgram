//从temp2.txt文件中读取温度数据，并判断今天的天气情况。
#include <stdio.h>
int main()
{
    int sum;
    FILE *t;
    t=fopen("D:\\workspace\\AnsiC\\LearningLangC\\class5\\temp2.txt","r+");
    if(t==NULL)
    {
        printf("file error");
        return -1;
    }
    fscanf(t,"%d",&sum);
    if(sum>=38)
        printf("酷热");
    else if(sum>=35 && sum<38)
        printf("炎热");
    else if(sum>=28 && sum<35)
        printf("闷热");
    else if(sum>=10 && sum<28)
        printf("温暖");
    else if(sum>=0 && sum<10)
        printf("凉爽");
    else if(sum>=-9 && sum<0)
        printf("寒冷");
    else
        printf("严寒");
    fclose(t);
    return 0;
}