#include <stdio.h>
int main()
{
    int year,month,day,s;
    printf("year=");
    scanf("%d",&year);
    
    printf("month=");
    scanf("%d",&month);
    
    printf("day=");
    scanf("%d",&day);
    if(year%400==0)
    {
        if(month==1)
        {
            s=day;
            printf("第%d天",s);
        }
        else if(month==2)
        {
            s=31+day;
            printf("第%d天",s);
        }
        else if(month==3)
        {
            s=31+29+day;
            printf("第%d天",s);
        }
        else if(month==4)
        {
            s=31*2+29+day;
            printf("第%d天",s);
        }
        else if(month==5)
        {
            s=31*2+29+30+day;
            printf("第%d天",s);
        }
        else if(month==6)
        {
            s=31*3+29+30+day;
            printf("第%d天",s);
        }
        else if(month==7)
        {
            s=31*3+29+30*2+day;
            printf("第%d天",s);
        }
        else if(month==8)
        {
            s=31*4+29+30*2+day;
            printf("第%d天",s);
        }
        else if(month==9)
        {
            s=31*5+29+30*2+day;
            printf("第%d天",s);
        }
        else if(month==10)
        {
            s=31*5+29+30*3+day;
            printf("第%d天",s);
        }
        else if(month==11)
        {
            s=31*6+29+30*3+day;
            printf("第%d天",s);
        }
        else if(month==12)
        {
            s=31*6+29+30*4+day;
            printf("第%d天",s);
        }
    }
    else
    {
        if(month==1)
        {
            s=day;
            printf("第%d天",s);
        }
        else if(month==2)
        {
            s=31+day;
            printf("第%d天",s);
        }
        else if(month==3)
        {
            s=31+30+day;
            printf("第%d天",s);
        }
        else if(month==4)
        {
            s=31*2+30+day;
            printf("第%d天",s);
        }
        else if(month==5)
        {
            s=31*2+30*2+day;
            printf("第%d天",s);
        }
        else if(month==6)
        {
            s=31*3+30*2+day;
            printf("第%d天",s);
        }
        else if(month==7)
        {
            s=31*3+30*3+day;
            printf("第%d天",s);
        }
        else if(month==8)
        {
            s=31*4+30*2+day;
            printf("第%d天",s);
        }
        else if(month==9)
        {
            s=31*5+30*3+day;
            printf("第%d天",s);
        }
        else if(month==10)
        {
            s=31*5+30*4+day;
            printf("第%d天",s);
        }
        else if(month==11)
        {
            s=31*6+30*5+day;
            printf("第%d天",s);
        }
        else if(month==12)
        {
            s=31*6+30*5+day;
            printf("第%d天",s);
        }
    }
    return 0;
}