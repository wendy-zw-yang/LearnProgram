/*题目提供的测试信息存放在结构体数组p_p中，结构体st_p定义为
struct st_p
{ char type; //场所分类
  char time[15]; //时间，"202210411201314"表示2022年04月11日20点13分14秒
  char mark[30]; //明细
  int amount; //人流量
} p_p[100]={{'M',"20220529201314", "OLE", 55}, {'S', "20220613121314", "Middle school", 618}, {'L', "20220622141314", "The cinema", 120}};

请编程实现如下功能：
 1）自定义函数统计人流量超过100的记录个数。
2）自定义函数按明细升序，输出所有信息
并用main函数调用，运行结果如图。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct st_p
{
    char type;     // 场所分类
    char time[15]; // 时间，"202210411201314"表示2022年04月11日20点13分14秒
    char mark[30]; // 明细
    int amount;    // 人流量
} p_p[100] = {{'M', "20220529201314", "OLE", 55}, {'S', "20220613121314", "Middle school", 618}, {'L', "20220622141314", "The cinema", 120}};

int count()
{
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        if (p_p[i].amount > 100)
            k++;
    }
    printf("人流量超过100的记录个数为: ");
    return k;
}

void select()
{
    char t[30] , b[15];
    char m;
    int k;
    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (strcmp(p_p[i].mark, p_p[j].mark) > 0)
            {
                strcpy(t, p_p[i].mark);
                strcpy(p_p[i].mark, p_p[j].mark);
                strcpy(p_p[j].mark, t);

                m = p_p[i].type;
                p_p[i].type = p_p[j].type;
                p_p[j].type = m;

                strcpy(b, p_p[i].time);
                strcpy(p_p[i].time, p_p[j].time);
                strcpy(p_p[j].time, b);

                k = p_p[i].amount;
                p_p[i].amount = p_p[j].amount;
                p_p[j].amount = k;
            }
        }
    }
    printf("\n按明细升序排序为: \n");
}

int main()
{
    // struct st_p p_p[100]={{'M',"20220529201314", "OLE", 55}, {'S', "20220613121314", "Middle school", 618}, {'L', "20220622141314", "The cinema", 120}};
    count();
    select();
    for (int i = 0; i < 3; i++)
    {
        printf("%c,%c\n", p_p[i].time, p_p[i].mark);
    }
}