#include <stdio.h>
#include "ui.h"
#include "data_manage.h"
#include "data_manage_p.h"

void user_choose(void)
{
	int temp;
	do {
		printf("\n");//�����С�
		direction_ui();//��������ͼ���ļ���
		printf("����ѡ��");
		scanf("%d", &temp);
		switch (temp)//����ѡ��
		{
		case 1: put_all(); break;//��ʾ����ѧ����Ϣ��
		case 2: display_find_data();break;//������Ϣ����ʾ��
		case 3: add_data(); break;//����һ��ѧ������Ϣ��
		case 4: del_data(); break;//ɾ��һ��ѧ������Ϣ��
		case 5: break;//�˳���
		default: printf("��������ȷ�Ĳ������");
			break;
		}
	} while (temp!=5);

}