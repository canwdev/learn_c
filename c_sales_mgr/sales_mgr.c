#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define DEBUG
#define MAX 50
#define MAXSZ 1000
const int title_len = 38;

typedef struct
{
	int number;			//编号（唯一标识符）
	char name[MAX];		//名称
	int many;			//个数
	double in;			//进价
	double out;			//售价
	int inst;			//进货量
	int sold;			//销售量
	double profit;		//利润
} elemtype;

typedef struct
{
	elemtype elem[MAXSZ];
	int length;
} list;

//功能
void opendb(list *L);							//载入文件
void savedb(list *L);							//保存文件
void show_list(list *L);						//显示库存
void add_list(list *L);							//新增物品
int locate_item(list *L, int val);				//定位物品返回地址
void search_list(list *L);						//查询并显示结果
void instock_list(list *L);						//进货
void outstock_list(list *L);					//出货
void del_list(list *L);							//删除物品
void benefit_list(list *L);						//盈利统计
int edit_list(list *L);							//编辑物品信息
void ui_title_display(char title[],int length);	//界面标题边框
void sort_by_num(list *L);						//按编号排序
void advanced_search(list *L);					//高级搜索 
void help();

int main(void)
{
	list L= {{0},0};
	int i,s=1;
	while(s)
		{
			system("title 数据存销管理"); 					//设置窗口标题
			//system("mode con cols=80 lines=20"); 			//设置窗口大小
			system("color 3F"); 							//设置窗口背景与字体颜色
			opendb(&L);
			//ui_title_display("数据存销管理",title_len);
			printf("╔─────────────────────────────────────╗\n");
			printf("│※                            数据存销管理                              ※│ \n");
			printf("╚─────────────────────────────────────╝\n\n");
			printf("                                1.显示库存\n");
			printf("                                2.新增数据\n");
			printf("                                3.查询数据\n");
			printf("                                4.进货\n");
			printf("                                5.出货\n");
			printf("                                6.删除数据\n");
			printf("                                7.利润统计\n");
			printf("                                8.数据编辑\n\n");
			printf("                                0.保存并退出\n\n");
			printf("──────────────────────────────────────\n\n");
			printf("                                ?.选择一项功能: ");
			while (!(scanf("%d",&i)))
				{
					fflush(stdin);		//清除输入缓存，类似于cin.clear()
					//while (getchar()!='\n')
					//	continue;
					printf("* 输入错误，请输入数字: ");

				}
			//scanf("%d",&i);
			system("cls");
			switch(i)
				{
					default:
						printf(" * 输入错误，重新输入\n");
						break;
					case 0:
						savedb(&L);
						exit(0);
						break;
					case 10:
						exit(0);
						break;
					case 1:
						show_list(&L);
						break;
					case 2:
						add_list(&L);
						savedb(&L);
						break;
					case 3:
						search_list(&L);
						break;
					case 4:
						instock_list(&L);
						savedb(&L);
						break;
					case 5:
						outstock_list(&L);
						savedb(&L);
						break;
					case 6:
						del_list(&L);
						savedb(&L);
						break;
					case 7:
						benefit_list(&L);
						break;
					case 8:
						edit_list(&L);
						savedb(&L);
						break;
					case 9:
						help();
						break;
				}
		}
	return 0;
}

void opendb(list *L)
{
	FILE* fp;
	int i;

	if( (fp = fopen("sales_list.ini", "r"))==NULL )
		{
			printf("* 库存不存在,请先新增数据。\n");
			return;
		}
	fscanf(fp,"length=%d\n",&L->length);
	for(i=0; i<L->length; i++)
		{
			for(i=0; i<L->length; i++)
				fscanf(fp,"%d %s %d %lf %lf %d %d %lf\n",&L->elem[i].number,&L->elem[i].name,&L->elem[i].many,&L->elem[i].in,&L->elem[i].out,&L->elem[i].inst,&L->elem[i].sold,&L->elem[i].profit);
		}
	fclose(fp);
}

