/*
Author: 申佳依
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "headers/catfeeder.h"
#include "headers/menu.h"
#include "headers/timesetting.h"
#include "headers/catdata.h"
#include "headers/feeder.h"
#include "headers/feedalert.h"

//**模块二：时间管理模块
/**
 * 设置系统时间
 * */
void set_time(struct tm *time_a) // tm这是一个结构体类型，定义在 <time.h> 中，用于表示日期和时间。
{
    printf("set system time:");
    int sec = (*time_a).tm_sec;          // 秒（0-59）
    int min = (*time_a).tm_min;          // 分（0-59）
    int hour = (*time_a).tm_hour;        // 时（0-23）
    int day = (*time_a).tm_mday;         // 月中的第几天（1-31）
    int month = (*time_a).tm_mon + 1;    // 月份(0-11,其中0表示1月)
    int year = (*time_a).tm_year + 1900; // 年份(自1900 起)
    printf("%d-%d-%d %d:%d:%d\n", year, month, day, hour, min, sec);
}

/**
 * 读取系统时间
 */
void read_current_time(struct tm *current_time)
{
    time_t now = time(NULL);          // time_t是数据类型，是1970年1月1日以来的秒数
    *current_time = *localtime(&now); // localtime函数，将time_t类型的值转换为本地时间表示
}

/**
 * 计算时间差
 */
int time_difference(struct tm *time_a, struct tm *current_time)
{
    int td;
    td = (time_a->tm_hour - current_time->tm_hour) * 60 + (time_a->tm_min - current_time->tm_min);
    return (td);
}
