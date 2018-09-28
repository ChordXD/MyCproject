#include <stdio.h>
#include <Windows.h>
#include "data_manage_p.h"



static FILE *open(void)
{
	static error(void);

mark:;
	FILE *fp;
	if ((fp = fopen(sign, "r")) == NULL) {
		printf("欢迎使用本程序！检测到第一次使用该程序，正在为您构建程序所需文件，请稍后.....\n");//无法打开文件。
		if((fp = fopen(sign, "w"))!=NULL){//以只写模式打开文件，此时文件不存在，则会自动创建一个数据文件。
			fclose(fp);
			Sleep(500);//增加使用体验。
			puts("构建成功！");
			goto mark;//重新以只读模式打开。
		}
		else
			error();//出错。
	}
	else {
		printf("欢迎！正在初始化，请稍后.....\n");
		Sleep(1000);
		return fp;
	}

}

static error(void)
{
	puts("失败！\a是否重新构建？");
	printf("1，重新尝试构建。\n2、退出。\n");
	int choose;
	scanf("%d", &choose);
	if (choose == 1)
		open();
	else
		exit(1);//直接退出。
}

void get_data(void)
{
	FILE *fp = open();//打开文件
	while (fscanf(fp, "%lld %s %s %d %d %d\n", &student[number].id, student[number].name,
		student[number].CLASS, &student[number].math,
		&student[number].english, &student[number].sum) != EOF) {//格式化读取文件流的学生信息。
		number++;//每成功读取一个学生信息，学生数量增加一个。
	}
	printf("初始化成功！共读取%d个学生数据！\n", number);
	fclose(fp);

}