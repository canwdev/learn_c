//CAN ORIGINAL CODE PROJECT
#include<stdio.h>

void readme();
void readme1();
void custom_color();
void all_color();

int main()
{
	int s;
	system("mode con cols=63 lines=21"); 			//���ô��ڴ�С

	while(s)
		{
			system("cls");
			system("title CMD COLORS 2.1"); 					//���ô��ڱ���

			readme1();
			printf("\n1.CMD ��ɫ��ʾ��\n2.�Զ�����ɫ\n?.����ѡ��: ");
			while (!(scanf("%d",&s)))
				{
					fflush(stdin);
					printf("* �����������������: ");

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
	system("title �Զ�����ɫ");
	for(;;)
		{
			readme1();
			printf("\n	x=%c		y=%c\n",x,y);
			printf("\n����ǰ���ͱ�����ɫ������q����~\n");
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
					printf("* �������!\n");
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
	system("title CMD ��ɫ��ʾ��");
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
			printf("* �ļ�������\n");
			return;
		}
	if(a=fgetc(pf) == EOF)
		printf("* �ļ�Ϊ��\n");
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
	puts(" ���ơ�\n  ");
	puts("���ڹ���ȥ������\n");
	puts("���ھ���ˮ�Һԡ�\n");
	puts("���Ǿ��������ã�\n");
	puts("��ʰ�������б��\n");
}
