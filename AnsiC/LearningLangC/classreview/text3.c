#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENT_NUM 1000 // 最大学生数

struct fpStudent
{
    int number;    // 学生编号
    char name[81]; // 学生姓名
    float GPA;     // 学生学业绩点
};

typedef struct fpStudent Student;

int read_record(char filename[], Student stu[])
{
    FILE *fp;
    int i = 0;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("no file");
        return -1;
    }
    char ss[200];
    while (fgets(ss, 20, fp) != NULL)
    {
        sscanf(stu, "%d%s%f", stu[i].number, stu[i].name, stu[i].GPA);
        i++;
    }
    fclose(fp);
    return i;
}

void show(Student a[], int n)
{ // 显示统计后的入选学生的信息
    int i;
    printf("入选学生学号\t姓名\t\t    学业绩点GPA \n");
    for (i = 0; i < n; i++)
    {
        printf("%6d\t\t%-20s%-6.2f\n", a[i].number, a[i].name, a[i].GPA);
    }
}

void sort_record(Student stu_sort[], int n)
{
    read_record("student.txt", stu_sort[]);
    Student temp;
    for (int i = 0; i < n - 1; n++)
    {
        for (int j = i + 1, j < n; j++)
        {
            if (stu_sort[i].GPA < stu_sort[j].GPA)
            {
                temp.GPA=stu[i].GPA;
				stu[i].GPA=stu[j].GPA;
				stu[j].GPA=temp.GPA;

				strcpy(temp.name,stu[i].name);
				strcpy(stu[i].name,stu[j].name);
				strcpy(stu[j].name,temp.name);

				temp.number=stu[i].number;
				stu[i].number=stu[j].number;
				stu[j].number=temp.number;
            }
        }
    }
    show(stu_sort,60);
    return stu_sort[59].GPA;
}

int count_candicate(Student Stu,int n,Student stu_candidate,float Gap_level)
{
    int k=0;
    read_record("student.txt", Stu[]);
    sort_record(Stu[], n);
    for(int i=0;i<n;i++)
    {
        if(Stu[i].GPA > Gap_level)
            k++;
    }
    printf("最高GPA: %s",Stu[0].GPA);
    printf("最低GPA: %s",Stu[k].GPA);
    return k;
}

int main(void)

{
    char filename[] = "students.txt";
    Student Stu[MAX_STUDENT_NUM]; // 学生
    int stu_num;
    stu_num = read_record(filename, Stu);

    Student stu_candidate[MAX_STUDENT_NUM]; // 入选学生信息
    float Gap_level = 3; // 遴选门槛线Gap_level

    int candidate_num = count_candicate(Stu,stu_num,stu_candidate,Gap_level);
    show(Stu[i],stu_num); // 入选学生人数
}