#include <stdio.h>
#define MaxSize 10  // ������󳤶� 
typedef int ElemType; 
typedef struct{
	ElemType data[MaxSize];  //�þ�̬�ġ����顱�������Ԫ�� 
	int length; //˳���ĵ�ǰ���� 
}SqList; //˳�������Ͷ��壨��̬���䷽ʽ�� 

void InitList(SqList &L) {
	L.length=0;
}

typedef struct{
	ElemType *data;  //ָ��̬���������ָ��  
	int length; //˳���ĵ�ǰ���� 
}SeqList; //˳�������Ͷ��壨��̬���䷽ʽ�� 

void InitList(SeqList &L) {
	L.length=0;
}

int main() {
	SqList L;
	InitList(L); 
	for(int i=0;i<L.length;i++) {
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	
	
	return 0;
} 
