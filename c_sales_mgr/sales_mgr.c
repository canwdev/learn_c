#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define DEBUG
#define MAX 50
#define MAXSZ 1000
const int title_len = 38;

typedef struct
{
	int number;			//��ţ�Ψһ��ʶ����
	char name[MAX];		//����
	int many;			//����
	double in;			//����
	double out;			//�ۼ�
	int inst;			//������
	int sold;			//������
	double profit;		//����
} elemtype;

typedef struct
{
	elemtype elem[MAXSZ];
	int length;
} list;

//����
void opendb(list *L);							//�����ļ�
void savedb(list *L);							//�����ļ�
void show_list(list *L);						//��ʾ���
void add_list(list *L);							//������Ʒ
int locate_item(list *L, int val);				//��λ��Ʒ���ص�ַ
void search_list(list *L);						//��ѯ����ʾ���
void instock_list(list *L);						//����
void outstock_list(list *L);					//����
void del_list(list *L);							//ɾ����Ʒ
void benefit_list(list *L);						//ӯ��ͳ��
int edit_list(list *L);							//�༭��Ʒ��Ϣ
void ui_title_display(char title[],int length);	//�������߿�
void sort_by_num(list *L);						//���������
void advanced_search(list *L);					//�߼����� 
void help();

int main(void)
{
	list L= {{0},0};
	int i,s=1;
	while(s)
		{
			system("title ���ݴ�������"); 					//���ô��ڱ���
			//system("mode con cols=80 lines=20"); 			//���ô��ڴ�С
			system("color 3F"); 							//���ô��ڱ�����������ɫ
			opendb(&L);
			//ui_title_display("���ݴ�������",title_len);
			printf("�X���������������������������������������������������������������������������[\n");
			printf("����                            ���ݴ�������                              ���� \n");
			printf("�^���������������������������������������������������������������������������a\n\n");
			printf("                                1.��ʾ���\n");
			printf("                                2.��������\n");
			printf("                                3.��ѯ����\n");
			printf("                                4.����\n");
			printf("                                5.����\n");
			printf("                                6.ɾ������\n");
			printf("                                7.����ͳ��\n");
			printf("                                8.���ݱ༭\n\n");
			printf("                                0.���沢�˳�\n\n");
			printf("����������������������������������������������������������������������������\n\n");
			printf("                                ?.ѡ��һ���: ");
			while (!(scanf("%d",&i)))
				{
					fflush(stdin);		//������뻺�棬������cin.clear()
					//while (getchar()!='\n')
					//	continue;
					printf("* �����������������: ");

				}
			//scanf("%d",&i);
			system("cls");
			switch(i)
				{
					default:
						printf(" * ���������������\n");
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
			printf("* ��治����,�����������ݡ�\n");
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
			printf("* ����ʧ�ܣ�\n");
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
	printf("* �ѱ��棡\n");
#ifdef DEBUG
	system("pause");
#endif
}

void show_list(list *L)
{
	int i;
	system("cls");
	system("title ���ݿ��");
	//system("mode con cols=80 lines=50");
	ui_title_display("���ݿ�����",title_len);
	if(L->length == 0)
		printf("���Ϊ�ա�[%d/%d]  \n\n",L->length,MAXSZ);
	else
		{
			printf("    ���\t���   \t����\t����\t�ۼ�\t����\t����\tӯ��\n");
			for(i=0; i<L->length; i++)
				printf("    %.3d \t%.6s\t%.3d\t%.2f\t%.2f\t%d   \t%d\t%.2f\n",L->elem[i].number,L->elem[i].name,L->elem[i].many,L->elem[i].in,L->elem[i].out,L->elem[i].inst,L->elem[i].sold,L->elem[i].profit);
			printf("\n   ������� [%d/%d]   ��Ҫ�鿴������ϸ��Ϣ����ʹ�ò�ѯ���ܡ�\n\n   ",L->length,MAXSZ);
		}
	system("pause");
	system("cls");
}

void add_list(list *L)		//��������
{
	int i,j,k=1,x,z;
	char ifadd;
	system("cls");
	system("title ��������");
	ui_title_display("��������",title_len);
	if(L->length >= MAXSZ)
		printf(" * ����������޷�������ݡ�");
	else
		{
			printf("   [%d/%d] ���ι���Ҫ����������Ŀ������0ȡ��: ",L->length,MAXSZ);
			scanf("%d",&k);
			for(j=0; j<k; j++)
				{
					i=L->length;
				add_reinput:
					printf("\n   %d.��������Ŀ���(Ψһ��ʶ��):",j+1);
					scanf("%d",&x);
					for(z=0; z<=L->length; z++)
						if(x==L->elem[z].number)
							{
								printf(" * ����ظ��򲻹淶������������");
								goto add_reinput;
							}
					L->elem[i].number=x;
					//scanf("%d",&L->elem[i].number);
					printf("   ����:");
					scanf("%s",&L->elem[i].name);
					printf("   ����:");
					scanf("%d",&L->elem[i].many);
					printf("   ����:");
					scanf("%lf",&L->elem[i].in);
					printf("   �ۼ�:");
					scanf("%lf",&L->elem[i].out);
					L->elem[i].inst=0;
					L->elem[i].sold=0;
					L->elem[i].profit=0;
					L->length++;
				printf("\n * �Ƿ����������ݣ�����0ȡ��: ");
				ifadd = getch();
				if(ifadd == '0')
					{
						printf("\n * ����ֹ������ݡ�");
						break;
					}
				}
		}
	system("pause");
	system("cls");
}

int locate_item(list *L, int val)		//��λ����
{
	int i;
	int loc=-1;
	for(i=0; i<L->length; i++)
		{
			if(val == L->elem[i].number)
				loc = i;
		}
#ifdef DEBUG
	printf("��λ�ɹ���");
#endif
	return loc;
}

void search_list(list *L)		//��ѯ����
{
	int i,j=-1;
	system("cls");
	system("title ��ѯ����");
	ui_title_display("��ѯ����",title_len);
	printf("   ������Ҫ��ѯ���ݵı��: ");
	scanf("%d",&i);
	j = locate_item(L,i);
	if(j == -1)
		printf(" * δ�ҵ��κν����");
	else
		{
			printf("   ������ϸ��Ϣ:\n\n");
			printf("   ���:%d\n   ����:%s\n   ����:%d\n   ����:%.2f\n   �ۼ�:%.2f\n   ����:%d\n   ����:%d\n   ӯ��:%.2f\n\n"
			       ,L->elem[j].number,L->elem[j].name,L->elem[j].many,L->elem[j].in,L->elem[j].out,L->elem[i].inst,L->elem[j].sold,L->elem[j].profit);
		}
	system("pause");
	system("cls");
}

void instock_list(list *L)		//����
{
	int i,j,z;
	system("title ����");
	ui_title_display("����",title_len);
	printf("   ������Ҫ�������ݵı�ţ�����0ȡ��:");
	scanf("%d",&i);
	j=locate_item(L,i);
	if(j == -1)
		{
			printf(" * ��ȡ��: �޴˱�ţ��޷�������");
			system("pause");
			system("cls");
			return;
		}
	printf("   ���:%d\n   ����:%s\n   ����:%d\n   ����:%.2f\n   �ۼ�:%.2f\n   ����:%d\n   ����:%d\n   ӯ��:%.2f\n\n"
	       ,L->elem[j].number,L->elem[j].name,L->elem[j].many,L->elem[j].in,L->elem[j].out,L->elem[i].inst,L->elem[j].sold,L->elem[j].profit);
	printf("   �����������: ");
	scanf("%d",&z);
	L->elem[j].many=L->elem[j].many+z;
	L->elem[j].inst+=z;
	L->elem[j].profit-=(double)z*L->elem[j].in;
	printf(" * ����� %d ������, ����֧�� ��%.2f   ",z,(double)z*L->elem[j].in);
	system("pause");
	system("cls");
}

void outstock_list(list *L)		//����
{
	int i,j,z;
	system("title ����");
	ui_title_display("����",title_len);
	printf("   ������Ҫ�������ݵı�ţ�����0ȡ��:");
	scanf("%d",&i);
	j=locate_item(L,i);
	if(j == -1)
		{
			printf(" * ��ȡ��: �޴˱�ţ��޷��۳���");
			system("pause");
			system("cls");
			return;
		}
	printf("   ���:%d\n   ����:%s\n   ����:%d\n   ����:%.2f\n   �ۼ�:%.2f\n   ����:%d\n   ����:%d\n   ӯ��:%.2f\n\n"
	       ,L->elem[j].number,L->elem[j].name,L->elem[j].many,L->elem[j].in,L->elem[j].out,L->elem[i].inst,L->elem[j].sold,L->elem[j].profit);
	printf("   �������۳���: ");
	scanf("%d",&z);
	if(z>L->elem[j].many)
		printf(" * ���ݲ��㣬���� %d���޷����ۡ�    ",L->elem[j].many);
	else
		{
			L->elem[j].many=L->elem[j].many-z;
			L->elem[j].sold+=z;
			L->elem[j].profit+=L->elem[j].out*(double)z;

			printf("   �۳��� %d ������, �������� ��%.2f    ",z,L->elem[j].out*(double)z);
		}
	system("pause");
	system("cls");
}

void del_list(list *L)			//ɾ������
{
	int i,j,z;
	char confirm_del;
	system("title ɾ������");
	ui_title_display("ɾ������",title_len);
	printf("   ������Ҫɾ�����ݵı�ţ�����0ȡ��: ");
	scanf("%d",&i);
	j=locate_item(L,i);
	if(j == -1)
		{
			printf(" * ��ȡ��: �޴˱�ţ��޷�ɾ����    ");
			system("pause");
			system("cls");
			return;
		}
	printf("   ���:%d ����:%s ����:%d ����:%.2f �ۼ�:%.2f ����:%d ����:%d ӯ��:%.2f\n"
	       ,L->elem[j].number,L->elem[j].name,L->elem[j].many,L->elem[j].in,L->elem[j].out,L->elem[i].inst,L->elem[j].sold,L->elem[j].profit);
	printf("\n * ȷ��ɾ�����˲����޷�������(y/n)");
	while(confirm_del = getch())
		{
			if(confirm_del=='y'||confirm_del=='Y')
				{
					for(z=j; z<=L->length; z++)
						L->elem[z]=L->elem[z+1];
					L->length--;
					printf("\n   �ѳɹ�ɾ����    ");
					break;
				}
			else if(confirm_del=='n'||confirm_del=='N')
				{
					printf("\n   ��ȡ����    ");
					break;
				}

			else
				{
					printf("\n   �����������������롣    ");
					printf("\n * ȷ��ɾ�����˲����޷�������(y/n)");
				}
		}

	system("pause");
	system("cls");
}

void benefit_list(list *L)		//����ͳ��
{
	int i,ainst=0,asold=0;
	double aprofit=0;
	system("title ����ͳ��");
	ui_title_display("����ͳ��",title_len);
	for(i=0; i<L->length; i++)
		{
			ainst+=L->elem[i].inst;
			asold+=L->elem[i].sold;
			aprofit+=(double)L->elem[i].profit;
		}
	printf("     ������ %d �������۳� %d ������ӯ�� %.2f Ԫ��\n\n     ",ainst,asold,aprofit);
	system("pause");
	system("cls");
}

int edit_list(list *L)
{
	int d0,d;
	char edit_title[30];
	int s=9;
	system("title ���ݱ༭��");
	system("cls");
	ui_title_display("���ݱ༭��",title_len);
	printf("   ����Ҫ�༭���ݵı�ţ�����0ȡ��:");
	scanf("%d",&d0);
	d=locate_item(L,d0);
	if(d == -1)
		{
			printf(" * ��ȡ��: �޴˱�ţ��޷��༭��");
			system("pause");
			system("cls");
			return -1;
		}
	while(s)
		{
			system("cls");
			sprintf(edit_title,"���ݱ༭: %.3d ��",L->elem[d].number);
			ui_title_display(edit_title,title_len);
			printf(" ���:%d ����:%s ����:%d ����:%.2f �ۼ�:%.2f ����:%d ����:%d ӯ��:%.2f\n\n"
			       ,L->elem[d].number,L->elem[d].name,L->elem[d].many,L->elem[d].in,L->elem[d].out,L->elem[d].inst,L->elem[d].sold,L->elem[d].profit);
			printf("                               1.�޸ı��\n");
			printf("                               2.�޸�����\n");
			printf("                               3.�޸�����\n");
			printf("                               4.�޸Ľ���\n");
			printf("                               5.�޸��ۼ�\n");
			printf("                               6.���������Ϣ\n");
			printf("                               0.���\n\n");
			printf("����������������������������������������������������������������������������\n\n");
			printf("                              ?.ѡ��һ��:");
			while (!(scanf("%d",&s)))
				{
					fflush(stdin);
					printf("* �����������������: ");
				}
			switch(s)
				{
					default:
						printf(" * ���������������");
						system("pause");
						break;
					case 1:
						printf("   �������µı��:");
						scanf("%d",&L->elem[d].number);
						break;
					case 2:
						printf("   �������µ�����:");
						scanf("%s",&L->elem[d].name);
						break;
					case 3:
						printf("   �������µĸ���:");
						scanf("%d",&L->elem[d].many);
						break;
					case 4:
						printf("   �������µĽ���:");
						scanf("%lf",&L->elem[d].in);
						break;
					case 5:
						printf("   �������µ��ۼ�:");
						scanf("%lf",&L->elem[d].out);
						break;
					case 6:
						L->elem[d].inst=0;
						L->elem[d].sold=0;
						L->elem[d].profit=0;
						printf("���������Ϣ��ɣ�");
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
	char ch[]="��";
	int i,j,count=0;
	for(i=0; i<length; ++i)
		{
			if(i==0)
				printf("�X");
			else if(i==length-1)
				printf("�[");
			else
				printf("%s",ch);
		}
	printf("\n");
	for(j=0; j<(length-strlen(title))/2; j++)
		{
			if(j==0)
				printf("��");
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
				printf("��");
			else
				printf("  ");
			++count;
		}
	printf("\n");
	for(i=0; i<length; ++i)
		{
			if(i==0)
				printf("�^");
			else if(i==length-1)
				printf("�a");
			else
				printf("%s",ch);
		}
	printf("\n");
}

void help()
{
	system("title ���ݴ������� ����");
	system("color F3");
	system("cls");
	ui_title_display("���ݴ�������",title_len);
	printf("\n    ���ݴ������� 20160709\n");
	system("pause");
	system("cls");
}
