#include "data_manage.h"
#include "data_get.h"
#include "ui.h"

int main(void)
{

	head_ui();//��ӭ���档
	
	initialize_data();//��ʼ���������ڴ��д�����������

	get_data();//��ȡ�ļ����Ѵ��ѧ�����ݣ�д���ڴ�����׼���õĻ�������

	user_choose();//���أ����û�֮����н�����

	save();//�����ڴ���ѧ�����ݣ�����������ļ���

	getchar();//��ֹ�ļ����֡�
	getchar();
	return 0;
}