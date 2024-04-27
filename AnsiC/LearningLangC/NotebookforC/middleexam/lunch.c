#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    FILE *t;
    t=fopen("","r+");
    int a=0,b=0,c=0,d=0;
    int i,k;
    int num;
    srand(time(NULL));
    printf("");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        k=rand() %4 +1;
        printf("");
        switch(k)
        {
            case 1: a++; break;
            case 2: b++; break;
            case 3: c++; break;
            case 4: d++; break;
        }
    }
    fprintf(t,"",a,b,c,d);
    fclose();
}