void savedb(list *L)
{
	FILE* fp;
	int i;
	if ( (fp = fopen("sales_list.ini", "w"))==NULL )
		{
			printf("* 保存失败！\n");
#ifdef DEBUG
			system("pause");
#endif
			exit(-1);
		}
	fprintf(fp,"length=%d\n",L->length);
	for(i=0; i<L->length; i++)
		{
			for(i=0; i<L->length; i++)
				fprintf(fp,"%d %s %d %f %f %d %d %f\n",L->elem[i].number,L->elem[i].name,L->elem[i].many,L->elem[i].in,L->elem[i].out,L->elem[i].inst,L->elem[i].sold,L->elem[i].profit);
		}
	fclose(fp);
	printf("* 已保存！\n");
#ifdef DEBUG
	system("pause");
#endif
}

void show_list(list *L)
{
	int i;
	system("cls");
	system("title 数据库存");
	//system("mode con cols=80 lines=50");
	ui_title_display("数据库存概览",title_len);
	if(L->length == 0)
		printf("库存为空。[%d/%d]  \n\n",L->length,MAXSZ);
	else
		{
			printf("    编号\t简称   \t数量\t进价\t售价\t进量\t销量\t盈利\n");
			for(i=0; i<L->length; i++)
				printf("    %.3d \t%.6s\t%.3d\t%.2f\t%.2f\t%d   \t%d\t%.2f\n",L->elem[i].number,L->elem[i].name,L->elem[i].many,L->elem[i].in,L->elem[i].out,L->elem[i].inst,L->elem[i].sold,L->elem[i].profit);
			printf("\n   库存用量 [%d/%d]   若要查看数据详细信息，请使用查询功能。\n\n   ",L->length,MAXSZ);
		}
	system("pause");
	system("cls");
}

void add_list(list *L)		//新增数据
{
	int i,j,k=1,x,z;
	char ifadd;
	system("cls");
	system("title 新增数据");
	ui_title_display("新增数据",title_len);
	if(L->length >= MAXSZ)
		printf(" * 库存已满，无法添加数据。");
	else
		{
			printf("   [%d/%d] 本次共需要新增几个项目？输入0取消: ",L->length,MAXSZ);
			scanf("%d",&k);
			for(j=0; j<k; j++)
				{
					i=L->length;
				add_reinput:
					printf("\n   %d.输入新项目编号(唯一标识符):",j+1);
					scanf("%d",&x);
					for(z=0; z<=L->length; z++)
						if(x==L->elem[z].number)
							{
								printf(" * 编号重复或不规范，请重新输入");
								goto add_reinput;
							}
					L->elem[i].number=x;
					//scanf("%d",&L->elem[i].number);
					printf("   名称:");
					scanf("%s",&L->elem[i].name);
					printf("   个数:");
					scanf("%d",&L->elem[i].many);
					printf("   进价:");
					scanf("%lf",&L->elem[i].in);
					printf("   售价:");
					scanf("%lf",&L->elem[i].out);
					L->elem[i].inst=0;
					L->elem[i].sold=0;
					L->elem[i].profit=0;
					L->length++;
				printf("\n * 是否继续添加数据？输入0取消: ");
				ifadd = getch();
				if(ifadd == '0')
					{
						printf("\n * 已终止添加数据。");
						break;
					}
				}
		}
	system("pause");
	system("cls");
}

int locate_item(list *L, int val)		//定位数据
{
	int i;
	int loc=-1;
	for(i=0; i<L->length; i++)
		{
			if(val == L->elem[i].number)
				loc = i;
		}
#ifdef DEBUG
	printf("定位成功！");
#endif
	return loc;
}

void search_list(list *L)		//查询数据
{
	int i,j=-1;
	system("cls");
	system("title 查询数据");
	ui_title_display("查询数据",title_len);
	printf("   请输入要查询数据的编号: ");
	scanf("%d",&i);
	j = locate_item(L,i);
	if(j == -1)
		printf(" * 未找到任何结果。");
	else
		{
			printf("   数据详细信息:\n\n");
			printf("   编号:%d\n   数据:%s\n   数量:%d\n   进价:%.2f\n   售价:%.2f\n   进量:%d\n   销量:%d\n   盈利:%.2f\n\n"
			       ,L->elem[j].number,L->elem[j].name,L->elem[j].many,L->elem[j].in,L->elem[j].out,L->elem[i].inst,L->elem[j].sold,L->elem[j].profit);
		}
	system("pause");
	system("cls");
}

