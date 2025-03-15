/*
Author: 郑世婷（logger()），杨紫雯（playSound()）
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

#include "headers/catfeeder.h"
#include "headers/menu.h"
#include "headers/timesetting.h"
#include "headers/catdata.h"
#include "headers/feeder.h"
#include "headers/feedalert.h"

#pragma comment(lib, "winmm.lib")

/**
 * this function is to output the message to log file with timestamp
 * every operation, such as adding a cat info, manu-feeding, to catfeeder should be logged into log file.
 */
void logger(char *message)
{
    // 1. open the log file(already defined as LOG_FILE in catfeeder.h) in append mode
    // 2. get current time and convert to char*, like "[2024-07-06 15:08:55]"
    // 3. using fprintf to output the current time and meesage to log file
    // 4. clost the log file
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL)
    {
        printf("Error opening log file!\n");
        return;
    }
    
    int year, month, day, hour, minute, second;
    get_current_datetime(&year, &month, &day, &hour, &minute, &second);
    fprintf(file, "[%4d-%02d-%02d %02d:%02d:%02d] %s\n", year, month, day, hour, minute, second, message);
    
    fclose(file);
}

/**
 * play specified sound to alert
 */
int playSound(char *wavFilePath)
{
    // play the video 'wav'
    if (!PlaySound(wavFilePath, NULL, SND_FILENAME | SND_SYNC))
    {
        printf("fail to play a sound!\n");
    }

    return 0;
}

void get_current_datetime(int *year, int *month, int *day, int *hour, int *minute, int *second)
{
    // get current time
    time_t now;
    time(&now);
    
    // change the time into local time
    struct tm *local = localtime(&now);

    // get the year, month, day, hour, minute and second
    *year = local->tm_year + 1900;
    *month = local->tm_mon + 1;
    *day = local->tm_mday;
    *hour = local->tm_hour;
    *minute = local->tm_min;
    *second = local->tm_sec;
}