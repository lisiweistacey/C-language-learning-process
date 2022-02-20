#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("******************************\n");
	printf("******1. play****0. exit******\n");
	printf("******************************\n");
}
void game()
{
	//雷的信息存储（布置雷）
	//1布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2排查出的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	//printf("\n");
	DisplayBoard(show, ROW, COL);
	printf("\n");
	//布置雷
	SetMine(mine, ROW, COL);
	//扫雷
	//DisplayBoard(mine, ROW, COL);
	//printf("\n");
	FindMine(mine, show, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出成功\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}
