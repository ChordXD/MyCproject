#include <stdio.h>
#include "data_manage_p.h"

Student student[DATA_MAX];//���ڴ��д���һ��DATA_MAX��С����ʱ�������飬���ѧ�����ݡ�
char sign[] = "data.txt";//�����ļ����ļ���
int number;//ѧ������
int user_number;

void initialize_data(void)
{
	user_number = 0;
	number = 0;//��ʼ��ѧ��������	
}