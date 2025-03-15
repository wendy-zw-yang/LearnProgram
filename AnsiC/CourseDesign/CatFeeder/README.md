# 编程作业说明

## 采用模块化编程
1. 每个模块由2个文件构成，一个是头文件（.h），一个是源程序文件(.c)，分别放在: CatFeeder\headers和CatFeeder\下
2. 头文件写成如下格式时可以在.c程序下引用：
```C
#ifndef XXX_HEADER_FILE
#define XXX_HEADER_FILE

/*使用功能名替代上面的XXX*/
void functionName();

#endif
```
3. 编译。打开CMD窗口，进入文件夹并执行：make.bat，用于编译整个项目
4. 测试：执行CatFeeder.exe即可查看看执行结果

## 程序主体内容

### 程序介绍 ——猫咪喂食器

##### 描述
一个基于C语言的猫咪喂食器，通过实现用户预置喂食时间、喂食量、语音提示等功能，提供智能化的喂食服务。

##### 主要功能
1. 时间和喂食量预设功能:猫咪喂食器能够随时预设喂食时间和喂食量，且每只猫都能预设不同的喂食量和时间。每次喂食的时间和喂食量将保存在文件中
2. 自动喂食功能:猫咪喂食器能够根据预设的喂食时间和喂食量自动喂食，畏食器在喂食结束后，将记录该次喂食并存储至日志文件。
3. 手动喂食功能:在特殊情况下，用户可以手动触发喂食器进行喂食，手动喂食后，将记录该次喂食并存储至日志文件。
4. 喂食提醒功能:猫咪喂食器能够在喂食前5分钟做出语音或者文字提示。

### 程序设计

#### 模块设计图
在CatFeeder\文件夹下:
![模块设计图](\CatFeeder\programDesign.png "programDesign")

#### 模块划分
1. 主控制模块：用于主程序的控制和主要功能的索引
2. 用户交互界面：显示主菜单和子菜单，并调用其余模块函数实现功能
3. 预设数据管理：用于增加，删除，更新猫咪的信息以及对猫咪喂食日志信息的查看
4. 时间管理模块：编写内部调用时间函数，用于喂食执行模块
5. 喂食执行模块: 分别实现手动喂食与自动喂食两个主要功能
6. 喂食提醒模块：分别实现自动喂食前5分钟与自动喂食开始时的语音提示（提前录入测试语音）
7. 数据持久化：将每一次手动或自动喂食，以及猫咪信息的修改进行日志的记录与保存（在CatFeeder\下的"catfeeder.log"中

### 程序实现

#### 函数模块
1. 主控制模块(catfeeder)函数声明：
```c
// 语音提醒与日志函数(对应数据持久化)为补加，修改时声明在主函数模块对应头文件中，函数在utils.c文件里
int playSound(char* wavFilePath);
void logger(char* message);
void get_current_datetime(int *year, int *month, int *day, int *hour, int *minute, int *second);

#define MAX_NAME_LENGTH 50 

#define CAT_INFO_FILE "feeding_schedule.txt"
#define LOG_FILE "catfeeder.log"
#define SOUND_CALLCAT "resources\\CallCatToEat.wav"
#define SOUND_ALERT "resources\\alertBefore5Minute.wav"
```  
2. 用户交互界面(menu)函数声明：
```c
void displayMenu();
void showCats(CatList *list);
void dataSetting(CatList *list);
void feederMods(CatList *list);
void systemInfo();
void systmeIntroduction();
```
3. 预设数据管理(catdata)函数声明：
```c
void initCatList(CatList *list);
void destroyCatList(CatList *list);

void addCat(CatList *list, const char *name, int hour, int minute, float amount);
void removeCat(CatList *list, const char *name);
 
void showData(CatList *list);
void saveData(CatList *list); 
void loadData(CatList *list);    

void inputCatInfo(CatList *list); 
void updateCatInfo(CatList *list);
void deleteCat(CatList *list);

void queryLastFeedTimeInLog();
```
4. 时间管理模块(timesetting)函数声明：
```c
void set_time(struct tm *time_a);
void read_current_time(struct tm *current_time);
int time_difference(struct tm *time_a, struct tm *current_time);
```
5. 喂食执行模块(feeder)函数声明：
```c
void manualFeed(CatList *list);
void autoFeed(CatList *list);
```
6. 喂食提醒模块(feedalert)函数声明：
```c
int checkReminder(FeedTime *presetTime, const struct tm *currentTime);
void triggerFeedReminder(char *catName, FeedTime presetTime);

int playSound(char* wavFilePath);
```

#### 文件
```c
#define CAT_INFO_FILE "feeding_schedule.txt" // 猫咪信息存储文件
#define LOG_FILE "catfeeder.log" // 猫咪喂食日志存储文件
```

#### 链表和结构体
```c
typedef struct Cat
{
    char name[MAX_NAME_LENGTH];
    int feedHour;
    int feedMinute;
    float feedAmount;
    struct Cat *next;点
} Cat;

typedef struct
{
    Cat *head;
} CatList;
```
在终端CMD打开保存的文件路径，cd到\CatFeeder里面，然后执行catfeeder.exe，任何对\CatFeeder下文件的修改都需要执行make命令重新编译文件
文件中文内容易出现乱码，可复制到txt文本中替换原代码