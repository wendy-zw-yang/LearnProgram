#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char search[20],s;
    int flag =0,n=0;
    printf("input your string: ");
    //gets(search);
    scanf("%s",search);

    printf("input the char you want to search: ");
    scanf("%c",&s);

    for(int i=0;search[i]!='\0';i++)
    {
        if(s==search[i])
            flag++;
        n++;
        if(flag==1)
        {
            printf("%c is the %d number in the string\n",s,n);
            break;
        }
    }

    if(flag==0)
        printf("can't find the char");
}