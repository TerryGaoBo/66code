#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
/*
1、打断点
2、F5
3、f10    f11
*/
void test3()
{
	printf("hello");
}
void test2()
{
	test3();
}

void test()
{
	test2();
}

int main()
{
	test();
	return 0;
}

#if 0
int main()
{
	int i = 0;
	int count = 0;
	int a = 0;
	for(i = 0;i < 1000;i++)
	{
		count++;
		a = count;
		printf("hhh");
	}

	//int a = 10;
	//int b = 20;
	//int arr[10] = {0};

	//printf("%d,%d,%d,%d\n",&a,&b,&arr[0],&arr[9]);


	/*int i = 0;
	int arr[10] = {0};
	arr[10] = 99;
	printf("%d\n",arr[10]);*/
	//for(i=0; i<=10; i++)
	//{
	//	arr[i] = 0;//arr[12] = 0;-->i -> 0
	//	printf("hehe\n");
	//}
	return 0;
}


void menu()
{
	printf("*****************\n");
	printf("*****0.exit*******\n");
	printf("*****1.play******\n");
	printf("*****************\n");
}
void game()
{
	char mineInfo[ROWS][COLS];//*
	char mine[ROWS][COLS];//'0'

	InitBoard(mineInfo,ROWS,COLS,'*');
	InitBoard(mine,ROWS,COLS,'0');

	ShowBoard(mineInfo,ROWS,COLS);

	SetMine(mine,ROW,COL);

	//ShowBoard(mine,ROWS,COLS);

	FindMine(mineInfo,mine,ROW,COL);

}
int main()
{
	int input = 0;
	srand((unsigned int) time (NULL) );
	do
	{
		menu();
		printf("请输入你的操作：");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			break;
		}
	}while(input);
	return 0;
}
#endif