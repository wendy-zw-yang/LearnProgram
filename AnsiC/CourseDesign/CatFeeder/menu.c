/*
Author: 杨紫雯
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <conio.h> // include _kbhit and _getch function

#include "headers/catfeeder.h"
#include "headers/menu.h"
#include "headers/timesetting.h"
#include "headers/catdata.h"
#include "headers/feeder.h"
#include "headers/feedalert.h"

/**
 * display the main menu
 */
void displayMenu(CatList *list)
{
    // clrscr();
    system("cls");
    printf("==================================\n");
    printf("         Main menu\n");
    printf("==================================\n");
    printf("1. Show the catlist\n");
    printf("2. Set cats' data\n");
    printf("3. Set feeder mods\n");
    printf("4. Query last feeding time\n");
    printf("5. System Info\n");
    printf("6. Exit\n");
    printf("==================================\n");
}

/**
 * display the main menu
 */
void showCats(CatList *list)
{
    system("cls");
    printf("===========================================\n");
    printf("CatName\t\tFeedTime\tFeedAmount\n");
    printf("===========================================\n");
    showData(list);
}

void dataSetting(CatList *list)
{
    system("cls");
    printf("==================================\n");
    printf("         Data Setting\n");
    printf("==================================\n");
    printf("1. Add a new cat to feed\n");
    printf("2. Update a cat's feeding data\n");
    printf("3. Delete a cat's feeding data\n");
    printf("4. Return\n");
    printf("==================================\n");

    int choice;
    while (1)
    {
        printf("Please input your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            inputCatInfo(list); // add a new cat info
            break;
        case 2:
            updateCatInfo(list); // update a cat's info
            break;
        case 3:
            deleteCat(list); // delete a cat's info
            break;
        case 4:
            saveData(list); // recieve and return
            return;
        default:
            printf("no such choice");
            system("pause");
            break;
        }
    }
}

void feederMods(CatList *list)
{

    int choice;
    FeedTime time;
    while (1)
    {
        system("cls");
        printf("==================================\n");
        printf("       Set Feeder Mods\n");
        printf("==================================\n");
        printf("1. Manual feeding\n");
        printf("2. Automatic feeding\n");
        printf("3. Return\n");
        printf("==================================\n");

        printf("Please input your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            manualFeed(list);
            system("pause");
            break;
        case 2:
            autoFeed(list);
            system("pause");
            break;
        case 3:
            return;
        default:
            printf("no such choice");
            system("pause");
            break;
        }
    }
}

void systemInfo()
{
    int choice;
    while (1)
    {
        system("cls");
        printf("==================================\n");
        printf("       System Info\n");
        printf("==================================\n");
        printf("1. Version Info\n");
        printf("2. System introduction\n");
        printf("3. Return\n");
        printf("==================================\n");

        printf("Please input your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("CatFeeder version 1.0.1\n");
            system("pause");
            break;
        case 2:
            systmeIntroduction();
            system("pause");
            break;
        case 3:
            return;
        default:
            printf("no such choice");
            system("pause");
            break;
        }
    }
}
/**
 * Display the system introduction
 */
void systmeIntroduction()
{
    printf("This is a Cat Feeder\n\n");
    printf("It based on C language, realizing smart feeding through functions like presetting feeding time, feed amount, and sound alert.\n\n");
    printf("Below are Feeder's main functions:\n\n");
    printf("1. Presetting time and feeding amount: The cat feeder can preset the feeding time and feeding amount at any time, \n");
    printf("\tand each cat can preset different feeding amount and time.\n");
    printf("2. Automatic feeding: The cat feeder can automatically feed according to the preset feeding time and feeding amount.\n");
    printf("3. Manual feeding: In special circumstances, users can manually trigger the feeder to feed, such as when they forget to set \n");
    printf("\tthe feeding time for the cat, users can feed the cat manually.\n");
    printf("4. Feeding reminder: The cat feeder can make voice and text reminders 5 minutes before feeding\n");
    printf("5. Feeding log will be saved in the catfeeder.log\n");
    printf("6. Master can find out lastest feeding time in feeding log.\n\n");
}