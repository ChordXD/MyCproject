#include <stdio.h>
#include "data_manage.h"
#include "data_manage_p.h"

void print(int aim)
{
	printf("%-20lld   %-10s %-10s %-10d %-10d %-10d\n", student[aim].id, student[aim].name,
		student[aim].CLASS, student[aim].math,
		student[aim].english, student[aim].sum);//格式化输出所有学生数据。
}

void put_all(void)
{
	if (zero_data() == -1) goto end;//若没有数据，执行此段。
	printf("学号                   姓名       班级       高数分数   英语分数   总分\n");
	for (int i = 0; i < number; i++)
		print(i);//循环打印所有数据。
	printf("快捷操作：\n1、删除数据。\n2、添加数据。\n3、查找数据\n4、什么也不做，返回上一级菜单。\n");
	int choose_put;
	printf("您的选择：");
	scanf("%d", &choose_put);
	switch (choose_put)
	{
	case 1:del_data(); break;
	case 2:add_data(); break;
	case 3:display_find_data(); break;
	case 4:break;
	default:printf("请输入正确的操作数字！\a");
		break;
	};
end:;
}
