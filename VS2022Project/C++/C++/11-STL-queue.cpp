//#include <iostream>
//#include <queue>
//
//using namespace std;
//
////queue 队列 先进先出
//
////构造函数
//// queue<T> que;
//// queue(const queue &que);
////赋值操作
//// queue& operator=(const queue &que);
////数据存取
//// push(elem);  //往队尾添加元素
//// pop();      //往队头移除第一个元素
//// back();     //返回最后一个元素
//// front();    //返回第一个元素
////大小操作
//// empty(); //判断堆栈是否为空
//// size();  //返回栈的大小
//// emplace(elem); //队尾插入elem 返回插入值的引用
//
//void test01() {
//
//	queue<int> q1;
//	q1.push(5);
//	q1.push(6);
//	q1.push(7);
//	cout << q1.back() << endl;
//	cout << q1.front() << endl;
//	q1.pop();
//	cout << q1.back() << endl;
//	cout << q1.front() << endl;
//    cout << endl;
//
//	queue<int> q2(q1);
//	cout << q2.back() << endl;
//	cout << q2.front() << endl;
//	cout << endl;
//
//	queue<int> q3(q2);
//	cout << q3.back() << endl;
//	cout << q3.front() << endl;
//	cout << endl;
//
//	while (!q1.empty()) q1.pop();
//	/*cout << q1.back() << endl;
//	cout << q1.front() << endl;
//	cout << q1.size() << endl;
//	cout << endl;*/
//	swap(q1, q2);
//
//	cout << q1.back() << endl;
//	cout << q1.front() << endl;
//	cout << q1.size() << endl;
//	cout << endl;
//
//	q2.swap(q3);
//	cout << q2.back() << endl;
//	cout << q2.front() << endl;
//	cout << q2.size() << endl;
//
//	q1.emplace(77);
//	cout << q1.back() << endl;
//	cout << q1.front() << endl;
//	cout << q1.size() << endl;
//
//}
//
//int main() {
//	test01();
//
//
//
//	return 0;
//}