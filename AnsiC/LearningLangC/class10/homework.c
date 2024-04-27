#include <stdio.h>
#include <stdlib.h>

int read(char filename[],int s[])
{
	int i;
	FILE *f;
	f=fopen("data.txt","r");
	while(!feof(f))
	{
		fscanf(f,"%d",&s[i]);
		i++;
	}
	return i;
}

int sum(int b[],int n)  
{    //功能：对数组b的前n个元素求和;返回和s  
	int s=0,i;
	for(i=0;i<n;i++)
	{
		s=s+b[i];
	}
	return s;
}

void sort(int b[], int n)  //数组b的前n个元素升序排序 
{  
	int i,j;
	int t;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(b[i]>b[j])
			{
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	}
}

int insert(int b[],int n,int x)   
{//在升序的数组中插入一个数x，n为数组元素个数
// 函数返回插入元素后的数组元素个数 
	b[n]=x;
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n+1;j++)
		{
			if(b[i]>b[j])
			{
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	}
	return n+1;
}

int dele(int b[],int n,int x)
{
	// 删除数组b中值为x的元素，n代表数组中元素的个数; 函数返回删除该元素后的剩余元素个数。 
	//如果x不存在，则输出"没找到"，并返回原数据个数。 
	int i,j;
	int index;
    index=-1;
    for(i=0;i<n;i++)
    {
        if(x==b[i])
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
            b[j]=b[j+1];
        }
		return n-1;
    }
	else 
		printf("not found");
		return n;
}

void printarr(int b[],int n) 
{//显示数组b中的前n个元素 
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",b[i]);
	}
}

int write(char filename[],int s[],int n)  //将数组s中的n个元素写入到filename文件 
{//功能：将数组s中的前n个元素写入到filename中，正确写入返回1，否则（比如文件打开错误）返回-1。
	FILE *f = fopen(filename, "w");
    if (f==NULL) 
	{
        return -1;
    }
    for (int i=0;i<n;i++) 
	{
        fprintf(f, "%d\n", s[i]);
    }
    fclose(f);
    return 1;
}

void menu()
{
	printf("1----文件中读取数据\n");
	printf("2----对所有数据求和\n");
	printf("3----对所有数据排序\n");
	printf("4----新增一个数据\n");
	printf("5----删除一个数据\n");
	printf("6----输出现有数组内数据\n");
	printf("7----保存数据\n");
	printf("8----退出\n");
}

int main()
{   
    int i,choice;
	int score[60];
	char file[]="data.txt";   //自创一个数据文本文件 
	int n,x;
	menu();
	while(1)
	{
		printf("\n请输入功能选项:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:n=read(file,score);
				printf("%d",n); break;
			case 2:printf("和为%d\n",sum(score,n));break;
			case 3:sort(score,n);break;
			case 4:
			    printf("输入待插入的数：");scanf("%d",&x);
				n=insert(score,n,x);break;
			case 5:
			    printf("输入待删除的数：");scanf("%d",&x);
				n=dele(score,n,x);break;
			case 6:printarr(score,n);break;
			case 7:write(file,score,n);break;
			case 8:exit(0);break;
			default: continue;
		}
		//system("pause");
		//system("cls");
	}
}