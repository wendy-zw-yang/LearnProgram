/*
Author: 申佳依
*/
#ifndef FEEDALERT_HEADER_FILE
#define FEEDALERT_HEADER_FILE

#include <time.h>

//***模块五：喂食提醒模块    
 //设置提醒时间 
typedef struct FeedTime
{  
    int hour;  
    int minute;  
} FeedTime;  

int checkReminder(FeedTime *presetTime, const struct tm *currentTime);
void triggerFeedReminder(char *catName, FeedTime presetTime);

int playSound(char* wavFilePath);

#endif