#include <stdio.h>
#include <string.h>
int main()
{
    char sum[20];
    scanf("%s",sum);
    int k;
    for(int i=0;sum[i]!='\0';i++)
        k++;
    //printf("%d",k);
    for(int i=k-1;i>=0;i--)
    {
        printf("%c",sum[i]);
    }
}