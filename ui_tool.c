#include <stdio.h>

void get_photo(char *file_name)
{
	FILE *fp;
	if ((fp = fopen(file_name, "r")) == NULL) {
		printf("error\n");//打开失败，提示错误
	}
	else {
		char ch;
		while ((ch = fgetc(fp)) != EOF)//不断读取下一个字符
		{
			putchar(ch);//以字符形式打印读取到的文件
		}
		fclose(fp);//文件关闭
	}
}