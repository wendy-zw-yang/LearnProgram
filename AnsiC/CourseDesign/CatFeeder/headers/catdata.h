/*
Author: 杨紫雯
*/
#ifndef CATDATA_HEADER_FILE
#define CATDATA_HEADER_FILE

#include "catfeeder.h"

void initCatList(CatList *list); //初始化链表
void destroyCatList(CatList *list);  //销毁链表

void addCat(CatList *list, const char *name, int hour, int minute, float amount);  //添加猫咪信息
void removeCat(CatList *list, const char *name); //删除猫咪信息
 
void showData(CatList *list);    //displat cat list
void saveData(CatList *list);    //保存数据
void loadData(CatList *list);    //加载数据

void inputCatInfo(CatList *list);    //设置喂食时间和喂食量
void updateCatInfo(CatList *list);   //更新喂食时间和喂食量
void deleteCat(CatList *list);

void queryLastFeedTimeInLog();
#endif