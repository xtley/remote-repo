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

typedef struct{
	ElemType *data;  //指向动态分配数组的指针  
	int length; //顺序表的当前长度 
}SeqList; //顺序表的类型定义（动态分配方式） 

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
