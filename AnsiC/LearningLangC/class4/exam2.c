#include <stdio.h>
#include <math.h>
int main()
{
    int year;
    printf("year=");
    scanf("%d",&year);
    if(year%400==0)
    {
        printf("\n%d is a leap year",year);
    }
    else
    {
        printf("\n%d is not a leap year",year);
    }
    return 0;
}