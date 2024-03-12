#include <iostream>
#include <stack>
using namespace std;

//栈 符合先进后出

//构造函数
// stack<T> stk;
// stack(const stack &stk);
//赋值操作
// stack& operator=(const stack &stk);
//数据存取
// push(elem); //向栈顶添加元素
// pop();      //从栈顶移除第一个元素
// top();     //返回栈顶元素
//大小操作
// empty(); //判断堆栈是否为空
// size();  //返回栈的大小
// swap(stk1,stk2); //交换
// stk1.swap(stk2); //交换
// stack.emplace(elem); //原位构造函数 返回插入元素的引用
//void test01() {
//
//	stack<int> stk1;
//	stk1.push(3);
//	stk1.push(4);
//	stk1.push(6);
//	stk1.pop();
//	cout << stk1.top() << endl;
//
//	stack<int> stk2(stk1);
//	cout << stk2.top() << endl;
//
//	stack<int> stk3 = stk2;
//	cout << stk3.top() << endl;
//
//	stack<int> stk4 = stk3;
//	cout << stk4.top() << endl;
//
//	stack<int> stk5;
//	stk5 = stk4;
//	cout << stk5.top() << endl;
//
//	cout << stk5.size() << endl;
//
//	while (!stk5.empty()) stk5.pop();
//	cout << stk5.size() << endl;
//	if (stk5.empty()) cout << "stk5为空" << endl;
//	//stk5.pop(); 为空出栈报错
//
//	swap(stk4, stk5);
//	cout << stk4.size() << endl;
//	cout << stk5.size()<< endl;
//
//	stk3.swap(stk4);
//
//	cout << stk3.size() << endl;
//	cout << stk4.size() << endl;
//
//	stk3.emplace(4);
//	stk3.emplace(6)=8;
//	//cout << stk3.emplace(7) << endl;
//	cout << stk3.top() << endl;
//}
//int main() {
//
//	test01();
//
//
//
//	return 0;
//}