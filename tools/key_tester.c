#include<stdio.h>
#include<windows.h> 

int main()
{
	system("title ����������");
	system("color 0a");

	printf("�������ⰴ����\n");
	char a;
	for(;;)
	{
		a=getch();
		printf("char=%c\tdec=%d\toct=%o\thex=%x\t\n",a,a,a,a);
	}
	return 0;
}
