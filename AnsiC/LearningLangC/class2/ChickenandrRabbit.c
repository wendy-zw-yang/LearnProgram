/*头m 脚n
  鸡x 兔y
  x=(4*m-n)/2
  y=(n-2*m)/2*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void)
{
    int m,n,x,y;
    scanf("%d",&m);
    scanf("%d",&n);
    x =(4*m-n)/2;
    y =(n-2*m)/2;
    
    if((x+y)==m && (2*x+4*y)==n)
        printf("鸡数为%d, 兔子数为%d\n",x,y);
    else
        printf("error\n");
    return 1;
}
/*#include <stdio.h>
int main() //主函数
{
    int head,feet;
    int chicken,rabbit;
    scanf("%d %d", &head,&feet);
    /*反复穷举符合条件的解法，直到得到结果
    for(chicken=1;chicken<=head;chicken++)
    {   rabbit=head-chicken;
        if(chicken*2+rabbit*4==feet)
            break;
    }
    printf("\nchicken=%d,rabbit=%d\n")
}*/