/* 自定义需要用的函数："____.h"，定义在同一个project中*/
void color(short x) //自定义函数根据参数改变颜色
{
    if(x>=0 && x<=15) //参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x); //只有一个参数，改变字体颜色
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7); //默认颜色为白色
}