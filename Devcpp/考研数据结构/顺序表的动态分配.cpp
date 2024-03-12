#include <stdio.h>
#include <stdlib.h> // malloc��free������ͷ�ļ� 
#define InitSize 10 //Ĭ�ϵ���󳤶� 
typedef int ElemType;
typedef struct{
	ElemType *data;  //ָ��̬���������ָ��  
	int MaxSize; //˳����������� 
	int length; //˳���ĵ�ǰ���� 
}SeqList; //˳�������Ͷ��壨��̬���䷽ʽ�� 

void InitList(SeqList &L) {
	L.data=(int*)malloc(InitSize*sizeof(int)); 
	L.length=0;
	L.MaxSize=InitSize;
}
void IncreaseSize(SeqList &L,int len) {
	int *p=L.data;
	L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));
	for(int i=0;i<L.length;i++) {
		L.data[i]=p[i];  //�����ݸ��Ƶ������� 
	} 
	L.MaxSize+=len;  //˳�����󳤶�����len
	free(p); //  �ͷ�ԭ�����ڴ�ռ� 
}
bool ListInsert(SeqList &L,int i,int e) {
	if(i<1||i>L.length+1||L.length>=L.MaxSize)
	    return false;
	for(int j=L.length;j>=i;j--) {
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
	L.MaxSize++;
	return true; 
} // ʱ�临�Ӷȣ���� O(1) � O(n) ƽ�� O(n/2) 
bool ListDelete(SeqList &L,int i,int &e) {
	if(i<1||i>L.length) return false;
	e=L.data[i-1]; // ��ɾ���ı�������main���� 
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;
	return true;					   
} // ʱ�临�Ӷȣ���� O(1) � O(n) ƽ�� O((n-1)/2) 
void DisplayList(SeqList &L) {
	for(int i=0;i<L.length;i++) {
		printf("data[%d]=%d\n",i,L.data[i]);
	}
}
ElemType GetElem(SeqList L,int i) {
	return L.data[i-1];
}
int LocateElem(SeqList L,ElemType e) {
	for(int i=0;i<L.length;i++) 
		if(L.data[i]==e) return i+1;
	return 0;
}
// ˳�����ص㣺
// 1.������ʣ�������O(1)ʱ�����ҵ���i��Ԫ�ء�����ʵ�֣�data[i-1],��̬���䣬��̬���䶼һ��
// 2.�洢�ܶȸߣ�ÿ���ڵ�ֻ�洢����Ԫ��
// 3.��չ���������� ��������ö�̬����ķ�ʽʵ�֣���չ���ȵ�ʱ�临�Ӷ�Ҳ�Ƚϸߣ� 

int main() {
	SeqList L;
	InitList(L); 
	for(int i=0;i<L.length;i++) {
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	
	
	return 0;
} 
