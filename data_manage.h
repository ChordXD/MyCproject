#pragma once
#ifndef DATA_MANAGE_H_INCLUDED
#define DATA_MANAGE_H_INCLUDED

/*此头文件包含数据库管理的全部所需函数。*/

void initialize_data(void);//系统初始化。

void add_data(void);//增加数据。

int find_data(long long aim);//根据学号查找数据。

void del_data(void);//删除一条数据

void display_find_data(void);//显示查找数据。

void print(int aim);//打印一条数据。

void put_all(void);//打印所有数据。

int zero_data(void);//数据库没有数据时的异常处理。

void user_choose(void);//用户交互，

void save(void);//保存数据。

#endif // !DATA_MANAGE_H_INCLUDED
