//凯撒密码加密解密
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char encode[100];
    printf("input code: ");
    scanf("%c",&encode); //输入明文

    int i;
    int n=strlen(encode);
    for(i=0;i<n;i++)
    {
        if(encode[i]<='Z' && encode[i]>='A')
            encode[i]=(encode[i]-'A'+3) % 26 + 'A';
        else if(encode[i]<='z' && encode[i]>='a')
            encode[i]=(encode[i]-'a'+3) % 26 + 'a';
    }
    puts(encode);
    return 0;
}