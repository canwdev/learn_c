#include<stdio.h>
#include"title_display.h"

void iparr2num(const char ipArr[], int ip[] )
{
	int i,j=0;

	for (i=0; i<15; i++)
		{
			if(ipArr[i] == '\0')
				break;
			if(ipArr[i] == '.')
				{
					++j;
					continue;
				}
			ip[j]= ip[j]*10 + ipArr[i] - '0';
		}
//	printf("\nj=%d\n",j);
}

int ifcorrect(const int ip[])
{
	int i;
	/*for (i=0; i<4; i++)
		{
			printf("%d.",ip[i]);
		}
	printf("~ \n");*/
	for (i=0; i<4; i++)
		{
			if(ip[i]<0 || ip[i]>255)
				return 0;
		}
	return 1;
}

void ipclass(int ip[])
{
	printf("��ַ���ͣ�");
	if(ip[0]>=0 && ip[0]<=127)
		{
			printf("A���ַ");
			if(ip[0]==10)
				printf("��ר�õ�ַ");
			if(ip[0]==127)
				printf("�����͵�ַ");
			if(ip[1]==0 && ip[2]==0 && ip[3]==0 || ip[1]==1 && ip[2]==1 && ip[3]==1)
				printf("��������ַ");
			//if(ip[1]==255 && ip[2]==255 && ip[3]==255)
			//	printf("���㲥��ַ");
			printf("\n\n"); 
			title_display("A ���ַ", 30);
			printf("��Χ��1.0.0.0~127.255.255.255\nĬ���������룺255.0.0.0");
			printf("\nA���ַ�������(net ID)�ĵ�һλΪ0������7λ�ɷ��䣬����Ϊ��С��ͬ��128(2^7)�顣\n��һ������һ���ַ����������;��netID=10����ר�õ�ַ��\n���ܹ��õ���A���ַ����ֻ��125����\n������ȫ0��ȫ1��������ַ������������Ŀ�ġ�\n�ʿ��Է��� (2^24)-2=16777214 ��������");
		}
	else if(ip[0]>=128 && ip[0]<=191)
		{
			printf("B���ַ");
			if(ip[2]==0 && ip[3]==0 || ip[2]==1 && ip[3]==1)
				printf("��������ַ");
			//if(ip[2]==255 && ip[3]==255)
			//	printf("���㲥��ַ");
			printf("\n\n"); 
			title_display("B ���ַ", 30);
			printf("��Χ��128.0.0.0~191.255.255.255\nĬ���������룺255.255.0.0");
			printf("B ���ַ������ų���Ϊ14λ�����������Ϊ 2^14 = 16384��\n������(host ID)����Ϊ16λ������������Ϊ 2^16=65536��\n��������Ϊȫ0��ȫ1��������ַ������������Ŀ�ģ�����������������Ϊ 65534 ����");
		}
	else if(ip[0]>=192 && ip[0]<=223)
		{
			printf("C���ַ");
			if(ip[3]==0 || ip[3]==1)
				printf("��������ַ");
			//if(ip[3]==255)
			//	printf("���㲥��ַ");
			printf("\n\n"); 
			title_display("C ���ַ", 30);
			printf("��Χ��192.0.0.0~223.255.255.255\nĬ���������룺255.255.255.0");
			printf("\nC��IP��ַ����ų���Ϊ21λ����������� 2^21 = 2097152 ����ͬ��C�����硣\n������(host ID)����Ϊ8λ������������Ϊ 2^8=256��\n��������Ϊȫ0��ȫ1��������ַ������������Ŀ�ģ�����������������Ϊ 254 ����");
		}

	else if(ip[0]>=224 && ip[0]<=239)
		printf("D���ַ (224.0.0.0~239.255.255.255)");
	else if(ip[0]>=240 && ip[0]<=247)
		printf("E���ַ (240.0.0.0~247.255.255.255)");
	else if(ip[0]==255 && ip[1]==255 && ip[2]==255 && ip[3]==255)
		printf("���޹㲥��ַ");
	else 
		printf("������ַ");
	printf("\n\n��ABC��IP��ַ�У������Ŷ�����ȫ��1�ĵ�ַ��ַΪ��ֱ�ӣ��㲥��ַ��"); 
	printf("\n");
}

ipbinary(int ip[])
{
	int k,i,j,flag,x,rem,a[30];
	printf("�����ƣ�");
	for(k=0; k<4; k++)
		{
			x=ip[k];
			a[30]=0,rem=0;i=0;
			flag=0;
			//if(x<=0)
			//	printf("00000000");
			//else
			{
				do
				{
					rem=x%2;
					x=x/2;
					a[i]=rem;
					i++;
				}while(x!=0);
			
			//printf("[%d]",i);
			for(j=8-i;j>0;j--)
			printf("0");

			for(i;i>0;)
			{
				printf("%d",a[--i]);
				if(a[i]==1)
				flag++;
			}
			
			}
			//printf("[%d]",flag);
			printf(".");
			
			//if(flag==8)
			//printf("\t �㲥��ַ??");
		}
	printf("\b ");
}

int main()
{
	
	int i;
	char ipArr[15];
	int ip[4]= {0,0,0,0};

	
	
	restart:
	ip[0] = ip[1] = ip[2] = ip[3] = 0;
	title_display("IP��ַ�����⹤��", 30);
	
	printf("������ IPv4 ��ַ������ 192.168.1.1����");
	gets(ipArr);

	iparr2num(ipArr,ip);

	if(ifcorrect(ip))
		{
			printf("\n��ַ��");
			for (i=0; i<4; i++)
				{
					printf("%d.",ip[i]);
				}
			printf("\b \n\n");
			ipbinary(ip);
			printf("\n\n");
			ipclass(ip);
		}
	else
		printf("��������, ������� 0.0.0.0 �� 255.255.255.255 �ĵ�ַ");
	printf("\n");
	
	system("pause");
	system("cls");
	goto restart;
	
	return 0;
}
