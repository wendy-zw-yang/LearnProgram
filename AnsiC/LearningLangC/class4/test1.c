#include <stdio.h>
int main()
{
    char c = '\101'; //"\"符号+至多三位编码，自动匹配翻译ASC11码
    printf("%d\n",c);
    
    char s = '\x71'; //十六进制同理可以识别
    printf("%d\n",s);
    //编码只能为三位以下，否则溢出报错
    
    printf("a\x12t3b"); //t不属于16进制编码，无法被自动识别，可以区分转义内容
    return 0;
}