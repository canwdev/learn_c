#include<stdio.h>
//ASCII

int main()
{
	
	int a;
	puts("ASCII");
	for(a=0;a<=128;++a)
	{
		printf("char=%c\tdec=%d\toct=%o\thex=%x\t\n",a,a,a,a);
	}
	getch();
	return 0;
}
