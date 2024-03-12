//#include <iostream>
//#include <algorithm>
//#include <deque>
//
//using namespace std;
//
////deque容器
////deque容器基本概念
////双端数组，可以对头端进行插入删除操作
////deque和vector区别
//// 
//// vector对于头部的插入删除效率低，数据量越大，效率越低
//// deque相对而言 对头部的插入删除速度比vector快
//// vector访问元素时的速度会被deque快 这和两者的内部实现有关
//// 
//// deque内部工作原理:
//// deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
//// 中控器维护的是每个缓冲区的地址.使得使用deque时像一片连续的内存空间
//// 
//// deque容器的迭代器也是支持随机访问的
//// 
//
//void Print(const deque<int> &d) {
//	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////deque构造函数
//void test01() {
//	//deque<T> deq T;  //默认构造形式
//	//deque(beg,end);  //构造函数将[beg,end]区间中的元素拷贝给本身
//	//deque(n,elem);   //构造函数将n个elem拷贝给本身
//	//deque(const deque &dep); //拷贝构造函数
//
//	deque<int> d1(10,6);
//	Print(d1);
//	deque<int> d2(d1.begin()+3,d1.end()-2);
//	Print(d2);
//	deque<int> d3(d2);
//	Print(d3);
//
//}
////deque赋值操作
//void test02() {
//	//deque& operator=(const deque &deq);  //重载等号操作符
//	//assign(beg,end);    //将[beg,end]区间中的数据拷贝赋值给本身
//	//assign(n,elem);    //将n个elem拷贝赋值给本身
//	deque<int> d1(10,6);
//	Print(d1);
//	deque d2 = d1;
//	Print(d2);
//	deque<int> d3;
//	d3.assign(d1.begin(), d1.end());
//	Print(d3);
//	deque<int> d4;
//	d4.assign(10,7);
//	Print(d4);
//}
////deque大小操作
//void test03() {
//	//deque.empty(); //判断容器是否为空
//	//deque.size();  //返回容器中元素的个数
//	//deque.resize(num); //重新指定容器的长度为num,如果容器变长，则以默认填充新位置
//	//                   //如果容器变短，则末尾超出容器长度的元素被删除
//	//deque.resize(num,elem);  //重新指定容器的长度为num，如果容器变长，则以elem值填充新位置
//	//                         //如果容器变短，则末尾超出容器长度的元素被删除
//
//	deque<int> d1(10,7);
//	Print(d1);
//	cout << d1.size() << endl;
//	d1.resize(20);
//	Print(d1);
//	d1.resize(30,8);
//	Print(d1);
//	d1.resize(8);
//	Print(d1);
//	d1.resize(0);
//	if (d1.empty()) cout << "deque容器为空" << endl;
//}
////deque插入和删除
//void test04() {
//	// 两端插入操作
//	// push_back(elem);  //在容器尾部添加一个数据
//	// push_front(elem); //在容器头部插入一个数据
//	// pop_back();       //删除容器最后一个元素
//	// pop_front();      //删除容器第一个元素
//	// 
//	// 指定位置操作:
//	// 注意下面的pos是迭代器
//	// insert(pos,elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置  返回一个随机访问迭代器，它指向从中删除元素的位置。
//	// insert(pos,n,elem); //在pos位置插入n个elem数据，无返回值
//	// insert(pos,beg,end); //在pos位置插入[beg,end) 区间的数据，无返回值
//	// clear();   //清空容器的所有数据
//	// erase(beg,end); //删除[beg,end)区间的数据，返回下一个数据的位置 返回一个随机访问迭代器，它指向从中删除元素的位置。
//	// erase(pos);     //删除pos位置的数据 返回下一个数据的位置 返回一个随机访问迭代器，它指向从中删除元素的位置。
//
//	deque<int> d1;
//	d1.push_back(5);
//	d1.push_front(8);
//	Print(d1);
//	d1.resize(10, 6);
//	d1.pop_back();
//	Print(d1);
//	d1.pop_front();
//	Print(d1);
//
//	auto it1=d1.insert(d1.begin() + 4, 9);
//	cout << *it1 << endl;
//	Print(d1);
//	d1.insert(d1.begin()+1, 4, 10);
//	Print(d1);
//	d1.insert(d1.begin()+3, d1.begin(), d1.end()); //**** 三个参数都是迭代器
//	Print(d1);
//	
//	auto it2=d1.erase(d1.begin() + 2, d1.end()-1);
//	cout << *it2 << endl;
//	Print(d1);
//	auto it3=d1.erase(d1.begin());
//	cout << *it3 << endl;
//	Print(d1);
//	d1.clear();
//	Print(d1);
//
//
//}
////deque数据存取
//void test05() {
//	//at(int idx);  //返回索引idx处的引用
//	//operator[];   //返回索引idx处的引用
//	//front();    //返回容器中第一个元素的引用
//	//back();    //返回元素中最后一个元素的引用
//
//	deque<int> d1(10, 6);
//	Print(d1);
//	cout << d1.at(2) << endl;
//	Print(d1);
//	d1.at(3) = 5;
//	Print(d1);
//	cout << d1.at(4) << endl;
//	d1[4] = 6;
//	Print(d1);
//	cout << d1.front() << endl;
//	d1.front() = 7;
//	Print(d1);
//	cout << d1.back() << endl;
//	d1.back() = 8;
//	Print(d1);
//	
//}
////deque容器排序 对于支持随机访问的迭代器都可以使用sort进行排序
//void test06() {
//	deque<int> d1;
//	for (int i = 15; i > 0; i--) {
//		d1.push_back(i);
//	}
//	Print(d1);
//	sort(d1.begin(), d1.end());
//	Print(d1);
//}
//// 补充  emplace() 插入
//void test07() {
//    //emplace  c++11 原位构造元素
//	//iterator emplace(const_iterator position, value_type val);
//	// position:它定义了要插入新元素的位置。
//    // val:要插入的新值。
//	// 返回值：它将迭代器返回到新构造的元素。
//	//
//	deque<int> d1(20, 6);
//	d1[0] = 8;
//	d1[19] = 77;
//	Print(d1);
//	auto it=d1.emplace(d1.begin()+11, 88);
//	Print(d1);
//	cout << *it << endl;
//
//}
//int main() {
//
//	test07();
//
//	return 0;
//}