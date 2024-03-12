#include <stdio.h>
#include <stdlib.h> // malloc，free函数的头文件 
#define InitSize 10 //默认的最大长度 
typedef int ElemType;
typedef struct{
	ElemType *data;  //指向动态分配数组的指针  
	int MaxSize; //顺序表的最大容量 
	int length; //顺序表的当前长度 
}SeqList; //顺序表的类型定义（动态分配方式） 

void InitList(SeqList &L) {
	L.data=(int*)malloc(InitSize*sizeof(int)); 
	L.length=0;
	L.MaxSize=InitSize;
}
void IncreaseSize(SeqList &L,int len) {
	int *p=L.data;
	L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));
	for(int i=0;i<L.length;i++) {
		L.data[i]=p[i];  //将数据复制到新区域 
	} 
	L.MaxSize+=len;  //顺序表最大长度增加len
	free(p); //  释放原来的内存空间 
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
} // 时间复杂度：最好 O(1) 最坏 O(n) 平均 O(n/2) 
bool ListDelete(SeqList &L,int i,int &e) {
	if(i<1||i>L.length) return false;
	e=L.data[i-1]; // 把删除的变量告诉main函数 
	for(int j=i;j<L.length;j++)
		L.data[j-1]=L.data[j];
	L.length--;
	return true;					   
} // 时间复杂度：最好 O(1) 最坏 O(n) 平均 O((n-1)/2) 
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
// 顺序表的特点：
// 1.随机访问：可以在O(1)时间内找到第i个元素。代码实现：data[i-1],静态分配，动态分配都一样
// 2.存储密度高，每个节点只存储数据元素
// 3.拓展容量不方便 （即便采用动态分配的方式实现，拓展长度的时间复杂度也比较高） 

int main() {
	SeqList L;
	InitList(L); 
	for(int i=0;i<L.length;i++) {
		printf("data[%d]=%d\n",i,L.data[i]);
	}
	
	
	return 0;
} 
