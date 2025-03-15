/*
Author: 郑世婷
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <conio.h> // 包含 _kbhit 和 _getch 函数

#include "headers/catfeeder.h"
#include "headers/menu.h"
#include "headers/timesetting.h"
#include "headers/catdata.h"
#include "headers/feeder.h"
#include "headers/feedalert.h"

void feedAction(char *name)
{
    printf("Start feeding %s ", name);
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        sleep(1);
    }
    printf("Done!\n");
}

/**
 * The auto feeding function. In this function, the feeder do:
 * 1. build a endless loop to check the difference between current time and pre-set feeding time
 * 2. if the difference time is 5 minutes, alert master the feeding will start soon
 * 3. if the difference time is 0 minutes, start the feeding
 * 4. anytime, hit "esc" key to quit
 */
void autoFeed(CatList *list)
{
    FeedTime feedTime;
    struct tm time;
    struct tm currentTime;
    int autoFeeding = 1;
    int diffTime = 0;
    printf("Auto-feeding has been started, press 'esc' key to exit the auto-feeding\n");
    while (autoFeeding)
    {
        Cat *current = list->head;
        while (current != NULL)
        {
            // trigger to remind master to feed before 5 minute ahead the preset feeding time
            time.tm_hour = current->feedHour;
            time.tm_min = current->feedMinute;

            read_current_time(&currentTime);                 // read_current_time(&currentTime); //get current time
            diffTime = time_difference(&time, &currentTime); // caculate the difftime between current time and pre-set time
            if (diffTime == 5)
            {
                // printf("Wait %d minutes to feed %s\n",diffTime, current->name);
                playSound(SOUND_ALERT); // when difftime is 5 minutes, play sound to remind feeding
            }

            // trigger to feed the cats when the preset time is current time
            feedTime.hour = current->feedHour;
            feedTime.minute = current->feedMinute;
            triggerFeedReminder(current->name, feedTime);

            current = current->next;
        }

        // check if there is "esc" being hit every 1 second. After 1 minute, start next check loop.
        for (int i = 0; i < 60; i++)
        {
            // sleep 1 second
            sleep(1);
            if (_kbhit())
            {
                char ch = _getch(); // 获取按下的键
                // ASCII 27 是 'esc' 键
                if (ch == 27)
                {
                    printf("Detected 'esc' be pressed! Auto-feeding has been terminated\n");
                    autoFeeding = 0;
                    break;
                }
            }
        }
    }
}

void manualFeed(CatList *list)
{
    char name[MAX_NAME_LENGTH];
    int flag = 0;
    printf("Input the cat you want to feed manually: ");
    scanf("%s", name);

    Cat *current = list->head;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            flag = 1;
            break;
        }
        current = current->next; // go through the cat list
    }

    if (flag == 0)
    {
        printf("Dear Master, the catlist is empty now! Please add cats' info:\n");
        inputCatInfo(list);
        saveData(list);
    }
    playSound(SOUND_CALLCAT);
    feedAction(name);

    char logMessage[MAX_NAME_LENGTH + 20]; // Buffer for log message
    snprintf(logMessage, sizeof(logMessage), "%s has been fed\n", name);
    logger(logMessage);
}