// wcan orininal code project 20160614
#include<stdio.h>
#include<string.h>
#define MAXS 1000

void enter(char *str);

int main()
{
	char str[MAXS];
	int max;

	printf("输入要重复的字符串，<br>表示回车:\n");
	gets(str);
	enter(str);
	printf("需要循环几次：");
	scanf("%d",&max);

	for(int i=0; i<max; i++)
		printf("%s",str);
	
	getchar();
	getchar();
	return 0;
}

void enter(char *str)
{
	int j;
	for(int i=0; i<MAXS; i++)
		if(str[i] == '<' && str[i+1] == 'b' && str[i+2] == 'r' && str[i+3] == '>')
			{
				str[i]='\n';
				j=i+1;
				for(j; j<=MAXS; j++)
					{
						str[j]=str[j+3];
					}
			}
	/*
	else if(str[i] == '<' && str[i+1] == 's' && str[i+2] == 'p' && str[i+3] == '>')
		{
			str[i]=' ';
			j=i+1;
			for(j; j<=MAXS; j++)
				{
					str[j]=str[j+3];
				}
		}
	*/

}
