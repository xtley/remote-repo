#include <iostream>
#include <stack>
using namespace std;

//ջ �����Ƚ����

//���캯��
// stack<T> stk;
// stack(const stack &stk);
//��ֵ����
// stack& operator=(const stack &stk);
//���ݴ�ȡ
// push(elem); //��ջ�����Ԫ��
// pop();      //��ջ���Ƴ���һ��Ԫ��
// top();     //����ջ��Ԫ��
//��С����
// empty(); //�ж϶�ջ�Ƿ�Ϊ��
// size();  //����ջ�Ĵ�С
// swap(stk1,stk2); //����
// stk1.swap(stk2); //����
// stack.emplace(elem); //ԭλ���캯�� ���ز���Ԫ�ص�����
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
//	if (stk5.empty()) cout << "stk5Ϊ��" << endl;
//	//stk5.pop(); Ϊ�ճ�ջ����
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