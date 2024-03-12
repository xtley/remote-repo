#include <stdio.h>
#define MaxSize 10  // 定义最大长度 
typedef int ElemType; 
typedef struct{
	ElemType data[MaxSize];  //用静态的“数组”存放数据元素 
	int length; //顺序表的当前长度 
}SqList; //顺序表的类型定义（静态分配方式） 

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
} // 时间复杂度：最好 O(1) 最坏 O(n) 平均 O(n/2) 
bool ListDelete(SqList &L,int i,int &e) {
	if(i<1||i>L.length) return false;
	e=L.data[i-1]; // 把删除的变量告诉main函数 
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;
	return true;					   
} // 时间复杂度：最好 O(1) 最坏 O(n) 平均 O((n-1)/2) 
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
} //时间复杂度：最好O(1) 最坏 O(n) 平均 O(n) 
int main() {
	SqList L;
	InitList(L); 
	ListInsert(L,1,1);
	DisplayList(L);
	
	
	return 0;
} 
