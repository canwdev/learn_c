#include<stdio.h>
#include"title_display.h"
//ASCII

int main()
{
	
	int a;
	title_display("ASCII ", 30);
	for(a=0;a<=128;++a)
	{
		printf("char=%c\tdec=%d\toct=%o\thex=%x\t\n",a,a,a,a);
	}
	title_display("OK", 30);
	getch();
	return 0;
}
