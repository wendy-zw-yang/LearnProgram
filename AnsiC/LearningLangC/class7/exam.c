#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int score,a=0,b=0,c=0,d=0,e=0;
    FILE *t;
    char y,grade;
    do
    {
        printf("input score:");
        scanf("%d",&score);
        getchar();
        t=fopen("D:\\DocumentCenter\\data.txt","r+"); //w+创建并读写
        switch(score/10)
        {
            case 10:
            case 9:grade='A';a++;break;
            case 8:grade='B';b++;break;
            case 7:grade='C';c++;break;
            case 6:grade='D';d++;break;
            default:grade='E';e++;break;
        }
        printf("still input?(y/N)\n");
        scanf("%c",&y);
        getchar();
    } while (y=='y');
    fprintf(t,"A=%d, B=%d, C=%d, D=%d, E=%d",a,b,c,d,e);
    fclose(t);
}