/*请大家编程完成以下功能，要求运用结构体及模块化的设计。

提供的数据文件是某平台各家店的信息明细，请读取文件信息存入到对应的数据结构体中，实现如下功能：

1）统计输出综合评分最高的5家店铺信息。

2）输入一家店铺名称，输出其对应的信息。

3）新增加一个店铺信息。

4）按照店铺的名称进行排序，输出店铺名称和对应的综合评分。

有能力的同学可拓展其它功能。参考代码和数据文件见附件。*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 2
struct date
{
	int year;
	int month;
	int day;
};
typedef struct shop
{
	char shop_name[30];
	char type[20];
	int ave_per;
	float shop_score[4];
	int count;
	char address[100];
	struct date shop_open;
} SHOP;

SHOP shops[10000] = {""}; // 全局变量,数组的大小设定注意 ，初始化注意

int read_data(char filename[]); // 函数声明
void sort_by_Avg(int n);
void print(int n);

int read_data(char filename[]) // 函数定义
{
	FILE *fp;
	int i = 0;
	char ss[300], tt[300];
	fp = fopen(filename, "r");

	while (fgets(ss, 200, fp) != NULL) // read a line of string from the file, max length is 200
	{
		// puts(ss);
		sscanf(ss, "%s%s%d%f%d%f%f%f%s%s",
			   shops[i].shop_name, shops[i].type, &shops[i].ave_per, &shops[i].shop_score[0], &shops[i].count,
			   &shops[i].shop_score[1], &shops[i].shop_score[2], &shops[i].shop_score[3], shops[i].address, tt);

		sscanf(tt, "%4d%*c%2d%*c%2d", &shops[i].shop_open.year, &shops[i].shop_open.month, &shops[i].shop_open.day);
		// printf("%s\n",shops[i].shop_name);
		i++;
		// if(i%10==0)
		// system("pause");
	}
	fclose(fp);
	// printf("%d\n",i);
	return i;
}
void print(int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("\n");
		printf("%s\t%s\n", shops[i].shop_name, shops[i].type);
		printf("人均消费%d\n", shops[i].ave_per);
		printf("综合得分\t口味评分\t环境评分\t服务评分\n");
		for (j = 0; j < 4; j++)
		{
			printf("%5.1f\t", shops[i].shop_score[j]);
		}
		printf("\n");
		printf("点评数：%d\n", shops[i].count);
		printf("地址:%s\n开业日期: %4d/%02d/%02d\n", shops[i].address, shops[i].shop_open.year, shops[i].shop_open.month, shops[i].shop_open.day);
	}
}

void exchange2Shop(int i, int j) // 交换结构体
{
	char t1[30];
	strcpy(t1, shops[i].shop_name);
	strcpy(shops[i].shop_name, shops[j].shop_name);
	strcpy(shops[j].shop_name, t1);

	char t2[20];
	strcpy(t2, shops[i].type);
	strcpy(shops[i].type, shops[j].type);
	strcpy(shops[j].type, t2);

	int tInt = 0;
	tInt = shops[i].ave_per;
	shops[i].ave_per = shops[j].ave_per;
	shops[j].ave_per = tInt;

	float tScore = 0;
	for (int k = 0; k < 4; k++)
	{
		tScore = shops[i].shop_score[k];
		shops[i].shop_score[k] = shops[j].shop_score[k];
		shops[j].shop_score[k] = tScore;
	}

	tInt = shops[i].count;
	shops[i].count = shops[j].count;
	shops[j].count = tInt;

	char t3[100];
	strcpy(t3, shops[i].address);
	strcpy(shops[i].address, shops[j].address);
	strcpy(shops[j].address, t3);

	tInt = shops[i].shop_open.year;
	shops[i].shop_open.year = shops[j].shop_open.year;
	shops[j].shop_open.year = tInt;

	tInt = shops[i].shop_open.month;
	shops[i].shop_open.month = shops[j].shop_open.month;
	shops[j].shop_open.month = tInt;

	tInt = shops[i].shop_open.day;
	shops[i].shop_open.day = shops[j].shop_open.day;
	shops[j].shop_open.day = tInt;
}

void list5BestShop(int n) // 1.排名前五的店铺
{
	float sumScore[10000];
	float tSum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sumScore[i] += shops[i].shop_score[j];
		}
		sumScore[i] = (float)shops[i].count;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sumScore[i] < sumScore[j])
			{
				exchange2Shop(i, j);
				tSum = sumScore[i];
				sumScore[i] = sumScore[j];
				sumScore[j] = tSum;
			}
		}
	}

	// printf("排名前五的店铺为:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", shops[i].shop_name);
	}
}

void searchShops(char search[], int n) // 2.搜索店铺
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(search, shops[i].shop_name) == 0)
		{
			printf("\n");
			printf("%s\t%s\n", shops[i].shop_name, shops[i].type);
			printf("人均消费%d\n", shops[i].ave_per);
			printf("综合得分\t口味评分\t环境评分\t服务评分\n");
			for (int j = 0; j < 4; j++)
			{
				printf("%5.1f\t", shops[i].shop_score[j]);
			}
			printf("\n");
			printf("点评数：%d\n", shops[i].count);
			printf("地址:%s\n开业日期: %4d/%02d/%02d\n", shops[i].address, shops[i].shop_open.year, shops[i].shop_open.month, shops[i].shop_open.day);
			flag = 1;
		}
		else
			break;
	}

	if (flag == 0)
		printf("未搜索到相关店铺\n");
}

int insertShop(char filename[], int n)
{
	FILE *fp;
	fp = fopen(filename, "a");

	printf("输入店铺名称: ");
	scanf("%s", shops[n].shop_name);
	printf("输入店铺类型: ");
	scanf("%s", shops[n].type);
	printf("\n输入店铺人均消费: ");
	scanf("%d", &shops[n].ave_per);

	printf("\n综合得分\t口味评分\t环境评分\t服务评分\n ");
	scanf("%f%f%f%f", &shops[n].shop_score[0], &shops[n].shop_score[1], &shops[n].shop_score[2], &shops[n].shop_score[3]);

	printf("\n点评数: ");
	scanf("%d", &shops[n].count);

	printf("\n地址:");
	scanf("%s", shops[n].address);

	printf("\n开业日期: ");
	scanf("%d%d%d", &shops[n].shop_open.year, &shops[n].shop_open.month, &shops[n].shop_open.day);

	fprintf(fp, "\n%s\t%s\t%d\t%5.1f\t%d\t%5.1f\t%5.1f\t%5.1f\t%s\t%4d/%02d/%02d",
			shops[n].shop_name, shops[n].type, shops[n].ave_per, shops[n].shop_score[0], shops[n].count,
			shops[n].shop_score[1], shops[n].shop_score[2], shops[n].shop_score[3], shops[n].address, shops[n].shop_open.year, shops[n].shop_open.month, shops[n].shop_open.day);
	n = n + 1;

	fclose(fp);
	return n;
}

void sortShop(int n) // 4.按照店铺的名称进行排序
{
	float sumScore[10000];
	float tSum = 0;

	for (int i = 0; i < n; i++)
	{
		sumScore[i] = 0;
		for (int j = 0; j < 4; j++)
		{
			sumScore[i] += shops[i].shop_score[j];
		}
		sumScore[i] = sumScore[i] * (float)shops[i].count;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(shops[i].shop_name, shops[j].shop_name) > 0)
			{
				exchange2Shop(i, j);
				tSum = sumScore[i];
				sumScore[i] = sumScore[j];
				sumScore[j] = tSum;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s\t%.2f\n", shops[i].shop_name, shops[i].shop_score[0]);
	}
}

void menu() // 函数体
{
	printf("1----统计输出综合评分最高的5家店铺信息\n");
	printf("2----输入一家店铺名称，输出其对应的信息\n");
	printf("3----新增加一个店铺信息\n");
	printf("4----按照店铺的名称进行排序，输出店铺名称和对应的综合评分\n");
	printf("5----exit\n");
}

int main() // 主控函数
{
	menu();
	int n;
	n = read_data("food.txt");
	// print(n);

	int choice;
	char search[30];

	while (1)
	{
		printf("input your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("排名前五的店铺为:\n");
			list5BestShop(n);
			break;
		case 2:
			printf("输入需要查询的店铺名称: ");
			scanf("%s", search);
			searchShops(search, n);
			break;
		case 3:
			n = insertShop("food.txt", n);
			break;
		case 4:
			sortShop(n);
			break;
		case 5:
			exit(0);
			break;
		default:
			continue;
		}
	}
}
