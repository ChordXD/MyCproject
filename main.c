#include "data_manage.h"
#include "data_get.h"
#include "ui.h"

int main(void)
{

	head_ui();//欢迎画面。
	
	initialize_data();//初始化程序，在内存中创建缓冲区。

	get_data();//获取文件中已存的学生数据，写入内存中以准备好的缓冲区。

	user_choose();//主控，与用户之间进行交互。

	save();//保存内存中学生数据，并将其存入文件。

	getchar();//防止文件闪现。
	getchar();
	return 0;
}