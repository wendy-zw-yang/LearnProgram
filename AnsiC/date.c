#include <stdio.h>
struct date
{
    int month;
    int day;
    int year;
};

int main()
{
    /*读入日期*/
    struct date date;
    int day, month, year;
    printf("Please print the day of month:");
    scanf_s("%d", &day);
    printf("Please print the month:");
    scanf_s("%d", &month);
    printf("Please print the year:");
    scanf_s("%d", &year);
    /*检查日期*/

    if (month < 1 || month > 12)
    {
        printf("输入错误");
        return 1;
    }

    if (year < 1)
    {
        printf("输入错误");
        return 1;
    }

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0)
    {
        days_in_month[1] = 29;
    }

    if (day < 1 || day > days_in_month[month - 1])
    {
        printf("输入错误");
        return 1;
    }

    /*输出日期*/
    char print_month[] = {"January"
                          "February"
                          "March"
                          "April"
                          "May"
                          "June"
                          "July"
                          "August"
                          "September"
                          "October"
                          "November"
                          "December"};
    printf("%s %d %d/n", print_month[month - 1], day, year);
    return 0;
}