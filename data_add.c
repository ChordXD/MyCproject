#include <stdio.h>
#include "data_manage_p.h"

static void shift_array(int index)
{
	int src; //被赋值元素的索引。

	for (src = number - 1; src >= index; src--) {
		student[src + 1] = student[src];
	}
	number++;
}

int choose_temp;

void add_data(void)
{
mark:;
	Student temp;//临时储存。
	/*新添加学生数据的读取*/
	printf("请输入一组学生的数据：\n");
	printf("学号："); scanf("%lld", &temp.id);
	printf("姓名："); scanf("%s", temp.name);
	printf("班级："); scanf("%s", temp.CLASS);
	printf("数学成绩："); scanf("%d", &temp.math);
	printf("英语成绩："); scanf("%d", &temp.english);
	temp.sum = temp.math + temp.english;
	int i;
	int error = 0;

	for (i = 0; i < number; i++) {//学号查重（顺序查找）。
		if (student[i].id >= temp.id) {
			if (student[i].id == temp.id) error = 1; //学号相同！错误！
			break;//此时i中恰好存储了该学生按照学号从小到大排序应插入的位置。
		}
	}
	if (error == 1) {
		printf("\a学号不可相同。\n");
		printf("是否重新添加？\n重新添加：请输入 1 。结束添加：请输入 2 。\n您的选择：");

		scanf("%d", &choose_temp);

		if (choose_temp == 1) goto mark;
	}
	else {
		shift_array(i);//数据移动，将该新增学生的数据应插入位置之后的学生的数据全部顺序移动。
		student[i] = temp;//数据插入。

		printf("添加成功，当前已录入学生数量为%d。\n", number);
		printf("是否继续添加？\n继续添加：请输入 1 。结束添加：请输入 2 。");
		
		scanf("%d", &choose_temp);

		if (choose_temp == 1) goto mark;
		
	}

}