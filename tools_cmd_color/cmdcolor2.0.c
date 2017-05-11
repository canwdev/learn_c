#include<stdio.h>

void readme1();
void printf_tool();
void all_color();

int main()
{
	system("title CMD 颜色显示器2.0"); 					//设置窗口标题
	system("mode con cols=84 lines=30"); 			//设置窗口大小
	readme1();
	system("cls");
	all_color();
	return 0;
}

void all_color()
{
	int i,j;
	char cmdcolor[16]="0123456789ABCDEF";
	char setting[30];
	for(;;)
		for(j=0; j<16; ++j)
			for(i=0; i<16; ++i)
				{
					sprintf(setting,"color %c%c",cmdcolor[j],cmdcolor[i]);
					printf("color %c%c",cmdcolor[j],cmdcolor[i]);
					readme();
					system(setting);
					system("pause");
					system("cls");
				}
}

void readme1()
{
	char a;
	FILE *pf;
	if((pf=fopen("readme.txt", "r"))==NULL)
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
	system("pause");
}

void readme()
{
	puts(" 《云》\n  ");
	puts("难期怪雨去迢迢，\n");
	puts("家在惊合水且涸。\n");
	puts("作是俱鲜凝望久，\n");
	puts("收拾半堕槿篱斜。\n");
}
