#include <stdio.h>
#include "data_manage_p.h"

static void shift_array(int index)
{
	int src; //����ֵԪ�ص�������

	for (src = number - 1; src >= index; src--) {
		student[src + 1] = student[src];
	}
	number++;
}

int choose_temp;

void add_data(void)
{
mark:;
	Student temp;//��ʱ���档
	/*�����ѧ�����ݵĶ�ȡ*/
	printf("������һ��ѧ�������ݣ�\n");
	printf("ѧ�ţ�"); scanf("%lld", &temp.id);
	printf("������"); scanf("%s", temp.name);
	printf("�༶��"); scanf("%s", temp.CLASS);
	printf("��ѧ�ɼ���"); scanf("%d", &temp.math);
	printf("Ӣ��ɼ���"); scanf("%d", &temp.english);
	temp.sum = temp.math + temp.english;
	int i;
	int error = 0;

	for (i = 0; i < number; i++) {//ѧ�Ų��أ�˳����ң���
		if (student[i].id >= temp.id) {
			if (student[i].id == temp.id) error = 1; //ѧ����ͬ������
			break;//��ʱi��ǡ�ô洢�˸�ѧ������ѧ�Ŵ�С��������Ӧ�����λ�á�
		}
	}
	if (error == 1) {
		printf("\aѧ�Ų�����ͬ��\n");
		printf("�Ƿ�������ӣ�\n������ӣ������� 1 ��������ӣ������� 2 ��\n����ѡ��");

		scanf("%d", &choose_temp);

		if (choose_temp == 1) goto mark;
	}
	else {
		shift_array(i);//�����ƶ�����������ѧ��������Ӧ����λ��֮���ѧ��������ȫ��˳���ƶ���
		student[i] = temp;//���ݲ��롣

		printf("��ӳɹ�����ǰ��¼��ѧ������Ϊ%d��\n", number);
		printf("�Ƿ������ӣ�\n������ӣ������� 1 ��������ӣ������� 2 ��");
		
		scanf("%d", &choose_temp);

		if (choose_temp == 1) goto mark;
		
	}

}