#include <stdio.h>
#include "data_manage_p.h"

int choose_temp;
int zero_data(void)
{
	if (number == 0) {
		printf("���ݿ���û���κ�ѧ����Ϣ��������ӣ��ٽ��в�����\n\a");
		printf("�Ƿ�������ӣ�\n�ǣ������� 1 ���񣬲�������һ���˵��������� 2 ��\n");
		printf("����ѡ��");
		scanf("%d", &choose_temp);
		if (choose_temp == 1) add_data();//���û���Ҫ������ݣ�ת��������Ӻ�����
		return -1;//�����쳣ֵ-1��
	}
	return 1;//�����ݿ��д������ݣ�����1��
}