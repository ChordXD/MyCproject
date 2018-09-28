#include <stdio.h>
#include "data_manage_p.h"

Student student[DATA_MAX];//在内存中创建一个DATA_MAX大小的临时储存数组，存放学生数据。
char sign[] = "data.txt";//数据文件的文件名
int number;//学生数量
int user_number;

void initialize_data(void)
{
	user_number = 0;
	number = 0;//初始化学生数量。	
}