//ѧ����Ϣ����ϵͳ���£��밴����Ҫ�󲹳���������
#include<stdio.h>
#include<stdlib.h>
//ѧ����Ϣ
struct student{
	int Num;
	float score;//�ɼ�
	struct student *next;
}//ѧ��
struct student *create();
float average(struct student *head);
struct student *excellent(struct student *head, float ave);
int main() (
	struct student *head, *excellent head;
	head=create();
	excellent head=excellent(head,average(head));
	return 0;
}
struct student *create(){
//ʵ�ֹ���:�Ӽ������� 20 ��ѧ������Ϣ����β�巨����������������ͷ��
}
float average(struct student *head) {
//head Ϊ����ͷ���������� create ��������
//ʵ�ֹ���:��������������ѧ����ƽ���ɼ������ظóɼ�
}

float average(struct student *head) {
	//head Ϊ����ͷ���������� create ��������
//ʵ�ֹ���:��������������ѧ����ƽ���ɼ������ظóɼ�
}
struct student *excellent(struct student *head,float ave){
	//head Ϊ����ͷ��ave Ϊѧ��ƽ���ɼ�
	//ʵ�ֹ���:�Ӹ��������ҳ����г���ƽ���ɼ�������ѧ�������ɼ��Ӹߵ��͵�˳�򴴽�һ������������ͷָ��ɼ���ߵ�ѧ����������������ͷ��
}


