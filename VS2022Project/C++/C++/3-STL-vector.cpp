//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//class Person {
//public:
//	Person(string name, int age) :m_Name(name),m_Age(age){}
//	string m_Name;
//	int m_Age;
//};
//void Print(int val) {
//	cout << val << endl;
//}
//
//// 容器存储int
//void test01() {
//	vector<int> v;
//
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//
//	vector<int>::iterator itBegin = v.begin();
//	vector<int>::iterator itend = v.end();
//
//	while (itBegin != itend) {
//
//		cout << *itBegin << endl;
//		itBegin++;
//	}
//	cout << endl;
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << endl;
//	}
//
//	//STL提高遍历算法  利用回调的技术
//	cout << endl;
//	for_each(v.begin(), v.end(), Print);
//
//	//结合auto最方便的方法
//	cout << endl;
//	for (auto x : v) {
//		cout << x << endl;
//	}
//}
////容器存储自定义数据类型
//void test02() {
//	vector<Person> v;
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("ddd", 40);
//	Person p5("eee", 50);
//
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	v.push_back(Person("fff", 60));
//
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
//		// cout << (*it).m_Name << " " << (*it).m_Age << endl;
//		cout << it->m_Name << " " << it->m_Age << endl;
//	}
//
//	cout << endl;
//	for (auto x : v) {
//		cout << x.m_Name << " " << x.m_Age << endl;
//	}
//}
////容器存储自定义数据类型
//void test03() {
//	vector<Person*> v;
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("ddd", 40);
//	Person p5("eee", 50);
//
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//	v.push_back(&p4);
//	v.push_back(&p5);
//	//v.push_back(&Person("fff", 60));
//
//	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
//		//cout << (*it)->m_Name << " " << (*it)->m_Age << endl;
//		cout << (*(*it)).m_Name << " " << (*(*it)).m_Age << endl;
//		Person* p = *it;
//		//cout << (*p).m_Name << " " << (*p).m_Age << endl;
//		//cout << p->m_Name << " " << p->m_Age << endl;
//	}
//
//	cout << endl;
//	for (auto x : v) {
//		cout << x->m_Name << " " << x->m_Age << endl;
//	}
//}
////容器嵌套容器
//void test04() {
//
//	vector<vector<int>> v;
//
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> v3;
//	vector<int> v4;
//	vector<int> v5;
//
//	for (int i = 0; i < 5; i++) {
//		v1.push_back(i + 1);
//		v2.push_back(i + 2);
//		v3.push_back(i + 3);
//		v4.push_back(i + 4);
//		v5.push_back(i + 5);
//	}
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//	v.push_back(v5);
//
//	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
//		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
//			cout << *vit << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	for (auto x : v) {
//		for (auto y : x) {
//			cout << y << " " ;
//		}
//		cout << endl;
//
//	}
//}
////vector 构造函数
////vector 动态扩展
////并不是在原空续接新空间 而是寻找更大的内存空间 然后将原数据拷贝新空间 释放原空间
//void test05() {
//	//vector<T> v; 无参默认构造函数
//	//vector(v.begin(),v.end()>); 将v[begin(),end()]之间元素拷贝给自身
//	//vector(n,elem); 构造函数将n个elem拷贝给本身
//	//vector<const vector &vec>; //拷贝构造函数
//
//	vector<int> v1; //默认构造 无参构造
//
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//
//	for (auto x : v1) cout << x << " ";
//	cout << endl;
//	//通过区间方式进行构造
//	vector<int> v2(v1.begin(), v1.end());
//	for (auto x : v2) cout << x << " ";
//	cout << endl;
//
//	//通过n个elem构造
//	vector<int> v3(10,100);
//	for (auto x : v3) cout << x << " ";
//	cout << endl;
//
//	//通过拷贝构造函数构造
//	vector<int> v4(v3);
//	for (auto x : v4) cout << x << " ";
//	cout << endl;
//}
////vector 赋值操作
//void test06() {
//    //vector 赋值操作
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	for (auto x : v1) cout << x << " ";
//	cout << endl;
//
//	//赋值 operator=
//	vector<int> v2;
//	v2 = v1;
//	for (auto x : v2) cout << x << " ";
//	cout << endl;
//
//	//赋值 aggign
//	vector<int> v3;
//	v3.assign(v1.begin(), v1.end());
//	for (auto x : v2) cout << x << " ";
//	cout << endl;
//
//	//赋值 aggign n个方式
//	vector<int> v4;
//	v4.assign(10, 100);
//	for (auto x : v4) cout << x << " ";
//	cout << endl;
//
//	//赋值 aggign n个方式 {}
//	vector<int> v5;
//	v5.assign({1,2,3,4});
//	for (auto x : v5) cout << x << " ";
//	cout << endl;
//
//	cout << v1.capacity() << endl;
//	cout << v1.size() << endl;
//	//使用 aggign为原vector赋值 会直接覆盖调原来的所有元素 并且重新分配空间 但是大小capacity不会改变size会改变
//	v1.assign({ 1 });
//	for (auto x : v1) cout << x << " ";
//	cout << endl;
//	cout << v1.capacity() << endl;
//	cout << v1.size ()<< endl;
//
//}
////vector容量和大小
//void test07() {
//	//vector容量和大小
//
//	//empty(); 是否为空 为空返回true
//	//capacity(); 容器的容量
//	//size();  返回容器中元素的个数
//	//resize(int num); 重新指定容器的长度为num 如果容器变长则以默认值填差新位置
//	                   //如果容器变短 则末尾超出容器长度的元素被删除
//	//resize(int num,elem)  重新指定容器的长度为num 如果容器变长则以elem填差新位置
//	                   //如果容器变短 则末尾超出容器长度的元素被删除
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	for (auto x:v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	if (v1.empty()) cout << "v1为空" << endl;
//	else {
//		cout << "v1不为空" << endl;
//		cout << "v1的容量为：" << v1.capacity() << endl;
//		cout << "v1的大小为：" << v1.size() << endl;
//	}
//
//	//重新指定大小
//	v1.resize(15,100);
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	if (v1.empty()) cout << "v1为空" << endl;
//	else {
//		cout << "v1不为空" << endl;
//		cout << "v1的容量为：" << v1.capacity() << endl;
//		cout << "v1的大小为：" << v1.size() << endl;
//	}
//
//	//重新指定大小
//	v1.resize(5);
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	if (v1.empty()) cout << "v1为空" << endl;
//	else {
//		cout << "v1不为空" << endl;
//		cout << "v1的容量为：" << v1.capacity() << endl;
//		cout << "v1的大小为：" << v1.size() << endl;
//	}
//	
//}
////vector插入和删除
//void test08() {
//	//vector插入和删除
//	
//	//push_back(elem)  //尾部插入元素 ele
//	//pop_back();     //删除最后一个元素
//	//insert(const_iterator pos,elem ); 迭代器指向位置pos插入元素elem
//	//insert(const_iterator pos,int count,elem); 迭代器指向位置pos插入count个元素elem
//	//erase(const_iterator pos); 删除迭代器指向的元素
//	//erase(const_iterator start,const_iterator end); //删除迭代器从start到end之间的元素
//	//clear(); //删除容器中所有元素 size会为0 但是capacity不会改变
//
//	vector<int> v1;
//
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//	
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v1.pop_back();
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v1.insert(v1.begin()+1, 5); //插入到迭代器位置的前面
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v1.insert(v1.begin() + 1, 3,5); //插3个到迭代器位置的前面
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v1.erase(v1.begin()); //删除迭代器指定的元素
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v1.erase(v1.begin()+1,v1.end()-3); //删除迭代器区间内的元素
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v1.clear();
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//}
////vector 数据采取
//void test09() {
//	//vector 数据采取
//
//	//at(int idx); 返回索引idx所指的数据 引用
//	//operator[]    
//	//front()   返回容器中第一个数据元素 引用
//	//back      返回元素中最后一个元素 
//
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	for (auto x : v1) cout << x << " ";
//	cout << endl;
//	v1.at(0) = 55;
//	cout << v1.at(0) << endl;
//
//	for (auto x : v1) cout << x << " ";
//	cout << endl;
//
//	v1.front() = 66;
//	cout << v1.front() << endl;
//
//	v1.back() = 77;
//	cout << v1.back() << endl;
//
//	for (auto x : v1) cout << x << " ";
//	cout << endl;
//
//}
////vector 互换容器
//void test10() {
//	//vector 互换容器
//	//实现两个容器内元素进行互换
//
//	//swap(vec) 将vec与本身元素互换 所有信息互换
//
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//
//
//	vector<int> v2;
//	for (int i = 0; i < 11; i++) {
//		v2.push_back(i+1);
//	}
//
//
//	cout << "v1:" << endl;
//	cout << "capacity:" << v1.capacity() << endl;
//	cout << "size:" << v1.size() << endl;
//	cout << "遍历:" << endl;
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl << endl;
//
//	cout << "v2:" << endl;
//	cout << "capacity:" << v2.capacity() << endl;
//	cout << "size:" << v2.size() << endl;
//	cout << "遍历:" << endl;
//	for (auto x : v2) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v1.swap(v2);
//
//	cout << "v1:" << endl;
//	cout << "capacity:" << v1.capacity() << endl;
//	cout << "size:" << v1.size() << endl;
//	cout << "遍历:" << endl;
//	for (auto x:v1) {
//		cout << x << " ";
//	}
//	cout << endl<<endl;
//
//	cout << "v2:" << endl;
//	cout << "capacity:" << v2.capacity() << endl;
//	cout << "size:" << v2.size() << endl;
//	cout << "遍历:" << endl;
//	for (auto x : v2) {
//		cout << x << " ";
//	}
//	cout << endl<<endl;
//
//
//	//实际用途 巧用swap可以收缩内存空间
//
//	vector<int> v;
//	for (int i = 0; i < 100000; i++) {
//		v.push_back(i);
//	}
//	cout << "v的容量:" << v.capacity() << endl;
//	cout << "v的大小:" << v.size() << endl;
//
//	v.resize(3); //重新指定大小
//	cout << "v的容量:" << v.capacity() << endl; //容量没有变化 浪费了
//	cout << "v的大小:" << v.size() << endl << endl;
//
//	//巧用swap收缩内存
//	vector<int>(v).swap(v);  
//	//vector<int>(v); 利用拷贝构造函数创建匿名对象
//	//和匿名对象互换 然后原来的容器变为匿名对象这行结束之后原来的占用就消失了
//	cout << "v的容量:" << v.capacity() << endl; //容量变化 内存开销降低
//	cout << "v的大小:" << v.size() << endl;
//}
////vector预留空间
//void test11() {
//	//vector预留空间
//	//减少vector在动态扩展是的扩展次数 如果一开始知道就直接预留 不需要多余的去开辟
//
//	//函数原型
//	//reserve(int len);  //容器预留len个元素长度，预留位置不初始化，元素不可访问
//	//不会改变 size len如果比下载的capacity小的话不会扩展 否则将capacity扩展到len
//
//	//统计开辟过程中扩展了多少次内存
//
//	vector<int> v;
//	int num = 0;
//	int* p = NULL;
//
//	int num2 = 0;
//	int p2 = 0;
//	for (int i = 0; i < 100000; i++) { //空间扩展首地址会改变
//		v.push_back(i);
//		if (p != &v[0]) {
//			p = &v[0];
//			num++;
//		}
//
//		if (p2 != v.capacity()) {
//			p2 = v.capacity();
//			num2++;
//			cout << p2 << endl;
//		}
//	}
//	cout << "num:" << num << endl;
//	cout << "num2:" << num2 << endl;
//	vector<int > v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//	cout << "v1:" << endl;
//	cout << "capacity:" << v1.capacity() << endl;
//	cout << "size:" << v1.size() << endl;
//
//	v1.reserve(15);  
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//	cout << "v1:" << endl;
//	cout << "capacity:" << v1.capacity() << endl;
//	cout << "size:" << v1.size() << endl;
//
//
//}
////补充 reverse 反转容器
//void test12() {
//	vector<int> ve(20, 9);
//	ve[0] = 8;
//	ve[19] = 11;
//	for (auto x : ve) cout << x << " ";
//	cout << endl;
//	reverse(ve.begin(),ve.end());
//	for (auto x : ve) cout << x << " ";
//	cout << endl;
//
//}
//int main() {
//	test12();
//
//	return 0;
//}