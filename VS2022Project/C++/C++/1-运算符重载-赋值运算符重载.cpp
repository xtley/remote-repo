//#include <iostream>
//#include <string>
//#define my _1_
//using namespace std;
//
////���������-��ֵ��������� =
//
////���������Զ�Ϊ�������ĸ�����
////operator= ���Զ�����
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
//	//���� ��ֵ�����
//	myPerson& operator=(myPerson &p) {
//		//�������ṩǳ���� m_Age = p.m_Age;
//
//		//Ӧ�����ж��Ƿ��������ڶ�ȥ ��������ͷŸɾ���Ȼ�������
//		if (m_Age != NULL) {
//			delete m_Age;
//			m_Age = NULL;
//		}
//		m_Age = new int(*p.m_Age);
//		//���ض�����
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
//	p2 = p1; //��ֵ����
//	cout << "p1������Ϊ��" << *p1.m_Age << endl;
//
//	cout << "p1������Ϊ��" << *p2.m_Age << endl;
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
