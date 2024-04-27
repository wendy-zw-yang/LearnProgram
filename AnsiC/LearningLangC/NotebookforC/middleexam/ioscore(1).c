#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fp1, *fp2;
    char stuId[40];
    char myId[40];
    float score,score_1;

    fp1 = fopen("D:\\C041.txt", "r");
    fp2 = fopen("D:\\2335060507.txt", "wb");

    if (fp1 == NULL)
    {
        printf("Input file(input.txt) is not found! \n");
        exit(1);
    }
    
    printf("please input your student ID:");
    scanf("%s",myId);

    while (fscanf(fp1, "%[^,],%f\n", stuId, &score) != EOF)
    {
        if (strcmp(stuId, myId)==0)
        {
            printf("成绩为: %s,%.1f\n",stuId,score);          
            score_1 = 100;
            fprintf(fp2, "学号:%s, 原成绩为: %.1f,现成绩为: %.1f\n",myId,score,score_1);
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}



/*
    打开一个文件，读取该文件并找到你的序列号，以及对应的成绩，将该成绩+5分写入另一个文件
    1. 这里面要求输入输出的文件是input.txt,output.txt,和程序放在一个目录
    2. input.txt的格式如下，即学号和成绩用空格分开
        2335060505 65
        2335060506 66
        2335060507 85
    3. 如果学号和成绩是“,”分隔的，则读取时写为：
        fscanf(fp1, "%[^,],%d", stuId, &score) 
 */