#include <stdio.h>
#include "data_manage.h"
#include "data_manage_p.h"

void print(int aim)
{
	printf("%-20lld   %-10s %-10s %-10d %-10d %-10d\n", student[aim].id, student[aim].name,
		student[aim].CLASS, student[aim].math,
		student[aim].english, student[aim].sum);//��ʽ���������ѧ�����ݡ�
}

void put_all(void)
{
	if (zero_data() == -1) goto end;//��û�����ݣ�ִ�д˶Ρ�
	printf("ѧ��                   ����       �༶       ��������   Ӣ�����   �ܷ�\n");
	for (int i = 0; i < number; i++)
		print(i);//ѭ����ӡ�������ݡ�
	printf("��ݲ�����\n1��ɾ�����ݡ�\n2��������ݡ�\n3����������\n4��ʲôҲ������������һ���˵���\n");
	int choose_put;
	printf("����ѡ��");
	scanf("%d", &choose_put);
	switch (choose_put)
	{
	case 1:del_data(); break;
	case 2:add_data(); break;
	case 3:display_find_data(); break;
	case 4:break;
	default:printf("��������ȷ�Ĳ������֣�\a");
		break;
	};
end:;
}
