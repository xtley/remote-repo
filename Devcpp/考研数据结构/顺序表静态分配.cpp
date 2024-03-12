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
bool ListInsert(SqList &L,int i,int e) {
	if(i<1||i>L.length+1||L.length>=MaxSize)
	    return false;
	for(int j=L.length;j>=i;j--) {
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
	return true; 
} // ʱ�临�Ӷȣ���� O(1) � O(n) ƽ�� O(n/2) 
bool ListDelete(SqList &L,int i,int &e) {
	if(i<1||i>L.length) return false;
	e=L.data[i-1]; // ��ɾ���ı�������main���� 
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;
	return true;					   
} // ʱ�临�Ӷȣ���� O(1) � O(n) ƽ�� O((n-1)/2) 
void DisplayList(SqList &L) {
	for(int i=0;i<L.length;i++) {
		printf("data[%d]=%d\n",i,L.data[i]);
	}
}
ElemType GetElem(SqList L,int i) {
	return L.data[i-1];
}
int LocateElem(SqList L,ElemType e) {
	for(int i=0;i<L.length;i++) 
		if(L.data[i]==e) return i+1;
	return 0;
} //ʱ�临�Ӷȣ����O(1) � O(n) ƽ�� O(n) 
int main() {
	SqList L;
	InitList(L); 
	ListInsert(L,1,1);
	DisplayList(L);
	
	
	return 0;
} 
