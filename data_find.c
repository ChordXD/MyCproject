#include "data_manage_p.h"
#include <stdio.h>
int find_data(long long aim)//���ֲ��ҡ�
{
	int first = 0;
	int last = number - 1;
	
	while (first <= last) {
		int middle = (first + last)/2;//ȡ�м����ݵ��±�
		if (student[middle].id == aim) return middle;//���ҵ��������±ꡣ
		else if (student[middle].id < aim) first = middle + 1;//���±�ֵ��Ӧ�����ݱ�Ŀ��ֵС������һ�εĿ�ʼ�±��Ϊ���ڵ���ֵ�±�+1��
		else last = middle - 1;//ͬ�£������෴��
	}
	return -1;//�����������ж�δ�ҵ��������쳣ֵ-1 ��

}

void display_find_data(void)
{
mark:;
	if (zero_data() == -1) goto end;//�쳣��������û���κ����ݡ�
	long long temp;
	printf("����������Ҫ���ҵ�ͬѧ��ѧ�ţ�");
	scanf("%lld", &temp);
	int i = find_data(temp); //ʹ�ö��ֲ��Ҳ�ѯ��ѧ���Ƿ����,���һ�ø����ݵ��±ꡣ
	if (i != -1) {
		printf("ѧ��                   ����       �༶       ��������   Ӣ�����   �ܷ�\n");
		print(i);
	}
	else 
		printf("���󣡲��޴��ˣ�\n");//û���ҵ���
	printf("�Ƿ������ѯ��\n������ѯ�������� 1 ��\n������ѯ����������һ���������� 2 ��\n");
	int temp_choose;
	scanf("%d", &temp_choose);
	if (temp_choose == 1) goto mark;//�����û�ѡ�����¶���
end:;//�쳣�����ʶ��
}