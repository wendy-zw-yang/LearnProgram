/*
Author: 杨紫雯
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

void initCatList(CatList *list) // 初始化链表
{
    list->head = NULL;
}

void destroyCatList(CatList *list) // 销毁链表
{
    Cat *current = list->head;
    Cat *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    // 遍历列表，挨个释放内存
    list->head = NULL;
}

/**
 * showCats(): go through the catlist, and show all cats' data
 */
void showData(CatList *list)
{
    Cat *current = list->head; // 定义current作为链表头指针
    if (current == NULL)
    {
        printf("Dear Master, there is no cat yet! Please add cats' info");
        return;
    }
    while (current != NULL)
    {
        printf("%s\t\t%d:%d\t\t%.2f\n", current->name, current->feedHour, current->feedMinute, current->feedAmount);
        current = current->next; // 将指针current指向下一个节点
    }
}

/**
 * addCat(): add a new cat to the catlist
 */
void addCat(CatList *list, const char *name, int hour, int minute, float amount) // 添加猫咪信息
{
    Cat *newCat = (Cat *)malloc(sizeof(Cat)); // 为指向结构体Cat的指针newCat设置内存空间

    strcpy(newCat->name, name); // 将结构体Cat中的变量赋值给定义的变量
    newCat->feedHour = hour;
    newCat->feedMinute = minute;
    newCat->feedAmount = amount;
    newCat->next = list->head;
    // printf("%s %d %d %.2f\n", newCat->name, newCat->feedHour, newCat->feedMinute, newCat->feedAmount);
    list->head = newCat;
}

/**
 * removeCat(): remove a cat from catlist
 */
void removeCat(CatList *list, const char *name) // 删除猫咪信息
{
    Cat *current = list->head; // 定义current作为链表头指针
    Cat *prev = NULL;          // 用于跟踪当前节点的前一个结点

    while (current != NULL && strcmp(current->name, name) != 0)
    {
        prev = current;          // 将当前current要删除的目标猫咪信息赋给prev
        current = current->next; // 链表传递向前覆盖
    } // 遍历匹配到猫咪信息

    if (current == NULL)
    {
        printf("Cat not found!\n");
        return;
    }
    else if (prev == NULL)
        list->head = current->next;
    else
        prev->next = current->next;

    free(current); // 释放当前节点占用的内存，删除该节点
}

/**
 * saveData(): write and save the cats' data to feeding_schedule.txt
 */
void saveData(CatList *list)
{
    FILE *file = fopen(CAT_INFO_FILE, "w"); // （结尾可以用.conf(配置)或者.ini(初始化)文件）
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    Cat *current = list->head; // 设置链表头指针位置
    while (current != NULL)
    {
        // fwrite(current, sizeof(Cat), 1, file); // 写入当前节点current中的信息【只能以二进制保存】
        fprintf(file, "%s\t%d:%d\t%.2f\n", current->name, current->feedHour, current->feedMinute, current->feedAmount);

        current = current->next; // 将指针current指向下一个节点
    }
    fclose(file);
}

/**
 * loadData(): read the cat info from the document feeding_schedule.txt
 */
void loadData(CatList *list)
{
    FILE *file = fopen(CAT_INFO_FILE, "r");
    if (file == NULL)
    {
        printf("No existing data found.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    int feedHour;
    int feedMinute;
    float feedAmount;
    while (fscanf(file, "%s\t%d:%d\t%f", name, &feedHour, &feedMinute, &feedAmount) == 4)
    {
        addCat(list, name, feedHour, feedMinute, feedAmount);
        printf("%s %d %d %.2f\n", name, feedHour, feedMinute, feedAmount);
    }

    fclose(file);
}

/**
 * inputCatInfo(): setting a cat's feeding time and feed amount
 */
void inputCatInfo(CatList *list)
{
    char name[MAX_NAME_LENGTH];
    int hour, minute;
    float amount;

    printf("Enter cat's name: ");
    scanf("%s", name);
    printf("Set pre-feed time-->\n");
    printf("Set pre-feed hour (0-23): ");
    scanf("%d", &hour);
    printf("Set pre-feed minute (0-59): ");
    scanf("%d", &minute);
    printf("Set feeding amount in grams: ");
    scanf("%f", &amount);

    addCat(list, name, hour, minute, amount); // 调用addCat()函数，将设定的某猫喂食时间和喂食量添加到CatList链表
    saveData(list);

    char logMessage[MAX_NAME_LENGTH + 20];
    snprintf(logMessage, sizeof(logMessage), "Data of %s has been added", name);
    logger(logMessage);
}

/**
 * updateCatInfo()：update certain cat's feeding time and feed amount
 */
void updateCatInfo(CatList *list)
{
    char name[MAX_NAME_LENGTH];
    int hour, minute, amount;

    printf("Enter cat's name to update: ");
    scanf("%s", name);

    // Invoke removeCat() to remove the cat info
    removeCat(list, name); 

    printf("Set new feeding hour (0-23): ");
    scanf("%d", &hour);
    printf("Set new feeding minute (0-59): ");
    scanf("%d", &minute);
    printf("Set new feeding amount in grams: ");
    scanf("%d", &amount);

    // 调用addCat()增加新的喂食信息
    addCat(list, name, hour, minute, amount); 
    // 调用saveData()函数保存信息
    saveData(list);             

    char logMessage[MAX_NAME_LENGTH + 20];
    snprintf(logMessage, sizeof(logMessage), "Data of %s has been updated", name);
    logger(logMessage);
}

/**
 * deleteCat(): delete a cat's data from the catlist
 */
void deleteCat(CatList *list)
{
    char name[MAX_NAME_LENGTH];
    printf("Enter cat's name to delete: ");
    scanf("%s", name);

    removeCat(list, name);

    char logMessage[MAX_NAME_LENGTH + 20];
    snprintf(logMessage, sizeof(logMessage), "Data of %s has been deleted", name);
    logger(logMessage);
}

/**
 * retrieve feeding time from a line of log
 */
void extract_time(const char *line, char *time)
{
    strncpy(time, line + 1, 19);
    time[19] = '\0';
}

/**
 * Search log file to find out when the latest time the specified cat being fed.
 */
void queryLastFeedTimeInLog()
{
    char catName[MAX_NAME_LENGTH];
    printf("Please input cat name: ");
    scanf("%s", catName);
    char strFedTime[20] = "";

    FILE *file = fopen(LOG_FILE, "r");
    if (!file)
    {
        perror("Error opening file");
        return;
    }

    char line[200];
    char temp_time[20] = "";
    // Initialize last_time to empty string
    strFedTime[0] = '\0'; 

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, catName))
        {
            extract_time(line, temp_time);
            // Update strFedTime to the current found time
            strcpy(strFedTime, temp_time); 
        }
    }
    if (strFedTime[0] == '\0')
        printf("no %s feeding record in log file!\n", catName);
    else
        printf("%s was fed at %s \n", catName, strFedTime);

    system("pause");
    fclose(file);
}