//#include <iostream>
//#include <queue>
//
//using namespace std;
//
////queue ���� �Ƚ��ȳ�
//
////���캯��
//// queue<T> que;
//// queue(const queue &que);
////��ֵ����
//// queue& operator=(const queue &que);
////���ݴ�ȡ
//// push(elem);  //����β���Ԫ��
//// pop();      //����ͷ�Ƴ���һ��Ԫ��
//// back();     //�������һ��Ԫ��
//// front();    //���ص�һ��Ԫ��
////��С����
//// empty(); //�ж϶�ջ�Ƿ�Ϊ��
//// size();  //����ջ�Ĵ�С
//// emplace(elem); //��β����elem ���ز���ֵ������
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