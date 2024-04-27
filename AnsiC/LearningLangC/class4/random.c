#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int a,b,c;
    srand(time(NULL));
    a=rand() % 4;
    b=rand() % 4;
    c=rand() % 100;
    printf("%d,%d,%d",a,b,c);
}