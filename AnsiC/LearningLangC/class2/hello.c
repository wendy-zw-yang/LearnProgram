#include <stdio.h>
#include <conio.h> //引入getch的类
int main(int nArg, char *argu[], char *envir[])
{

    printf("Hello World\n");
    system("pause");
    printf("We have %d parameters\n", nArg);
    printf("Let's say hello to each parameter\n");
    system("pause");
    if(nArg>1)
    {
        for(int i=0;i<nArg;i++)
        {
            printf("Hello %s\n",argu[i]);
        }
    }
    return 1;
}