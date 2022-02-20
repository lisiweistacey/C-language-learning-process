#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
int ret = 0;
void menu()
{
	printf("***********************************\n");
	printf("****** 1.play ***** 0.exit ********\n");
	printf("***********************************\n");
}
void game()
{
	//创建数组
	char arr[ROW][COL] = {0};
	//初始化棋盘
	InitBoard(arr, ROW, COL);
	DisplayBoard(arr, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(arr, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//电脑下棋
		ComputerMove(arr, ROW, COL);
		DisplayBoard(arr, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(arr, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误，请重新选择");
			break;
		}
		
	}while (input);
}
int main()
{
	test();
	return 0;
}
