#include "data_manage_p.h"
#include <stdio.h>

void save(void)
{
	FILE *fp;
	if ((fp = fopen(sign, "w")) == NULL) {//��ֻдģʽ���ļ���ͬʱɾ���ļ�����һ�ε����ݡ�
		printf("\a����ʧ�ܣ�");//��ʧ�ܡ�
	}
	else {
		for (int i = 0; i < number; i++) {
			fprintf(fp, "%lld %s %s %d %d %d\n", student[i].id, student[i].name,
				student[i].CLASS, student[i].math,
				student[i].english, student[i].sum);//���ڴ��е�ѧ�����ݸ�ʽ����ӡ���ļ����С�
		}
		printf("����ɹ�����������%d�����ݡ�\n", number);
		fclose(fp);
	}

}