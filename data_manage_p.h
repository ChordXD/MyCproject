#pragma once
#ifndef DATA_MANAGE_P_H_INCLUDED
#define DATA_MANAGE_P_H_INCLUDED

/*��ͷ�ļ�Ϊ��ϵͳ�����ݽṹ���ṹ�����顣
�ŵ㣺���ڹ��������֣����ҽϿ��뷽�㡣
ȱ�㣺��Ϊ�ķ��ڴ���Դ��
*/

#define NAME_MAX_SIZE (100)//�������ֵ�ĺ궨��
#define DATA_MAX (100000)//�ڴ��еĻ������ݣ�Ҳ�Ǹ�ϵͳ�����Դ洢���ȡ��ѧ����Ϣ������

/*��ϵͳû�м������Խ��Ĺ���*/

//ѧ����Ϣ�ṹ�塣
typedef struct {
	long long id;
	char name[NAME_MAX_SIZE];
	char CLASS[NAME_MAX_SIZE];
	int math;
	int english;
	int sum;
}Student;

//���������initialize.c���ҵ���Ϊϵͳ�ز���ȱ��������Ϣ��
extern char sign[];//���ݱ�����ļ�����
extern Student student[];//�ڴ��г�ʼ���Ľṹ�����顣
extern int number;//ʵʱ��ѧ��������

#endif //!DATA_MANAGE_P_H_INCLUDED