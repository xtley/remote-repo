//#include <iostream>
//#include <set>
//using namespace std;
//
////set/multiset
////set
////����Ԫ���ڲ���ʱ�Զ�������
////����
////���ڹ���ʽ����,�ײ�ṹ���ö�����ʵ�֡�
//// set/multiset����
//// set���������������ظ���Ԫ��
//// multiset�����������ظ���Ԫ��
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
////set����͸�ֵ
//void test01() {
//	//����
//	//set<T> st;        //Ĭ�Ϲ��캯��
//	//set(const set&st);   //�������캯��
//	//��ֵ
//	//set& operator=(const set &st); //���صȺŲ�����
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
////set��С�ͽ���
//void test02() {
//	//ͳ��set������С�Լ�����set����
//	//size();  //����������Ԫ�ص���Ŀ
//	//empty();  //�ж������Ƿ�Ϊ��
//	//swap(st); //����������������
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
////set�����ɾ��
//void test03() {
//	//insert(elem);  //�������в���Ԫ��
//	//clear();      //�������Ԫ��
//	//erase(pos);   //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
//	//erase(beg,end); //ɾ������[beg,end)������Ԫ�أ�������һ��Ԫ�صĵ�����
//	//erase(elem);   //ɾ��������ֵΪelem��Ԫ��
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
////set���Һ�ͳ��
//void test04() {
//	//find(key);  //����key�Ƿ���� ������� ���ظļ��ĵ����� �����ڷ���set.end();
//	//count(key);  //ͳ��key��Ԫ�ظ���
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
////set multiset����
//void test05() {
//	//set�����Բ��ظ�����,��multiset����
//	//set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�
//	//multiset���������ݣ���˿��Բ����ظ�����
//	set<int> s1;
//	s1.insert(10);
//	s1.insert(80);
//	s1.insert(50);
//	s1.insert(50);
//	cout << *s1.insert(80).first << endl; //����ֵ <iterator,bool> ������ָ�����Ԫ�� ʧ�� false �ɹ�true
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