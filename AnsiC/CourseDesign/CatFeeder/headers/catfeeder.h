/*
Author: 杨紫雯
*/
#ifndef CATFEEDER_HEADER_FILE
#define CATFEEDER_HEADER_FILE
#define MAX_NAME_LENGTH 50 

#define CAT_INFO_FILE "feeding_schedule.txt"
#define LOG_FILE "catfeeder.log"
#define SOUND_CALLCAT "resources\\CallCatToEat.wav"
#define SOUND_ALERT "resources\\alertBefore5Minute.wav"

typedef struct Cat
{
    char name[MAX_NAME_LENGTH]; //修猫名字长度为50个字符
    int feedHour;   //喂食时间（小时/分钟）
    int feedMinute;
    float feedAmount; //按克来计算
    struct Cat *next;   //定义一个指向结构体Cat的指针next，用于跟踪下一个节点
} Cat;

typedef struct
{
    Cat *head;
} CatList;  //定义一个匿名结构体，命名为CatList，并在其中定义一个指向结构体Cat的链表头指针head

int playSound(char* wavFilePath);
void logger(char* message);
void get_current_datetime(int *year, int *month, int *day, int *hour, int *minute, int *second);

#endif