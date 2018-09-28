#pragma once
#ifndef DATA_MANAGE_P_H_INCLUDED
#define DATA_MANAGE_P_H_INCLUDED

/*此头文件为本系统的数据结构：结构体数组。
优点：易于管理，（二分）查找较快与方便。
缺点：较为耗费内存资源。
*/

#define NAME_MAX_SIZE (100)//名称最大值的宏定义
#define DATA_MAX (100000)//内存中的缓存数据，也是该系统最大可以存储与读取的学生信息数量。

/*本系统没有检查数组越界的功能*/

//学生信息结构体。
typedef struct {
	long long id;
	char name[NAME_MAX_SIZE];
	char CLASS[NAME_MAX_SIZE];
	int math;
	int english;
	int sum;
}Student;

//此三项可在initialize.c中找到，为系统必不可缺的数据信息。
extern char sign[];//数据保存的文件名。
extern Student student[];//内存中初始化的结构体数组。
extern int number;//实时的学生数量。

#endif //!DATA_MANAGE_P_H_INCLUDED