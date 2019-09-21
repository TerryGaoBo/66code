#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int menu()
{
	printf("************1.play************\n");
	printf("*****************************\n");
	printf("***********0.exit*************\n");
	printf("请输入你的选择:");
	int choice;
	scanf("%d\n", &choice);
	return choice;
}
void initboard(char board[][3])
{
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void showboard(char board[][3]) 
{
	for (int i = 0; i < 3; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		printf("---|---|---\n");
	}
}
void playermove(char board[][3])
{
	printf("玩家落子\n");
	while (1)
	{
		int i = 0;
		int j = 0;
		printf("请输入一组坐标(i j):");
		scanf("%d %d", &i, &j);
		if (i<0 || i>3 || j<0 || j>3)
		{
			printf("你输入的坐标非法\n");
			continue;
		}
	    if (board[i][j] != ' ')
		{
			printf("该坐标已经有子\n");
			continue;
		}
		board[i][j] = 'X';
		break;
	}
}
void computermove(char board[][3])
{
	printf("电脑落子\n");
	while (1);
	{
		int i = rand() % 3;
		int j = rand() % 3;
		if (board[i][j] == ' ')
		{
			board[i][j] = 0;
		}
	}
}
int isfull(char board[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char iswin(char board[][3])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	for (j = 0; j < 3; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
			return board[0][j];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ');
	    return board[0][2];
		if (isfull(board))
		{
			return 'q';
		}
		return ' ';
}
void game()
{
	char board[3][3];

	initboard(board);
	char winner = ' ';
	while (1)
	{
		showboard(board);
		playermove(board);
		if (winner != ' ')
		{
			break;
		}
		computermove(board);
		if (winner != ' ')
		{
			break;
		}
		winner = iswin(board);
		if (winner == 'X')
		{
			printf("玩家胜\n");
		}
		if (winner == '0')
		{
			printf("电脑胜\n");
		}
		if (winner == 'q')
		{
			printf("和局\n");
		}

		
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		int choice =menu();
		if (choice = 1)
		{
			game();
		}
		else
		{
			printf("再见了您嘞\n");
			break;
		}
		
	}
	return 0;
}




#if 0
/**
1、void  
2、什么类型的指针，就在皆解引用的时候，解引用几个字节
3、大小端？？？？？
4、指针加减整数   几个字节？？？
5、数组名代表数组首元素的地址。
6、sizeof(arr)：整个数组的字节大小
7、p[i] ===》 *(p+i)   []：自带解引用
8、指针-指针：只有在两个指针同时作用于同一块内存时，
才有意义。
9、指针数组：数组。存放指针的数组。
     数组指针   函数指针   
*/

int main()
{
	//char *p = "hello";
	//printf("%s\n",p);
	char *str[3] = {"hello","bit","gaobo"};
	int i = 0;
	for(i = 0;i < 3;i++)
	{
		printf("%s\n",str[i]);
	}

	return 0;
}



int main()
{

	int arr1[3] = {1,2,3};
	int arr2[3] = {4,5,6};
	int arr3[3] = {7,8,9};
	int arr4[3] = {10,11,12};

	int *p[4] = {arr1,arr2,arr3,arr4};

	int i = 0;
	for(i = 0;i < 4;i++)
	{
		int j = 0;
		for(j = 0;j < 3;j++)
		{
			printf("%d ",  *(*(p+i)+j));
		}
		printf("\n");
	}


	/*int len = sizeof(p)/sizeof(p[0]);
	printf("%d\n",len);*/




	/*int a = 10;
	int b = 20;
	int c = 30;
	int* arr[3] = {&a,&b,&c};*/

	//int arr2[3] = {1,2,3};
	return 0;
}


int main()
{
	int a = 10;
	int b = 20;

	int *p = &a;
	int **p2 = &p;

     *p2 = &b;
	**p2 = 100;

	printf("%d,%d\n",a,b);

	return 0;
}


int main()
{
	int values[5];
	int *vp;
	for(vp = &values[5]; vp > &values[0];)
	{
		//*--vp = 0;
		--vp;
		*vp = 0;
	}



	////指针+-整数；指针的关系运算
	//for (vp = &values[0]; vp < &values[5];)
	//{
	//	//*vp++ = 0;
	//	*vp = 0;
	//	vp++;
	//}
	return 0;
}


int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	int arr2[10] = {1,2,3,4,5,6,7,8,9,0};

	int *p = &arr[4];

	int *p2 = &arr2[2];

	printf("%d\n",p-p2);

	return 0;
}



void Show(int *p,int len)
{
	//int len = sizeof(p)/sizeof(p[0]); error
	int i = 0;
	for(i = 0; i< len;i++)
	{
		//printf("%d ",p[i]);
		printf("%d ",   *(p+i));
	}
}
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	int len = sizeof(arr)/sizeof(arr[0]);
	//int *p = arr;
	Show(arr,len);
	/*printf("%p\n", arr);
	printf("%p\n", &arr[0]);*/
	return 0;
}

int main()
{
	int n = 0x12345678;
	char *pc =  (char*)&n;
	*pc = 0x99;
	printf("%x\n",n);

	return 0;
} 

int main()
{
	int n = 0x12345678;
	char *pc =  (char*)&n;
	if(*pc == 0x78)
	{
		printf("is little\n");
	}
	else
	{
		printf("is not little\n");
	}

	/*int a = 10;
	int *p = &a;
	printf("%d\n",*p);*/


	//int *pi = &n;

	//printf("%p\n", &n);
	//printf("%p\n", pc);
	//printf("%p\n", pc+1);
	//printf("%p\n", pi);
	//printf("%p\n", pi+1);
	return 0;
} 


/*
野指针:  悬挂指针
面试问题：
如何预防野指针？  
*/
int main()
{
	int *p = NULL;//  野指针
	printf("%d\n",*p);
}


int fun()
{
	static int count = 1;
	return ++count;
}
int main()
{
	char ch = 9;
	char *pc = &ch;

	short sh = 10;
	short *ps = &sh;
	short *ps2 = (short *)&ch;
	

	void *pv = &ch;
	void *pv2 = &sh;

	//printf("%d\n",*ps);//10
	//printf("%d\n",ps);//100
	//printf("%d\n",ps+1);//102

	printf("%d\n",pv2);//10
	printf("%d\n",pv2+1);//10

	//int answer;
	//int a = fun() ;
	//int b = fun();
	//int c = fun();
	//answer = a - b * c;
	//printf( "%d\n", answer);//输出多少？
	//int i = 1;
	//int ret = (++i) + (++i) + (++i);
	//printf("%d\n", ret);
	//printf("%d\n", i);
	return 0;
}
#endif