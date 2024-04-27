/*
    打开一个文件，读取该文件并找到你的序列号，以及对应的成绩，将该成绩+5分写入另一个文件
    1. 这里面要求输入输出的文件是input.txt,output.txt,和程序放在一个目录
    2. input.txt的格式如下，即学号和成绩用空格分开
        2335060505 65
        2335060506 66
        2335060507 85
    3. 如果学号和成绩是“,”分隔的，则读取时写为：
        fscanf(fp1, "%[^,],%d", stuId, &sum1) 
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1, *f2;
    //char stuId[20];
    int a;
    float sum1,sum2;
    int i=0;

    f1 = fopen("D:\\input.txt", "r");
    f2 = fopen("D:\\output.txt", "w");

    if (f1 == NULL)
    {
        printf("文件不存在\n");
        exit(1);
    }
    
    printf("输入学号:");
    scanf("%d",&a);

    while (!feof(f1))
    {
        fscanf(fp1, "%f",&sum1);
        i++;
        //printf("\n%d,%f,%d",i,sum1,a);
        if (i==a)
        {
            sum2 = sum1 + 30;
            //if(sum1>100)
                //sum1=100;
            fprintf(f2, "2335060508,%.1f,%.1f\n",sum1,sum2);
        }
    }

    fclose(f1);
    fclose(f2);

    return 0;
}