#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//0916注释
int main()
{
	unsigned int a = 10;
	double d = 90.9;
	int c = a+d;


	//char c = 1;
	//printf("%u\n", sizeof(c));//1
	//printf("%u\n", sizeof(+c));//4
	//printf("%u\n", sizeof(!c));//4
	//char a = 1;//0000000000000000000000 0001
	//char b = 2;//00000000000000000000000010
	//char c = a+b;
	////printf("%d\n",sizeof(a+b));
	return 0;
}

#if 0
struct Student
{
	char name[10];
	int age;
};//模板
void Show1(struct Student stu)
{
	printf("%s,%d\n",stu.name,stu.age);
}

void Show(struct Student *pstu)
{
	//printf("%s,%d\n",(*pstu).name,(*pstu).age);
	printf("%s,%d\n",pstu->name,pstu->age);//-> 自带解引用
}

int main()
{
	struct Student stu1 = {"caocao",99};
	stu1.age = 199;
	//stu1.name = "caomengde";
	//0x9999 = "caomengde";
	strcpy(stu1.name,"caomengde");

	Show(&stu1);


	//printf("%s,%d\n",stu1.name,stu1.age);

	//struct Student stu2 = {"liubei",99};
	//struct Student stu3 = {"gaunyu",99};
	//struct Student stu4 = {"zhangfei",99};//实体
	return 0;
}



int main()
{
	int a = 1;
	int b = 2;
	int c = (a>b, a=b+10, a, b=a+1);
	printf("%d\n",c);
	return 0;
}


int Max(int a,int b)
{
	return a > b ? a : b;
}

int main()
{
	int a = 1;
	int b = 0;
	int c = 2;
	if(a++  || b++ || c++)
	{
		printf("hhhhhh\n");
	}
	else
	{
		printf("xxxxxxxx\n");
	}
	printf("%d,%d,%d\n",a,b,c);
	//int i = 0,a=0,b=2,c =3,d=4;
	////i = a++ && ++b && d++;
	//i = a++||++b||d++;
	//printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);
	//char ch = 'h';
	//char *pc = &ch;


	//printf("%d\n",sizeof(int *));
	//printf("%d\n",sizeof(char *));
	//printf("%d\n",sizeof(short *));
	//int a =(int)(10+4.9);
	//////a++;
	//////++a;
	////int b = ++a;
	////printf("%d\n",b);
	return 0;
}


//4     32  
int NumOfOne1(unsigned int num)
{
	int count = 0;

	while(num != 0)
	{
		if((num % 2) == 1)
		{
			count++;
		}
		num /= 2;
	}

	return count;
}
int NumOfOne2( int num)
{
	int count = 0;
	int i = 0;
	for(i = 0;i < 32;i++)
	{
		if( ((num >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;
}
int NumOfOne( int num)
{
	int count = 0;
	while(num != 0)
	{
		count++;
		num = num & (num-1);
	}
	return count;
}
/*
在编译期  确定表达式  的字节大小
*/
int main()
{

	//int arr[10] = {1,2,3,4,5,6,7};
	//printf("%d\n",sizeof(arr[10]));//
	int i = 10;
	//i++;
	printf("%d\n",sizeof(++i));//4   
	printf("%d\n",i);//10

	printf("%d\n",sizeof(1+3.5));//

	printf("%d\n",sizeof(NumOfOne(4)));

	//int num = 7;//
	////num += 10;//num = num+10
	//printf("%d\n",!num);//0
	//printf("%d\n",!!num);//1
	return 0;
}
#endif

