#include <stdio.h>
#include <Windows.h>
#include "data_manage_p.h"



static FILE *open(void)
{
	static error(void);

mark:;
	FILE *fp;
	if ((fp = fopen(sign, "r")) == NULL) {
		printf("��ӭʹ�ñ����򣡼�⵽��һ��ʹ�øó�������Ϊ���������������ļ������Ժ�.....\n");//�޷����ļ���
		if((fp = fopen(sign, "w"))!=NULL){//��ֻдģʽ���ļ�����ʱ�ļ������ڣ�����Զ�����һ�������ļ���
			fclose(fp);
			Sleep(500);//����ʹ�����顣
			puts("�����ɹ���");
			goto mark;//������ֻ��ģʽ�򿪡�
		}
		else
			error();//����
	}
	else {
		printf("��ӭ�����ڳ�ʼ�������Ժ�.....\n");
		Sleep(1000);
		return fp;
	}

}

static error(void)
{
	puts("ʧ�ܣ�\a�Ƿ����¹�����");
	printf("1�����³��Թ�����\n2���˳���\n");
	int choose;
	scanf("%d", &choose);
	if (choose == 1)
		open();
	else
		exit(1);//ֱ���˳���
}

void get_data(void)
{
	FILE *fp = open();//���ļ�
	while (fscanf(fp, "%lld %s %s %d %d %d\n", &student[number].id, student[number].name,
		student[number].CLASS, &student[number].math,
		&student[number].english, &student[number].sum) != EOF) {//��ʽ����ȡ�ļ�����ѧ����Ϣ��
		number++;//ÿ�ɹ���ȡһ��ѧ����Ϣ��ѧ����������һ����
	}
	printf("��ʼ���ɹ�������ȡ%d��ѧ�����ݣ�\n", number);
	fclose(fp);

}