void instock_list(list *L)		//进货
{
	int i,j,z;
	system("title 进货");
	ui_title_display("进货",title_len);
	printf("   请输入要进货数据的编号，输入0取消:");
	scanf("%d",&i);
	j=locate_item(L,i);
	if(j == -1)
		{
			printf(" * 已取消: 无此编号，无法进货。");
			system("pause");
			system("cls");
			return;
		}
	printf("   编号:%d\n   数据:%s\n   数量:%d\n   进价:%.2f\n   售价:%.2f\n   进量:%d\n   销量:%d\n   盈利:%.2f\n\n"
	       ,L->elem[j].number,L->elem[j].name,L->elem[j].many,L->elem[j].in,L->elem[j].out,L->elem[i].inst,L->elem[j].sold,L->elem[j].profit);
	printf("   请输入进货量: ");
	scanf("%d",&z);
	L->elem[j].many=L->elem[j].many+z;
	L->elem[j].inst+=z;
	L->elem[j].profit-=(double)z*L->elem[j].in;
	printf(" * 添加了 %d 个数据, 本次支出 ￥%.2f   ",z,(double)z*L->elem[j].in);
	system("pause");
	system("cls");
}

void outstock_list(list *L)		//出货
{
	int i,j,z;
	system("title 出售");
	ui_title_display("出售",title_len);
	printf("   请输入要出售数据的编号，输入0取消:");
	scanf("%d",&i);
	j=locate_item(L,i);
	if(j == -1)
		{
			printf(" * 已取消: 无此编号，无法售出。");
			system("pause");
			system("cls");
			return;
		}
	printf("   编号:%d\n   数据:%s\n   数量:%d\n   进价:%.2f\n   售价:%.2f\n   进量:%d\n   销量:%d\n   盈利:%.2f\n\n"
	       ,L->elem[j].number,L->elem[j].name,L->elem[j].many,L->elem[j].in,L->elem[j].out,L->elem[i].inst,L->elem[j].sold,L->elem[j].profit);
	printf("   请输入售出量: ");
	scanf("%d",&z);
	if(z>L->elem[j].many)
		printf(" * 数据不足，仅存 %d，无法出售。    ",L->elem[j].many);
	else
		{
			L->elem[j].many=L->elem[j].many-z;
			L->elem[j].sold+=z;
			L->elem[j].profit+=L->elem[j].out*(double)z;

			printf("   售出了 %d 个数据, 本次收入 ￥%.2f    ",z,L->elem[j].out*(double)z);
		}
	system("pause");
	system("cls");
}

void del_list(list *L)			//删除数据
{
	int i,j,z;
	char confirm_del;
	system("title 删除数据");
	ui_title_display("删除数据",title_len);
	printf("   请输入要删除数据的编号，输入0取消: ");
	scanf("%d",&i);
	j=locate_item(L,i);
	if(j == -1)
		{
			printf(" * 已取消: 无此编号，无法删除。    ");
			system("pause");
			system("cls");
			return;
		}
	printf("   编号:%d 数据:%s 数量:%d 进价:%.2f 售价:%.2f 进量:%d 销量:%d 盈利:%.2f\n"
	       ,L->elem[j].number,L->elem[j].name,L->elem[j].many,L->elem[j].in,L->elem[j].out,L->elem[i].inst,L->elem[j].sold,L->elem[j].profit);
	printf("\n * 确认删除？此操作无法撤销。(y/n)");
	while(confirm_del = getch())
		{
			if(confirm_del=='y'||confirm_del=='Y')
				{
					for(z=j; z<=L->length; z++)
						L->elem[z]=L->elem[z+1];
					L->length--;
					printf("\n   已成功删除。    ");
					break;
				}
			else if(confirm_del=='n'||confirm_del=='N')
				{
					printf("\n   已取消。    ");
					break;
				}

			else
				{
					printf("\n   输入有误，请重新输入。    ");
					printf("\n * 确认删除？此操作无法撤销。(y/n)");
				}
		}

	system("pause");
	system("cls");
}

