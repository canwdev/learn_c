//CAN ORIGINAL CODE PROJECT 20160620

#include<stdio.h>
#define MAXFN 255
//#define DEBUG

typedef struct
{
	char fname[MAXFN];
	int ro;
} settings;

void load_settings();

int main(void)
{
	int s=1,i;
	settings set;


	while(s)
		{
			system("title �ļ�����"); 					//���ô��ڱ���
			//system("mode con cols=84 lines=30"); 			//���ô��ڴ�С
			system("color 0B");
			load_settings(&set);
			system("cls");
			if(exist_file(&set))
			printf("* ��ѡ���ļ� \"%s\"\n",set.fname);
			else
			printf("* ѡ����ļ� \"%s\" ������\n",set.fname);
			printf("1.����\n");
			printf("2.��ȡ�ļ�\n");
			printf("3.����д��\n");
			printf("4.׷��д��\n");
			printf("5.������\n");
			printf("6.ɾ��\n");
			printf("0.�˳�\n");
			printf("?.ѡ��");
			scanf("%d",&i);
			system("cls");
			switch(i)
				{
					default:
						save_settings(&set);
						return 0;
					case 1:
						modi_settings(&set);
						break;
					case 2:
						show_file(&set);
						break;
					case 3:
						w_file(&set);
						break;
					case 4:
						ab_file(&set);
						break;
					case 5:
						rename_file(&set);
						break;
					case 6:
						del_file(&set);
						break ;
				}
		}

	return 0;
}

void load_settings(settings *set)
{
	int flag=0;
	FILE *pf;
	if( (pf = fopen("file_settings.ini", "r"))==NULL )
		{
			new_settings(set);
			printf("* �½������ļ�...");
			flag=1;
		}
	if( (pf = fopen("file_settings.ini", "r"))==NULL )
		{
			new_settings();
			printf("* �����ļ��½�ʧ��!\n");
			return;
		}
	if(flag)
		printf("�½��ɹ�\n");

	fscanf(pf,"FlieName=%s\nReadOnly=%d\n",&set->fname,&set->ro);

#ifdef DEBUG
	puts("\n     <DEBUG>     ");
	printf("FlieName=%s\nReadOnly=%d\n",set->fname,set->ro);
	puts("     </DEBUG>     \n");
#endif
	fclose(pf);
}

void new_settings()
{
	FILE *pf;
	if( (pf = fopen("file_settings.ini", "w"))==NULL )
		{
			printf("* �����ļ��½�ʧ��\n");
			return;
		}
	settings d_set = { "file_default.txt",0 };
	fprintf(pf,"FlieName=%s\nReadOnly=%d\n",d_set.fname,d_set.ro);
	fclose(pf);


}
void save_settings(settings *set)
{
	FILE *pf;
	if( (pf = fopen("file_settings.ini", "w"))==NULL )
		{
			printf("* �����ļ�����ʧ��\n");
			return;
		}
	fprintf(pf,"FlieName=%s\nReadOnly=%d\n",set->fname,set->ro);
	fclose(pf);
	printf("\n* �����ļ�����ɹ�\n");
}

void modi_settings(settings *set)
{
	int s=1,i;
	char conf;

	system("title �ļ�����-����"); 					//���ô��ڱ���
	//system("mode con cols=84 lines=30"); 			//���ô��ڴ�С
	system("color 0A");
	while(s)
		{
			system("cls");
			load_settings(set);

			printf("1.Ĭ���ļ�����%s\n",set->fname);
			printf("2.ֻ����%s\n",set->ro?"ON":"OFF");
			printf("3.�ָ�Ĭ��\n");
			printf("0.����\n");
			printf("?.ѡ��ѡ�����޸ģ�");
			scanf("%d",&i);

			switch(i)
				{
					default:
						save_settings(set);
						return;
					case 1:
						printf("�����µ�Ĭ���ļ�����");
						scanf("%s",&set->fname);
						save_settings(set);
						break;
					case 2:
						printf("0Ϊ��д��1Ϊֻ����");
						scanf("%d",&set->ro);
						save_settings(set);
						break;
					case 3:
						printf("ȷ�ϻָ���(y/n)��");
						conf=getch();
						if(conf=='y' || conf=='Y')
							new_settings();
						else if(conf=='n' || conf=='N')
							printf("��ȡ��");
						break;
				}
		}
}

