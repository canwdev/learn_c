//CAN ORIGINAL CODE PROJECT
#include<stdio.h>

void readme();
void readme1();
void custom_color();
void all_color();

int main()
{
	int s;
	system("mode con cols=63 lines=21"); 			//设置窗口大小

	while(s)
		{
			system("cls");
			system("title CMD COLORS 2.1"); 					//设置窗口标题

			readme1();
			printf("\n1.CMD 颜色显示器\n2.自定义颜色\n?.输入选项: ");
			while (!(scanf("%d",&s)))
				{
					fflush(stdin);
					printf("* 输入错误，请输入数字: ");

				}
			switch(s)
				{
					case 1:
						system("cls");
						all_color();
						break;
					case 2:
						custom_color();
						break;
				}

		}

	return 0;
}

void custom_color()
{
	char x,y;
	char setting[30];
	system("cls");
	system("title 自定义颜色");
	for(;;)
		{
			readme1();
			printf("\n	x=%c		y=%c\n",x,y);
			printf("\n输入前景和背景颜色，输入q结束~\n");
			fflush(stdin);
			x=getch();
			if ( x=='q' )
				return;
			y=getch();

			system("cls");
			
			if ( ( x>='0' && x<='9' || x>='a' && x<='f' || x>='A' && x<='F' ) && ( y>='0' && y<='9' || y>='a' && y<='f' || y>='A' && y<='F' ) )
				{
					sprintf(setting,"color %c%c",x,y);
					system(setting);

				}
			else
				{
					printf("* 输入错误!\n");
					//system("pause");
				}

		}

	system("pause");
}

void all_color()
{
	int i,j;
	char input;
	char cmdcolor[16]="0123456789ABCDEF";
	char setting[30];
	system("title CMD 颜色显示器");
	for(;;)
		for(j=0; j<16; ++j)
			for(i=0; i<16; ++i)
				{
					sprintf(setting,"color %c%c",cmdcolor[j],cmdcolor[i]);
					printf("color %c%c",cmdcolor[j],cmdcolor[i]);
					readme();
					system(setting);

					printf("Enter q to terminate.");
					input=getch();

					if(input == 'q')
						return;

					system("cls");
				}
}

void readme1()
{
	char a;
	FILE *pf;
	if((pf=fopen("color.txt", "r"))==NULL)
		{
			printf("* 文件不存在\n");
			return;
		}
	if(a=fgetc(pf) == EOF)
		printf("* 文件为空\n");
	rewind(pf);
	while((a=fgetc(pf))!=EOF)
		{
			printf("%c",a);
		}
	printf("\n");
	fclose(pf);
	//system("pause");
}

void readme()
{
	puts(" 《云》\n  ");
	puts("难期怪雨去迢迢，\n");
	puts("家在惊合水且涸。\n");
	puts("作是俱鲜凝望久，\n");
	puts("收拾半堕槿篱斜。\n");
}
