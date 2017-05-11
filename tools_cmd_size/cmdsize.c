//CAN ORIGINAL CODE PROJECT
#include<stdio.h>

void readme();
void custom_size();
void all_size();

int main()
{
	int s;
	system("mode con cols=63 lines=21"); 			//设置窗口大小

	while(s)
		{
			system("cls");
			system("title CMD WINDOW SZIE"); 					//设置窗口标题

			readme();
			printf("\n1.CMD 窗口自动变化\n2.自定义窗口大小\n?.输入选项: ");
			while (!(scanf("%d",&s)))
				{
					fflush(stdin);
					printf("* 输入错误，请输入数字: ");

				}
			switch(s)
				{
					case 1:
						system("cls");
						all_size();
						break;
					case 2:
						custom_size();
						break;
				}

		}

	return 0;
}

void custom_size()
{
	int x=0,y=0;
	char setting[30];
	system("cls");
	system("title 自定义窗口大小");
	for(;;)
		{
			readme();
			printf("\n	x=%d	y=%d\n",x,y);
			printf("\n输入长和宽的数值，输入00结束~\n");
			fflush(stdin);
			scanf("%d %d",&x,&y);
			if ( x==0 )
				return;

			system("cls");

			sprintf(setting,"mode con cols=%d lines=%d",x,y);
			system(setting);

		}

	system("pause");
}

void all_size()
{
	int i,j;
	char input;
	int cmdsize[7]= {15,20,30,40,50,60,70};
	char setting[30];
	system("title CMD 窗口自动变化");
	for(;;)
		for(j=0; j<7; ++j)
			for(i=0; i<3; ++i)
				{
					sprintf(setting,"mode con cols=%d lines=%d",cmdsize[j],cmdsize[i]);
					system(setting);
					printf("mode con cols=%d lines=%d\n",cmdsize[j],cmdsize[i]);
					readme();


					printf("Enter q to terminate.");
					input=getch();

					if(input == 'q')
						return;

					//system("cls");
				}
}

void readme()
{
	char a;
	FILE *pf;
	if((pf=fopen("cmdsize.txt", "r"))==NULL)
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
