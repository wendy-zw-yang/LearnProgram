/*���ұ��������¹��ܣ�Ҫ�����ýṹ�弰ģ�黯����ơ�

�ṩ�������ļ���ĳƽ̨���ҵ����Ϣ��ϸ�����ȡ�ļ���Ϣ���뵽��Ӧ�����ݽṹ���У�ʵ�����¹��ܣ�

1��ͳ������ۺ�������ߵ�5�ҵ�����Ϣ��

2������һ�ҵ������ƣ�������Ӧ����Ϣ��

3��������һ��������Ϣ��

4�����յ��̵����ƽ�����������������ƺͶ�Ӧ���ۺ����֡�

��������ͬѧ����չ�������ܡ��ο�����������ļ���������*/

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

SHOP shops[10000] = {""}; // ȫ�ֱ���,����Ĵ�С�趨ע�� ����ʼ��ע��

int read_data(char filename[]); // ��������
void sort_by_Avg(int n);
void print(int n);

int read_data(char filename[]) // ��������
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
		printf("�˾�����%d\n", shops[i].ave_per);
		printf("�ۺϵ÷�\t��ζ����\t��������\t��������\n");
		for (j = 0; j < 4; j++)
		{
			printf("%5.1f\t", shops[i].shop_score[j]);
		}
		printf("\n");
		printf("��������%d\n", shops[i].count);
		printf("��ַ:%s\n��ҵ����: %4d/%02d/%02d\n", shops[i].address, shops[i].shop_open.year, shops[i].shop_open.month, shops[i].shop_open.day);
	}
}

void exchange2Shop(int i, int j) // �����ṹ��
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

void list5BestShop(int n) // 1.����ǰ��ĵ���
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

	// printf("����ǰ��ĵ���Ϊ:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", shops[i].shop_name);
	}
}

void searchShops(char search[], int n) // 2.��������
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(search, shops[i].shop_name) == 0)
		{
			printf("\n");
			printf("%s\t%s\n", shops[i].shop_name, shops[i].type);
			printf("�˾�����%d\n", shops[i].ave_per);
			printf("�ۺϵ÷�\t��ζ����\t��������\t��������\n");
			for (int j = 0; j < 4; j++)
			{
				printf("%5.1f\t", shops[i].shop_score[j]);
			}
			printf("\n");
			printf("��������%d\n", shops[i].count);
			printf("��ַ:%s\n��ҵ����: %4d/%02d/%02d\n", shops[i].address, shops[i].shop_open.year, shops[i].shop_open.month, shops[i].shop_open.day);
			flag = 1;
		}
		else
			break;
	}

	if (flag == 0)
		printf("δ��������ص���\n");
}

int insertShop(char filename[], int n)
{
	FILE *fp;
	fp = fopen(filename, "a");

	printf("�����������: ");
	scanf("%s", shops[n].shop_name);
	printf("�����������: ");
	scanf("%s", shops[n].type);
	printf("\n��������˾�����: ");
	scanf("%d", &shops[n].ave_per);

	printf("\n�ۺϵ÷�\t��ζ����\t��������\t��������\n ");
	scanf("%f%f%f%f", &shops[n].shop_score[0], &shops[n].shop_score[1], &shops[n].shop_score[2], &shops[n].shop_score[3]);

	printf("\n������: ");
	scanf("%d", &shops[n].count);

	printf("\n��ַ:");
	scanf("%s", shops[n].address);

	printf("\n��ҵ����: ");
	scanf("%d%d%d", &shops[n].shop_open.year, &shops[n].shop_open.month, &shops[n].shop_open.day);

	fprintf(fp, "\n%s\t%s\t%d\t%5.1f\t%d\t%5.1f\t%5.1f\t%5.1f\t%s\t%4d/%02d/%02d",
			shops[n].shop_name, shops[n].type, shops[n].ave_per, shops[n].shop_score[0], shops[n].count,
			shops[n].shop_score[1], shops[n].shop_score[2], shops[n].shop_score[3], shops[n].address, shops[n].shop_open.year, shops[n].shop_open.month, shops[n].shop_open.day);
	n = n + 1;

	fclose(fp);
	return n;
}

void sortShop(int n) // 4.���յ��̵����ƽ�������
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

void menu() // ������
{
	printf("1----ͳ������ۺ�������ߵ�5�ҵ�����Ϣ\n");
	printf("2----����һ�ҵ������ƣ�������Ӧ����Ϣ\n");
	printf("3----������һ��������Ϣ\n");
	printf("4----���յ��̵����ƽ�����������������ƺͶ�Ӧ���ۺ�����\n");
	printf("5----exit\n");
}

int main() // ���غ���
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
			printf("����ǰ��ĵ���Ϊ:\n");
			list5BestShop(n);
			break;
		case 2:
			printf("������Ҫ��ѯ�ĵ�������: ");
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
