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
	printf("地址类型：");
	if(ip[0]>=0 && ip[0]<=127)
		{
			printf("A类地址");
			if(ip[0]==10)
				printf("，专用地址");
			if(ip[0]==127)
				printf("，回送地址");
			if(ip[1]==0 && ip[2]==0 && ip[3]==0 || ip[1]==1 && ip[2]==1 && ip[3]==1)
				printf("，保留地址");
			//if(ip[1]==255 && ip[2]==255 && ip[3]==255)
			//	printf("，广播地址");
			printf("\n\n"); 
			title_display("A 类地址", 30);
			printf("范围：1.0.0.0~127.255.255.255\n默认子网掩码：255.0.0.0");
			printf("\nA类地址的网络号(net ID)的第一位为0，其余7位可分配，共分为大小相同的128(2^7)块。\n第一块和最后一块地址留做特殊用途，netID=10用于专用地址。\n故能够得到的A类地址机构只有125个。\n主机号全0和全1的两个地址保留用于特殊目的。\n故可以分配 (2^24)-2=16777214 个主机。");
		}
	else if(ip[0]>=128 && ip[0]<=191)
		{
			printf("B类地址");
			if(ip[2]==0 && ip[3]==0 || ip[2]==1 && ip[3]==1)
				printf("，保留地址");
			//if(ip[2]==255 && ip[3]==255)
			//	printf("，广播地址");
			printf("\n\n"); 
			title_display("B 类地址", 30);
			printf("范围：128.0.0.0~191.255.255.255\n默认子网掩码：255.255.0.0");
			printf("B 类地址的网络号长度为14位，网络号总数为 2^14 = 16384。\n主机号(host ID)长度为16位，主机号总数为 2^16=65536。\n但主机号为全0和全1的两个地址保留用于特殊目的，故允许分配的主机号为 65534 个。");
		}
	else if(ip[0]>=192 && ip[0]<=223)
		{
			printf("C类地址");
			if(ip[3]==0 || ip[3]==1)
				printf("，保留地址");
			//if(ip[3]==255)
			//	printf("，广播地址");
			printf("\n\n"); 
			title_display("C 类地址", 30);
			printf("范围：192.0.0.0~223.255.255.255\n默认子网掩码：255.255.255.0");
			printf("\nC类IP地址网络号长度为21位，因此允许有 2^21 = 2097152 个不同的C类网络。\n主机号(host ID)长度为8位，主机号总数为 2^8=256。\n但主机号为全0和全1的两个地址保留用于特殊目的，故允许分配的主机号为 254 个。");
		}

	else if(ip[0]>=224 && ip[0]<=239)
		printf("D类地址 (224.0.0.0~239.255.255.255)");
	else if(ip[0]>=240 && ip[0]<=247)
		printf("E类地址 (240.0.0.0~247.255.255.255)");
	else if(ip[0]==255 && ip[1]==255 && ip[2]==255 && ip[3]==255)
		printf("受限广播地址");
	else 
		printf("其他地址");
	printf("\n\n在ABC类IP地址中，主机号二进制全是1的地址地址为（直接）广播地址。"); 
	printf("\n");
}

ipbinary(int ip[])
{
	int k,i,j,flag,x,rem,a[30];
	printf("二进制：");
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
			//printf("\t 广播地址??");
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
	title_display("IP地址分类检测工具", 30);
	
	printf("请输入 IPv4 地址（例如 192.168.1.1）：");
	gets(ipArr);

	iparr2num(ipArr,ip);

	if(ifcorrect(ip))
		{
			printf("\n地址：");
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
		printf("输入有误, 请输入从 0.0.0.0 到 255.255.255.255 的地址");
	printf("\n");
	
	system("pause");
	system("cls");
	goto restart;
	
	return 0;
}
