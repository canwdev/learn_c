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
			system("title 文件操作"); 					//设置窗口标题
			//system("mode con cols=84 lines=30"); 			//设置窗口大小
			system("color 0B");
			load_settings(&set);
			system("cls");
			if(exist_file(&set))
			printf("* 已选择文件 \"%s\"\n",set.fname);
			else
			printf("* 选择的文件 \"%s\" 不存在\n",set.fname);
			printf("1.设置\n");
			printf("2.读取文件\n");
			printf("3.覆盖写入\n");
			printf("4.追加写入\n");
			printf("5.重命名\n");
			printf("6.删除\n");
			printf("0.退出\n");
			printf("?.选择：");
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
			printf("* 新建配置文件...");
			flag=1;
		}
	if( (pf = fopen("file_settings.ini", "r"))==NULL )
		{
			new_settings();
			printf("* 配置文件新建失败!\n");
			return;
		}
	if(flag)
		printf("新建成功\n");

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
			printf("* 配置文件新建失败\n");
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
			printf("* 配置文件保存失败\n");
			return;
		}
	fprintf(pf,"FlieName=%s\nReadOnly=%d\n",set->fname,set->ro);
	fclose(pf);
	printf("\n* 配置文件保存成功\n");
}

void modi_settings(settings *set)
{
	int s=1,i;
	char conf;

	system("title 文件操作-设置"); 					//设置窗口标题
	//system("mode con cols=84 lines=30"); 			//设置窗口大小
	system("color 0A");
	while(s)
		{
			system("cls");
			load_settings(set);

			printf("1.默认文件名：%s\n",set->fname);
			printf("2.只读：%s\n",set->ro?"ON":"OFF");
			printf("3.恢复默认\n");
			printf("0.返回\n");
			printf("?.选择选项以修改：");
			scanf("%d",&i);

			switch(i)
				{
					default:
						save_settings(set);
						return;
					case 1:
						printf("输入新的默认文件名：");
						scanf("%s",&set->fname);
						save_settings(set);
						break;
					case 2:
						printf("0为读写，1为只读：");
						scanf("%d",&set->ro);
						save_settings(set);
						break;
					case 3:
						printf("确认恢复？(y/n)：");
						conf=getch();
						if(conf=='y' || conf=='Y')
							new_settings();
						else if(conf=='n' || conf=='N')
							printf("已取消");
						break;
				}
		}
}

void show_file(settings *set)
{
	char a;
	FILE *pf;
	system("title 文件操作-文件内容"); 					//设置窗口标题
	//system("mode con cols=84 lines=30"); 			//设置窗口大小
	system("color 0F");
	if( ( pf=fopen(set->fname, "r") ) == NULL )
		{
			printf("* 文件不存在\n");
			return;
		}
	printf("* 正在读取...") ;
	system("cls");
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

int exist_file(settings *set)
{
	FILE *pf;
	if( ( pf=fopen(set->fname, "r") ) == NULL )
		{
			//printf("* 文件不存在\n");
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
	system("title 文件操作-覆盖写入"); 					//设置窗口标题
	//system("mode con cols=84 lines=30"); 			//设置窗口大小
	system("color 0D");

	if( ( pf=fopen(set->fname, "w") ) == NULL )
		{
			printf("* 文件错误\n");
			return;
		}
	puts("输入一段文字，以 '#' 终止");

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
	system("title 文件操作-追加写入"); 					//设置窗口标题
	//system("mode con cols=84 lines=30"); 			//设置窗口大小
	system("color 0D");

	if( ( pf=fopen(set->fname, "a+b") ) == NULL )
		{
			printf("* 文件错误\n");
			return;
		}
	puts("输入一段文字，以 '#' 终止");

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
	system("title 文件操作-重命名"); 					//设置窗口标题
	//system("mode con cols=84 lines=30"); 			//设置窗口大小
	system("color 0E");
	printf("原文件名为 %s ，请输入新文件名：",set->fname);
	scanf("%s",&rnm);
	if(rename(set->fname,rnm)==NULL)
		{
			printf("* 重命名成功\n");
			printf("是否修改设置-默认文件名？(y/n)");
			rename_file_change_settings_fname:
			conf=getch();
			if(conf=='y' || conf=='Y')
			{
				strncpy(set->fname, rnm, MAXFN);
				save_settings(set);
				printf("* 修改默认文件名成功\n");
			}
			else if(conf=='n' || conf=='N')
				printf(" 取消\n");
			else
				goto rename_file_change_settings_fname;
		}
	else
		printf("* 重命名失败\n");
	system("pause");
}

void del_file(settings *set)
{
	char conf;
	system("title 文件操作-删除"); 					//设置窗口标题
	//system("mode con cols=84 lines=30"); 			//设置窗口大小
	system("color 0C");
	printf("确认删除文件\"%s\"？(y/n)",set->fname);
	del_file_confirm:
			conf=getch();
			if(conf=='y' || conf=='Y')
			{
				if(remove(set->fname))
				printf("\n* 删除失败\n"); 
				else
				printf("\n* 文件已删除\n");
			}
			else if(conf=='n' || conf=='N')
				printf(" 取消删除\n");
			else
				goto del_file_confirm;
	system("pause");
}
