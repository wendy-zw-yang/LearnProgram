#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[5]={1,2,3,4,5}; 
    //a[100]={1,2,3,4,5} 依旧分配100个元素单元，但只定义前五个
    printf("%d\n",sizeof(a)/sizeof(int)); 
    //计算元素个数，要/int的单位长度
    
    /////////////////////////////////////*计算数组大小*/////////////////////////////////////////
    char s[]="12345678910qwertyuiopasdfghjklzxcvbnm";
    //方法1：直接计算
    printf("%d\n",sizeof(s)); 
    
    //方法2：累加
    int i=0; 
    while(s[i]!='\0') //字符串类型数组以'\0'结尾，此处判断是否取完数组元素
    {
        i++;
    }
    printf("%d\n",i+1); //'\0'也占一个单位大小

    //方法3：指针计算
    char *p1,*p2;
    p1 = s;
    p2 = p1;
    while(*p1!='\0')
        p1++;
    //printf("%c",*p1); //p1-->'\0'
    printf("%d\n",p1-p2+1);
    return 0;
}
