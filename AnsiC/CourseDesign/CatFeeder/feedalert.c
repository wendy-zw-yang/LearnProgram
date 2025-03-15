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

// 判断是否提醒
int checkReminder(FeedTime *presetTime, const struct tm *currentTime)
{
    if (presetTime->hour == currentTime->tm_hour && presetTime->minute == currentTime->tm_min) // 简化处理：仅比较小时和分钟
    {
        return 1; // 需要提醒
    }
    return 0; // 不需要提醒
}

// 触发提醒
void triggerFeedReminder(char *catName, FeedTime presetTime)
{
    time_t rawtime;
    struct tm *currentTime;
    time(&rawtime); // 获取当前时间
    currentTime = localtime(&rawtime);
    if (checkReminder(&presetTime, currentTime))
    {
        //printf("Reminder for %s: It's time to feed!\n", catName);
        playSound(SOUND_CALLCAT);
        printf("Start feeding %s ", catName);
        for (int i = 0; i < 3; i++)
        {
            printf(".");
            sleep(1);
        }
        printf("Done!\n");
        char logMessage[MAX_NAME_LENGTH + 20]; // Buffer for log message
        snprintf(logMessage, sizeof(logMessage), "%s has been fed\n", catName);
        logger(logMessage);
    }
}
