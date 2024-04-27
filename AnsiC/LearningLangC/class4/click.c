#include <stdio.h>
#include <conio.h>

int main()
{
    int i=12366;
    char ch;
    while((ch=getch())!='a')
    {
        i++; /*<==> i=i+1/++i
            a=1 , k=0
            k = a++ >>> k=1 a=2 
            k = ++a >>> k=2 a=2*/
        printf("此时点击率：%d\n",i);
    }
    return 0;
}


/*  自增运算：
    i++ <==> i=i+1/++i  
    假设 a=1 , k=0
        k = a++ >>> k=1 a=2 
        k = ++a >>> k=2 a=2
*/