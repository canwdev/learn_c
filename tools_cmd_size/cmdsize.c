//CAN ORIGINAL CODE PROJECT
#include<stdio.h>

void readme();
void custom_size();
void all_size();

int main()
{
	int s;
	system("mode con cols=63 lines=21"); 			//���ô��ڴ�С

	while(s)
		{
			system("cls");
			system("title CMD WINDOW SZIE"); 					//���ô��ڱ���

			readme();
			printf("\n1.CMD �����Զ��仯\n2.�Զ��崰�ڴ�С\n?.����ѡ��: ");
			while (!(scanf("%d",&s)))
				{
					fflush(stdin);
					printf("* �����������������: ");

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
	system("title �Զ��崰�ڴ�С");
	for(;;)
		{
			readme();
			printf("\n	x=%d	y=%d\n",x,y);
			printf("\n���볤�Ϳ����ֵ������00����~\n");
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
	system("title CMD �����Զ��仯");
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
