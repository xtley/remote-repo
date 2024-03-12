//学生信息管理系统如下，请按功能要求补充完整函数
#include<stdio.h>
#include<stdlib.h>
//学生信息
struct student{
	int Num;
	float score;//成绩
	struct student *next;
}//学号
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
//实现功能:从键盘输入 20 个学生的信息，用尾插法创建链表并返回链表头。
}
float average(struct student *head) {
//head 为链表头，该链表由 create 函数建立
//实现功能:计算链表中所有学生的平均成绩并返回该成绩
}

float average(struct student *head) {
	//head 为链表头，该链表由 create 函数建立
//实现功能:计算链表中所有学生的平均成绩并返回该成绩
}
struct student *excellent(struct student *head,float ave){
	//head 为链表头，ave 为学生平均成绩
	//实现功能:从该链表中找出所有超过平均成绩的优秀学生，按成绩从高到低的顺序创建一个新链表，链表头指向成绩最高的学生，并返回新链表头。
}


