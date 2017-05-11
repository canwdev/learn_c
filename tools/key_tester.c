#include<stdio.h>
#include<windows.h> 

int main()
{
	system("title 按键测试器");
	system("color 0a");

	printf("输入任意按键：\n");
	char a;
	for(;;)
	{
		a=getch();
		printf("char=%c\tdec=%d\toct=%o\thex=%x\t\n",a,a,a,a);
	}
	return 0;
}
