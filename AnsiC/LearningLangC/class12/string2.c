#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_by_name(char name[][20],int n)
{
    int i,j;
    char t[20]; //定义一个和name每行大小相等的数组t[20]
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(strcmp(name[j],name[j+1])<0)
            {
                strcpy(t,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],t); //用strcpy()交换name的值
            }
        }
    }
}

int main()
{
    FILE *fp;
    int i,j,n;
    char name[1000][20];
    fp=fppen("name.txt","r");
    if(fp==NULL)
    {
        printf("no such file\n");
        return -1;
    }
    for(i=0;!feof(fp);i++)
    {
        fscanf(fp,"%s",name[i]);
    }
    int n=i;
    printf("读到%d位同学姓名\n",n);
    for(i=0,i<n;i++)
        puts(name[i]);
    
    fclose(fp);
}