#include <stdio.h>
#include "data_manage_p.h"
#include "data_manage.h"

static void shift_array(int index)
{
	int src; //����ֵԪ�ص�������

	for (src = index ; src <= number - 1 ; src++) {
		student[src] = student[src+1];//ǰ��
	}
	number--;//���������١�
}

int choose_temp;

void del_data(void)
{
mark:;
	if (zero_data() == -1) goto end;//���ݿ���û�����ݡ�
	long long aim;
	printf("������Ҫɾ��ѧ����ѧ�ţ�");
	scanf("%lld", &aim);
	int i = find_data(aim); //ʹ�ö��ֲ��Ҳ�ѯ��ѧ���Ƿ���ڡ�
	if (i != -1) {
		shift_array(i);//�����ƶ����������ݺ����Ԫ��ǰ�ƣ����Ǹ�Ԫ�ء�
		printf("ɾ���ɹ�����ǰ��¼��ѧ������Ϊ%d��\n",number);
	}
	else {
		printf("���󣡲��޴��ˣ�\n");
		printf("�Ƿ�����ɾ����\n����ɾ���������� 1 ������ɾ���������� 2 ��");

		scanf("%d", &choose_temp);

		if (choose_temp == 1) goto mark;
	}
	printf("�Ƿ����ɾ����\n����ɾ���������� 1 ������ɾ���������� 2 ��\n");
	printf("����ѡ��");
	scanf("%d", &choose_temp);

	if (choose_temp == 1) goto mark;
end:;

}