#include <stdio.h>
#include <string.h>
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
		printf("地址:%s\n开业日期：%4d/%02d/%02d\n", shops[i].address, shops[i].shop_open.year, shops[i].shop_open.month, shops[i].shop_open.day);
	}
}
int main() // 主控函数
{

	int n;
	n = read_data("food2.txt");
	print(n);

	return 0;
}
