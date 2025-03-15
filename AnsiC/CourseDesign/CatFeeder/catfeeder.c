/*
Author: 杨紫雯
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

#include "headers/catfeeder.h"
#include "headers/menu.h"
#include "headers/timesetting.h"
#include "headers/catdata.h"
#include "headers/feeder.h"
#include "headers/feedalert.h"


int main()
{
    CatList catList;

    initCatList(&catList);
    loadData(&catList);
    
    int choice;
    while (1) 
    {
        displayMenu();
        printf("Please input your choice:\n");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                showCats(&catList);
                system("pause");
                break;
            case 2:
                dataSetting(&catList);
                break;
            case 3:
                feederMods(&catList);
                break;
            case 4:
                queryLastFeedTimeInLog();
                break;
            case 5:
                systemInfo();
                break;
            case 6:
                saveData(&catList);
                destroyCatList(&catList);
                return 0;
            default:
                printf("Invalid choice!\n");
                system("pause");
                break;
        }
    }

    return 0;   
}


