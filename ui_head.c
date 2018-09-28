#include <stdio.h>
#include "ui.h"

void head_ui(void)
{
	char *head = "ui_head.txt"; //欢迎界面的文件名
	get_photo(head);//调用文件读取函数
}