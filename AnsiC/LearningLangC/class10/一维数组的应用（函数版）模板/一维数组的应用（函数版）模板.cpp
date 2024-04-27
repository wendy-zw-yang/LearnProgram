#include <stdio.h>
#include <stdlib.h>
void printarr(int b[],int n) 
{//显示数组b中的前n个元素 
 
}
int read(char filename[],int s[])   
{//功能：从filename中读取数据存入到数组s中，返回的时候读取到的数据个数。 
 
   
}

int write(char filename[],int s[],int n)  //将数组s中的n个元素写入到filename文件 
{//功能：将数组s中的前n个元素写入到filename中，正确写入返回1，否则（比如文件打开错误）返回-1。
 
}
void add(int b[],int n,int m)
{//功能：实现对数组b的前n个元素的值都增加m   
 
}
int sum(int b[],int n)  
{    //功能：对数组b的前n个元素求和;返回和s 

}
void sort(int b[], int n)  //数组b的前n个元素升序排序 
{  


}
int find(int b[], int n,int x)  //顺序查找数组b中x是否存在 ,找到则返回下标，没找到则返回-1 
{ 

}

int find2(int b[], int n,int x)  
{  
//升序基础上，利用二分法查找数组b中x是否存在 ,存在则返回下标 ，否则返回-1 

}
int dele(int b[],int n,int x)
{
	// 删除数组b中值为x的元素，n代表数组中元素的个数; 函数返回删除该元素后的剩余元素个数。 
	//如果x不存在，则输出"没找到"，并返回原数据个数。 
	
}

int insert(int b[],int n,int x)   
{//在升序的数组中插入一个数x，n为数组元素个数
// 函数返回插入元素后的数组元素个数 
	
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
{   int i,choice;
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
			case 1:n=read(file,score);break;
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

