#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c,d;
    for(a=0;a<10;a++)
    {
        for(b=0;b<10;b++)
        {
            for(c=0;c<10;c++)
            {
                for(d=0;d<10;d++)
                {
                    if((a*10+102)*(30+b)==(c*1000+d+750))
                        printf("A=%d,B=%d,C=%d,D=%d\n",a,b,c,d);
                }
            }
        }
    }
}