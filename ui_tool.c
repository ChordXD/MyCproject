#include <stdio.h>

void get_photo(char *file_name)
{
	FILE *fp;
	if ((fp = fopen(file_name, "r")) == NULL) {
		printf("error\n");//��ʧ�ܣ���ʾ����
	}
	else {
		char ch;
		while ((ch = fgetc(fp)) != EOF)//���϶�ȡ��һ���ַ�
		{
			putchar(ch);//���ַ���ʽ��ӡ��ȡ�����ļ�
		}
		fclose(fp);//�ļ��ر�
	}
}