#include<stdio.h>
#include<windows.h>

void about();

int main(void)
{
	system("title �쾯2������");
	
	launcher();
}

void launcher()
{
	int input=100;
	
	while(input)
	{
		input=100;
		
		printlist();
		
		
		switch(input=getch())				//�ȴ����̰���һ���ַ�
		{
			case 49: system("start ra2.exe -speedcontrol"); break;
			case 43: system("start ra2.exe -win -speedcontrol"); break;
		
			case 50: system("start ra2md.exe -speedcontrol"); break;
			case 45: system("start ra2md.exe -win -speedcontrol"); break;
	
			case 51: system("taskkill /f /im ra2.exe"); system("taskkill /f /im game.exe"); system("cls"); break;
			case 52: system("taskkill /f /im ra2md.exe"); system("taskkill /f /im gamemd.exe"); system("cls"); break;

			case 57: about(); break;		//57 == 9
			case 99: matrix();break;
			case 48: exit(0); break;
			case 27: exit(0); break;		//27 == ESC
		}
	}
}

void printlist()
{
	system("mode con cols=29 lines=18");
	system("color 4E");
	system("cls");
	printf("����������������������������\n");
	printf("��      Red Alert 2       ��\n");
	printf("����������������������������\n");

	printf("     \n");
	printf("     1.���� �쾯2\n");
	printf("     +.���� �쾯2����ģʽ\n");
	printf("     2.���� ����ĸ���\n");
	printf("     -.���� ���ﴰ��ģʽ\n");
	printf("     \n");
	printf("     3.���� �쾯2\n");
	printf("     4.���� ����ĸ���\n");
	printf("     \n");
	printf("     9.����\n");
	printf("     0.�˳�\n");
	printf("     \n");
	printf("  ������������������������  \n");
	printf("     ������ ");
}

void about()
{
	
	system("cls");
	printf("*         ����        *\n");
	
	printf("\n");
	printf("* �Ѵ˳�����ں쾯2�ļ�����\n");
	printf("* �����Թ���Ա������д˳���\n");
	printf("* ����ģʽ��16λɫ\n");
	printf("* ��Ϸ�������п��Ե���\n");
	printf("* wcan 2016.4\n");
	printf("\n");
	colors();
	system("pause");
	system("cls");
}

void matrix()
{
	HWND hwnd=GetForegroundWindow();
	int x=GetSystemMetrics(SM_CXSCREEN)+300,y=GetSystemMetrics(SM_CYSCREEN)+300;
	char setting[30];
	sprintf(setting,"mode con:cols=%d lines=%d",x,y);//���ÿ���̨��������
	system(setting); 
	SetWindowPos(hwnd, HWND_TOPMOST,0,0,x+300,y+300,NULL);//�ö�
	MoveWindow(hwnd,-10,-40,x+300,y+300,1);//�ƶ�
	
	int i;
	system("title matrix");
    system("date /T");
    system("TIME /T");
    system("color 0A");
    printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
    printf("�U��         M A T R I X          ���U\n");
    printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
    system("color 0A");
    printf("Input:");
    //sleep(1); 
    colors();
    scanf("%ld",&i);
    there: printf("%ld\t",++i);
	goto there;
}

void colors()
{
	int i;
	for(i=0;i<5;i++)
    {
    system("color 09");
    system("color 0C");
    system("color 0A");
	}
}


