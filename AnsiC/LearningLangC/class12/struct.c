/*自定义结构体*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student{
    int num;
    char id[20];
    char name[20];
    float score;
}STU;

int main()
{
    int a[100];
    STU b[100]={{1,"2335060507","yang",86.5},{2,"2335060705","sun",98.0}};
    for(int i=0;i<2;i++)
        printf("%d,%s,%s,%.1f\n",b[i].num,b[i].id,b[i].name,b[i].score);
}