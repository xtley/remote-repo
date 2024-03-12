//#include <iostream>
//#include <string>
//#define my _2_
//using namespace std;
//
////函数调用运算符重载 仿函数 类中重载小括号
////
//
////打印输出类
//class myPrint {
//public:
//
//	//重载函数调用运算符
//
//	void operator() (string test) {
//		cout << test << endl;
//	}
//};
//
////加法类
//class myAdd {
//public:
//	int operator()(int num1, int num2) {
//		return num1 + num2;
//	}
//
//
//
//};
//void myPrint02(string test) {
//	cout << test << endl;
//}
//void mytest01() {
//	myPrint myPrint;
//
//	myPrint("hello world");
//	myPrint02("hello world");
//}
//void mytest02() {
//	myAdd myadd;
//	int ret = myadd(100, 100);
//	cout << "ret =" << ret << endl;
//
//	//匿名函数对象
//	cout << myAdd()(100, 100) << endl;
//}
////int main() {
////	
////
////	return 0;
////}
