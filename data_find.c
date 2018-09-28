#include "data_manage_p.h"
#include <stdio.h>
int find_data(long long aim)//二分查找。
{
	int first = 0;
	int last = number - 1;
	
	while (first <= last) {
		int middle = (first + last)/2;//取中间数据的下标
		if (student[middle].id == aim) return middle;//若找到，返回下标。
		else if (student[middle].id < aim) first = middle + 1;//若下标值对应的数据比目标值小，则将下一次的开始下标改为现在的中值下标+1。
		else last = middle - 1;//同事，操作相反。
	}
	return -1;//若整个数据中都未找到，返回异常值-1 。

}

void display_find_data(void)
{
mark:;
	if (zero_data() == -1) goto end;//异常，数据中没有任何数据。
	long long temp;
	printf("请输入你需要查找的同学的学号：");
	scanf("%lld", &temp);
	int i = find_data(temp); //使用二分查找查询该学号是否存在,并且获得该数据的下标。
	if (i != -1) {
		printf("学号                   姓名       班级       高数分数   英语分数   总分\n");
		print(i);
	}
	else 
		printf("错误！查无此人！\n");//没有找到。
	printf("是否继续查询：\n继续查询：请输入 1 。\n结束查询，并返回上一级：请输入 2 。\n");
	int temp_choose;
	scanf("%d", &temp_choose);
	if (temp_choose == 1) goto mark;//根据用户选择重新定向。
end:;//异常处理标识。
}