#include <stdio.h>
#include <stdlib.h>
int main()
{
    float score[1000];
    int i=0,j;
    FILE *f;
    f=fopen("D:\\DocumentCenter\\score.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%f",&score[i]);
        i++;
    }
    //取数组中数据
    fclose(f);
    
    
    
    /////////////////////*将数组中的数按从大到小排序*/////////////////////
    int n=i;
    float max,t;
    //外循环：进行j次选择
    for(j=1;j<n;j++)
    {
    max=score[j];
    int index=j;
        //内循环：第j次选择过程
        for(i=1;i<n;i++)
        {
            if(score[i]>=max) //筛选最大值
            {
                max=score[i];
                index=i;
            }
        }
    t=score[j];
    score[j]=score[index];
    score[index]=t;
    //把每一次选择中的最大值放在第j个位置q
    }
    for(i=0;i<n;i++)
    {
        printf("%5.1f",score[i]);
    }
    
    
    
    /////////////////////////////*查找特定数*////////////////////////////////
    float x;
    printf("\n输入要查找的数: ");
    scanf("%f",&x);
    
    //直接查找
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(x==score[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("\n该数存在");
    else
        printf("\n该数不存在");
    
    //二分法查找
    int low,high,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x==score[mid])
            break;
        else if(x>score[mid])
            high=mid-1;
            else if(x<score[mid])
                low=mid+1;
    }
    if(low<=high)
        printf("\n该数存在");
    else
        printf("\n该数不存在");
    
    
    
    ///////////////////////////////*删除数*/////////////////////////////////
    printf("\n输入待删除的数: ");
    scanf("%f",&x);
    int index;
    index=-1;
    for(i=0;i<n;i++)
    {
        if(x==score[i])
        {
            index=i;
            break;
        }
    }
    //判断是否为数组中的数
    if(index>=0)
    {

        for(j=index;j<n-1;j++)  //往前推进一个数
        {
            score[j]=score[j+1];
        }
        for(i=0;i<n-1;i++)  //输出删除后的n-1个数
        {
            printf("%5.1f",score[i]);
        }
    }
}