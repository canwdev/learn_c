//CAN ORIGINAL CODE PROJECT
//�������ɲ��������
//����˵�����������ݣ�������
//���� title_display("CH����", 30);
//���������ֽ��������ż��

void title_display(char title[],int length)
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