void show_file(settings *set)
{
	char a;
	FILE *pf;
	system("title �ļ�����-�ļ�����"); 					//���ô��ڱ���
	//system("mode con cols=84 lines=30"); 			//���ô��ڴ�С
	system("color 0F");
	if( ( pf=fopen(set->fname, "r") ) == NULL )
		{
			printf("* �ļ�������\n");
			return;
		}
	printf("* ���ڶ�ȡ...") ;
	system("cls");
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

int exist_file(settings *set)
{
	FILE *pf;
	if( ( pf=fopen(set->fname, "r") ) == NULL )
		{
			//printf("* �ļ�������\n");
			return 0;
		}
	else
	fclose(pf);
	return 1;
}

void w_file(settings *set)
{
	char a;
	FILE *pf;
	system("title �ļ�����-����д��"); 					//���ô��ڱ���
	//system("mode con cols=84 lines=30"); 			//���ô��ڴ�С
	system("color 0D");

	if( ( pf=fopen(set->fname, "w") ) == NULL )
		{
			printf("* �ļ�����\n");
			return;
		}
	puts("����һ�����֣��� '#' ��ֹ");

	a=getchar();
	while(a!='#')
		{
			fputc(a, pf);
			a=getchar();
		}

	fclose(pf);
	system("pause");
}

void ab_file(settings *set)
{
	char a;
	FILE *pf;
	system("title �ļ�����-׷��д��"); 					//���ô��ڱ���
	//system("mode con cols=84 lines=30"); 			//���ô��ڴ�С
	system("color 0D");

	if( ( pf=fopen(set->fname, "a+b") ) == NULL )
		{
			printf("* �ļ�����\n");
			return;
		}
	puts("����һ�����֣��� '#' ��ֹ");

	a=getchar();
	while(a!='#')
		{
			fputc(a, pf);
			a=getchar();
		}

	fclose(pf);
	system("pause");
}

void rename_file(settings *set)
{
	char rnm[MAXFN],conf;
	system("title �ļ�����-������"); 					//���ô��ڱ���
	//system("mode con cols=84 lines=30"); 			//���ô��ڴ�С
	system("color 0E");
	printf("ԭ�ļ���Ϊ %s �����������ļ�����",set->fname);
	scanf("%s",&rnm);
	if(rename(set->fname,rnm)==NULL)
		{
			printf("* �������ɹ�\n");
			printf("�Ƿ��޸�����-Ĭ���ļ�����(y/n)");
			rename_file_change_settings_fname:
			conf=getch();
			if(conf=='y' || conf=='Y')
			{
				strncpy(set->fname, rnm, MAXFN);
				save_settings(set);
				printf("* �޸�Ĭ���ļ����ɹ�\n");
			}
			else if(conf=='n' || conf=='N')
				printf(" ȡ��\n");
			else
				goto rename_file_change_settings_fname;
		}
	else
		printf("* ������ʧ��\n");
	system("pause");
}

void del_file(settings *set)
{
	char conf;
	system("title �ļ�����-ɾ��"); 					//���ô��ڱ���
	//system("mode con cols=84 lines=30"); 			//���ô��ڴ�С
	system("color 0C");
	printf("ȷ��ɾ���ļ�\"%s\"��(y/n)",set->fname);
	del_file_confirm:
			conf=getch();
			if(conf=='y' || conf=='Y')
			{
				if(remove(set->fname))
				printf("\n* ɾ��ʧ��\n"); 
				else
				printf("\n* �ļ���ɾ��\n");
			}
			else if(conf=='n' || conf=='N')
				printf(" ȡ��ɾ��\n");
			else
				goto del_file_confirm;
	system("pause");
}
