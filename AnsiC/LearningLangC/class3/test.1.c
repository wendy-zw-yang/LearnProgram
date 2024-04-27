#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    char ch,ch1;
    scanf("%c",&ch);
    if(ch+2<=122)
        ch1=ch+2;
    else
        ch1=ch+2-26;
    printf("%c",ch1);
}