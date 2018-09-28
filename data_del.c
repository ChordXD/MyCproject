#include <stdio.h>
#include "data_manage_p.h"
#include "data_manage.h"

static void shift_array(int index)
{
	int src; //被赋值元素的索引。

	for (src = index ; src <= number - 1 ; src++) {
		student[src] = student[src+1];//前移
	}
	number--;//总人数减少。
}

int choose_temp;

void del_data(void)
{
mark:;
	if (zero_data() == -1) goto end;//数据库中没有数据。
	long long aim;
	printf("请输入要删除学生的学号：");
	scanf("%lld", &aim);
	int i = find_data(aim); //使用二分查找查询该学号是否存在。
	if (i != -1) {
		shift_array(i);//数据移动，将该数据后面的元素前移，覆盖该元素。
		printf("删除成功！当前已录入学生数量为%d。\n",number);
	}
	else {
		printf("错误！查无此人！\n");
		printf("是否重新删除？\n重新删除：请输入 1 。结束删除：请输入 2 。");

		scanf("%d", &choose_temp);

		if (choose_temp == 1) goto mark;
	}
	printf("是否继续删除？\n继续删除：请输入 1 。结束删除：请输入 2 。\n");
	printf("您的选择：");
	scanf("%d", &choose_temp);

	if (choose_temp == 1) goto mark;
end:;

}