#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char name[10][20]={"abc","deff"}; //创建一个
    for(int i=0;i<10;i++)
    {
        int j=0;
        while(name[i][j]!='\0')
        {
            printf("%c",name[i][j]);
            j++;
        }
        printf("\n");
    }
}