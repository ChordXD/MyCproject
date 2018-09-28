#include "data_manage_p.h"
#include <stdio.h>

void save(void)
{
	FILE *fp;
	if ((fp = fopen(sign, "w")) == NULL) {//以只写模式打开文件，同时删除文件中上一次的数据。
		printf("\a保存失败！");//打开失败。
	}
	else {
		for (int i = 0; i < number; i++) {
			fprintf(fp, "%lld %s %s %d %d %d\n", student[i].id, student[i].name,
				student[i].CLASS, student[i].math,
				student[i].english, student[i].sum);//将内存中的学生数据格式化打印到文件当中。
		}
		printf("保存成功，共保存了%d个数据。\n", number);
		fclose(fp);
	}

}