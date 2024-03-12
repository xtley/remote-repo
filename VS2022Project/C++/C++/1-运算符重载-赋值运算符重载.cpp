//#include <iostream>
//#include <string>
//#define my _1_
//using namespace std;
//
////运算符重载-赋值运算符重载 =
//
////编译器会自动为类声明四个函数
////operator= 会自动声明
//
//class myPerson {
//public:
//	myPerson(int age) :m_Age(new int(age)) {}
//	/*~Person() {
//		if (m_Age != NULL) {
//			delete m_Age;
//			m_Age = NULL;
//		}
//	}*/
//	//重载 赋值运算符
//	myPerson& operator=(myPerson &p) {
//		//编译器提供浅拷贝 m_Age = p.m_Age;
//
//		//应该先判断是否有属性在堆去 如果有先释放干净，然后再深拷贝
//		if (m_Age != NULL) {
//			delete m_Age;
//			m_Age = NULL;
//		}
//		m_Age = new int(*p.m_Age);
//		//返回对象本身
//		return *this;
//	}
////private:
//	int* m_Age;
//};
//void mytest01() {
//	myPerson p1(18);
//
//	myPerson p2(20);
//
//	p2 = p1; //赋值操作
//	cout << "p1的年龄为：" << *p1.m_Age << endl;
//
//	cout << "p1的年龄为：" << *p2.m_Age << endl;
//}
//void mytest02() {
//
//	int a = 10;
//	int b = 20;
//	int c = 30;
//
//	//c = b = a; 10 10 10
//
//	myPerson p1(10);
//	myPerson p2(20);
//	myPerson p3(30);
//	p3 = p2 = p1;
//
//	cout << *p1.m_Age << endl;
//	cout << *p1.m_Age << endl;
//	cout << *p1.m_Age << endl;
//}
////int main() {
////	//mytest01();
////	mytest02();
////
////
////	return 0;
////}
