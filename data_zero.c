#include <stdio.h>
#include "data_manage_p.h"

int choose_temp;
int zero_data(void)
{
	if (number == 0) {
		printf("数据库中没有任何学生信息！请先添加，再进行操作！\n\a");
		printf("是否立刻添加？\n是：请输入 1 。否，并返回上一级菜单：请输入 2 。\n");
		printf("您的选择：");
		scanf("%d", &choose_temp);
		if (choose_temp == 1) add_data();//若用户想要添加数据，转到数据添加函数。
		return -1;//返回异常值-1。
	}
	return 1;//若数据库中存在数据，返回1。
}