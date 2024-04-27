#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "color.h"

void main()
{
    for(int i=0;i<10;i++)
    {
        for (int j=0;j<i+1;j++)
        {
            color((short)j);
            printf("*");
        }
        printf("\n");
    }
}