void benefit_list(list *L)		//利润统计
{
	int i,ainst=0,asold=0;
	double aprofit=0;
	system("title 利润统计");
	ui_title_display("利润统计",title_len);
	for(i=0; i<L->length; i++)
		{
			ainst+=L->elem[i].inst;
			asold+=L->elem[i].sold;
			aprofit+=(double)L->elem[i].profit;
		}
	printf("     共进货 %d 件，共售出 %d 件，总盈利 %.2f 元。\n\n     ",ainst,asold,aprofit);
	system("pause");
	system("cls");
}

int edit_list(list *L)
{
	int d0,d;
	char edit_title[30];
	int s=9;
	system("title 数据编辑器");
	system("cls");
	ui_title_display("数据编辑器",title_len);
	printf("   输入要编辑数据的编号，输入0取消:");
	scanf("%d",&d0);
	d=locate_item(L,d0);
	if(d == -1)
		{
			printf(" * 已取消: 无此编号，无法编辑。");
			system("pause");
			system("cls");
			return -1;
		}
	while(s)
		{
			system("cls");
			sprintf(edit_title,"数据编辑: %.3d 号",L->elem[d].number);
			ui_title_display(edit_title,title_len);
			printf(" 编号:%d 数据:%s 数量:%d 进价:%.2f 售价:%.2f 进量:%d 销量:%d 盈利:%.2f\n\n"
			       ,L->elem[d].number,L->elem[d].name,L->elem[d].many,L->elem[d].in,L->elem[d].out,L->elem[d].inst,L->elem[d].sold,L->elem[d].profit);
			printf("                               1.修改编号\n");
			printf("                               2.修改名称\n");
			printf("                               3.修改数量\n");
			printf("                               4.修改进价\n");
			printf("                               5.修改售价\n");
			printf("                               6.清除利润信息\n");
			printf("                               0.完成\n\n");
			printf("──────────────────────────────────────\n\n");
			printf("                              ?.选择一项:");
			while (!(scanf("%d",&s)))
				{
					fflush(stdin);
					printf("* 输入错误，请输入数字: ");
				}
			switch(s)
				{
					default:
						printf(" * 输入错误，重新输入");
						system("pause");
						break;
					case 1:
						printf("   请输入新的编号:");
						scanf("%d",&L->elem[d].number);
						break;
					case 2:
						printf("   请输入新的名称:");
						scanf("%s",&L->elem[d].name);
						break;
					case 3:
						printf("   请输入新的个数:");
						scanf("%d",&L->elem[d].many);
						break;
					case 4:
						printf("   请输入新的进价:");
						scanf("%lf",&L->elem[d].in);
						break;
					case 5:
						printf("   请输入新的售价:");
						scanf("%lf",&L->elem[d].out);
						break;
					case 6:
						L->elem[d].inst=0;
						L->elem[d].sold=0;
						L->elem[d].profit=0;
						printf("清除利润信息完成！");
						break;
					case 0:
						s=0;
						break;
				}
		}
	system("cls");
	return 0;
}

void ui_title_display(char title[],int length)
{
	char ch[]="─";
	int i,j,count=0;
	for(i=0; i<length; ++i)
		{
			if(i==0)
				printf("╔");
			else if(i==length-1)
				printf("╗");
			else
				printf("%s",ch);
		}
	printf("\n");
	for(j=0; j<(length-strlen(title))/2; j++)
		{
			if(j==0)
				printf("│");
			else
				printf("  ");
		}
	for(i=0; i<strlen(title)/2; ++i)
		printf(" ");
	for(i=0; i<strlen(title); ++i)
		printf("%c",title[i]);
	for(i=0; i<strlen(title)/2; ++i)
		printf(" ");
	for(j=0; j<(length-strlen(title))/2; j++)
		{
			if(j==(length-strlen(title))/2-1)
				printf("│");
			else
				printf("  ");
			++count;
		}
	printf("\n");
	for(i=0; i<length; ++i)
		{
			if(i==0)
				printf("╚");
			else if(i==length-1)
				printf("╝");
			else
				printf("%s",ch);
		}
	printf("\n");
}

void help()
{
	system("title 数据存销管理 关于");
	system("color F3");
	system("cls");
	ui_title_display("数据存销管理",title_len);
	printf("\n    数据存销管理 20160709\n");
	system("pause");
	system("cls");
}
