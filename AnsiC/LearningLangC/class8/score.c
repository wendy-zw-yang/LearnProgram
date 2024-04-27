/*从文件中依次读出数据并输出有效数值*/
#include <stdio.h>
int main()
{
    float score[1000];
    int i=0;
    FILE *f;
    f=fopen("D:\\DocumentCenter\\score.txt","r");
    while(!feof(f)) //feof()用于判断指针是否指向文件末尾
    {
        fscanf(f,"%f",&score[i]);
        i++;
    }
    //从文件中依次读入数据
    
    /*fscanf(f,"%f",&score[0]);   //文件指针在第一行，取第一个数
    fscanf(f,"%f",&score[0]);     //指针移动一行，取下一个数为score[0]*/
    int n=i;
    fclose(f);
    
    for(i=0;i<n;i++)
        printf("%.2f\n",score[i]);  //输出所有的数
    
    //求平均数
    float sum=0;                  
    for(i=0;i<n;i++)
    {
        sum=sum+score[i];
    }
    printf("\n平均分为%.2f",sum/n);
    
    //和每个数比较得出最大值
    float max=score[0];
    for(i=1;i<n;i++)               
    {
        if(max<=score[i])
            max=score[i];
    }
    printf("\n最高分为%.2f",max);

    //用“冒泡法”求中间值
    int j;
    //外层循环嵌套：进行j次冒泡
    for(j=1;j<=n-1;j++)
    {
        //内层循环：每次冒泡排序过程
        for(i=0;i<n-j;i++)  //循环条件为i<n-1，只需要判断n-1次
        {
        float t;
            //筛选最值
            if(score[i]>score[i+1])
            {
                t=score[i];
                score[i]=score[i+1];
                score[i+1]=t;
            }
        }
    }
}