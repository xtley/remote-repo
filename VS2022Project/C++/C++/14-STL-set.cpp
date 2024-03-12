//#include <iostream>
//#include <set>
//using namespace std;
//
////set/multiset
////set
////所有元素在插入时自动被排序
////本质
////属于关联式容器,底层结构是用二叉树实现。
//// set/multiset区别
//// set不允许容器中有重复的元素
//// multiset允许容器有重复的元素
//
//void Print(set<int>& s) {
//	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void Print1(multiset<int>& s) {
//	for (multiset<int>::iterator it = s.begin(); it != s.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
////set构造和赋值
//void test01() {
//	//构造
//	//set<T> st;        //默认构造函数
//	//set(const set&st);   //拷贝构造函数
//	//赋值
//	//set& operator=(const set &st); //重载等号操作符
//	set<int> s1;
//	s1.insert(10);
//	s1.insert(80);
//	s1.insert(50);
//	s1.insert(50);
//	Print(s1);
//
//	multiset<int> s2;
//	s2.insert(10);
//	s2.insert(80);
//	s2.insert(50);
//	s2.insert(50);
//	Print1(s2);
//}
////set大小和交换
//void test02() {
//	//统计set容器大小以及交换set容器
//	//size();  //返回容器中元素的数目
//	//empty();  //判断容器是否为空
//	//swap(st); //交换两个集合容器
//
//	set<int> s1;
//	s1.insert(10);
//	s1.insert(80);
//	s1.insert(50);
//	s1.insert(50);
//	cout << s1.size() << endl;
//	Print(s1);
//
//	set<int> s2;
//	s2.insert(10);
//	s2.insert(90);
//	s2.insert(50);
//	s2.insert(50);
//	Print(s2);
//
//	s1.swap(s2);
//
//	Print(s1);
//	Print(s2);
//
//	set<int> s3;
//	cout << s3.empty() << endl;
//
//}
////set插入和删除
//void test03() {
//	//insert(elem);  //在容器中插入元素
//	//clear();      //清除所有元素
//	//erase(pos);   //删除pos迭代器所指的元素，返回下一个元素的迭代器
//	//erase(beg,end); //删除区间[beg,end)的所有元素，返回下一个元素的迭代器
//	//erase(elem);   //删除容器中值为elem的元素
//
//	set<int> s1;
//	s1.insert(10);
//	s1.insert(80);
//	s1.insert(50);
//	s1.insert(50);
//	cout << s1.size() << endl;
//	Print(s1);
//
//	s1.erase(s1.begin());
//	Print(s1);
//	s1.erase(s1.begin(), s1.end());
//	Print(s1);
//	s1.insert(10);
//	s1.insert(80);
//	s1.insert(50);
//	s1.insert(50);
//	Print(s1);
//	s1.erase(50);
//	Print(s1);
//	s1.clear();
//	Print(s1);
//
//}
////set查找和统计
//void test04() {
//	//find(key);  //查找key是否存在 如果存在 返回改键的迭代器 不存在返回set.end();
//	//count(key);  //统计key的元素个数
//
//	set<int> s1;
//	s1.insert(10);
//	s1.insert(80);
//	s1.insert(50);
//	s1.insert(50);
//	cout << s1.size() << endl;
//	Print(s1);
//	cout << *s1.find(50) << endl;
//	cout << s1.count(50) << endl;
//}
////set multiset区别
//void test05() {
//	//set不可以插重复数据,而multiset可以
//	//set插入数据的同时会返回插入结果，表示插入是否成功
//	//multiset不会检测数据，因此可以插入重复数据
//	set<int> s1;
//	s1.insert(10);
//	s1.insert(80);
//	s1.insert(50);
//	s1.insert(50);
//	cout << *s1.insert(80).first << endl; //返回值 <iterator,bool> 迭代器指向插入元素 失败 false 成功true
//	cout << s1.insert(90).second << endl;
//	Print(s1);
//
//
//}
//int main() {
//	test05();
//
//
//
//	return 0;
//}