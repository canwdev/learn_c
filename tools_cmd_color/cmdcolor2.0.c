#include<stdio.h>

void readme1();
void printf_tool();
void all_color();

int main()
{
	system("title CMD ��ɫ��ʾ��2.0"); 					//���ô��ڱ���
	system("mode con cols=84 lines=30"); 			//���ô��ڴ�С
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
	system("pause");
}

void readme()
{
	puts(" ���ơ�\n  ");
	puts("���ڹ���ȥ������\n");
	puts("���ھ���ˮ�Һԡ�\n");
	puts("���Ǿ��������ã�\n");
	puts("��ʰ�������б��\n");
}
