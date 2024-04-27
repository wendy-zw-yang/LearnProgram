#include <stdio.h>
#include <math.h>
int main()
{
    int i,a,b,c;
    i=0;
    for(a=1;a<=6;a++)
    {
        for(b=1;b<=6;b++)
        {
            for(c=1;c<=6;c++)
            {
                if(a!=b && b!=c && a!=c)
                    i=i+1;
            }
        }
    }
    printf("%d",i); 
}