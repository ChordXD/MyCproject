#include <stdio.h>
#include "ui.h"
#include "data_manage.h"
#include "data_manage_p.h"

void user_choose(void)
{
	int temp;
	do {
		printf("\n");//换个行。
		direction_ui();//交互界面图形文件。
		printf("您的选择：");
		scanf("%d", &temp);
		switch (temp)//面条选择。
		{
		case 1: put_all(); break;//显示所有学生信息。
		case 2: display_find_data();break;//查找信息并显示。
		case 3: add_data(); break;//增加一个学生的信息。
		case 4: del_data(); break;//删除一个学生的信息。
		case 5: break;//退出。
		default: printf("请输入正确的操作命令！");
			break;
		}
	} while (temp!=5);

}