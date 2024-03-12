//#include <iostream>
//#include <queue>
//
//using namespace std;
//
////���ȶ���  priority_queue
////��C++��������<queue>���Ѿ�ʵ�ֺ������ȶ������ֽṹ
//// priority_queue<int> que; ����һ���洢�������͵����ȶ��� ��ֵԽ�����ȼ�Խ��(�����)
//// 
//// ���ȶ�������ͨ����һ���������������Ԫ��
//// ÿ��Ԫ��ӵ���ض������ȼ�������ʱ�������ȼ��Ӵ�С����
//// �����ȶ��зǿ�ʱ������(ֻ��)��ȡ���ȼ���ߵ�Ԫ��
//// ���ȶ���һ��ʹ�ö���ʵ��
//// 
//// ���ȶ���que�Ĳ���
//// que.size();   //�������ȶ�����Ԫ������ �������Ӷ�
//// que.push(x);  //��Ԫ��x�������ȶ��� �������Ӷ�
//// que.pop();    //�����ȼ���ߵ�Ԫ�س��� �������Ӷ�
//// que.top();    //�������ȼ���ߵ�Ԫ�� �������Ӷ�
//// que.empty();  //�ж����ȶ����Ƿ�Ϊ�� �������Ӷ�
//// que.emplace(elem); //ԭλ���캯��
//// ���ȶ��ж���
//// priority_queue<int> que;
//// priority_queue <T,vector<T>,(����ʽ)<T>/�ȽϺ���(����/�º���)> que;
//
//void test01() {
//	priority_queue<int> que;
//	que.push(6);
//	que.push(2);
//	que.push(-5);
//	que.push(0);
//	que.push(99);
//
//	cout << que.size() << endl;
//	cout << que.top() << endl;
//	que.pop();
//	cout << que.top() << endl;
//
//	while (!que.empty()) que.pop();
//	cout << que.size() << endl;
//
//	que.emplace(11);
//	que.emplace(9);
//	cout << que.top() << endl;
//
//}
//void test02() {
//	priority_queue<int,vector<int>,less<int>> que;
//	que.push(6);
//	que.push(2);
//	que.push(-5);
//	que.push(0);
//	que.push(99);
//
//	cout << que.size() << endl;
//	cout << que.top() << endl;
//	que.pop();
//	cout << que.top() << endl;
//
//	while (!que.empty()) que.pop();
//	cout << que.size() << endl;
//
//	que.emplace(11);
//	que.emplace(9);
//	cout << que.top() << endl;
//
//}
//void test03() {
//	priority_queue<int, vector<int>, greater<int>> que;
//	que.push(6);
//	que.push(2);
//	que.push(-5);
//	que.push(0);
//	que.push(99);
//
//	cout << que.size() << endl;
//	cout << que.top() << endl;
//	que.pop();
//	cout << que.top() << endl;
//
//	while (!que.empty()) que.pop();
//	cout << que.size() << endl;
//
//	que.emplace(11);
//	que.emplace(9);
//	cout << que.top() << endl;
//
//}
////���� ���������
//struct node {
//	int x, y;
//	bool operator<(const node &b) const {
//		return this->x > b.x;
//	} //û��ָ����һ��Ԫ����ȵ���� �����Զ���y���� ���ǰ�ԭ�������˳��
//};
//void test04() {
//	priority_queue<node, vector<node>, less<node>> que; //��ʵ��д�ڶ����͵�����Ҳ��������
//	que.push({5,7});
//	que.push({ 7,2 });
//	que.push({7,1});
//	que.push({0,99});
//	que.push({3,5});
//
//	cout << que.size() << endl;
//	cout << que.top().x<<" "<<que.top().y << endl;
//	que.pop();
//	cout << que.top().x << " " << que.top().y << endl;
//
//	while (!que.empty()) {
//		cout << que.top().x << " " << que.top().y << endl;
//		que.pop();
//	}
//
//	que.emplace(11);
//	que.emplace(9);
//	cout << que.top().x << " " << que.top().y << endl;
//
//}
//
//struct node1 {
//	int x, y;
//};
////���� �º���
//struct cmp {
//	bool operator() (const node1& a, const node1& b) {
//		return a.x > b.x;
//	}
//};
//void test05() {
//	priority_queue<node1, vector<node1>, cmp> que;
//	que.push({ 5,7 });
//	que.push({ 7,2 });
//	que.push({ 7,1 });
//	que.push({ 0,99 });
//	que.push({ 3,5 });
//
//	cout << que.size() << endl;
//	cout << que.top().x << " " << que.top().y << endl;
//	que.pop();
//	cout << que.top().x << " " << que.top().y << endl;
//
//	while (!que.empty()) {
//		cout << que.top().x << " " << que.top().y << endl;
//		que.pop();
//	}
//
//	que.emplace(11);
//	que.emplace(9);
//	cout << que.top().x << " " << que.top().y << endl;
//
//}
////struct node1 {
////	int x, y;
////};
////���� �ȽϺ���/lambda���� cmp//�������� ����������������������
////bool cmp (const node1& a, const node1& b) {
////		return a.x > b.x;
////}
//void test06() {
//	/*auto fun = [](const node1& a, const node1& b) {return a.x > b.x; };
//	priority_queue<node1, vector<node1>, cmp/fun> que;
//	que.push({ 5,7 });
//	que.push({ 7,2 });
//	que.push({ 7,1 });
//	que.push({ 0,99 });
//	que.push({ 3,5 });
//
//	cout << que.size() << endl;
//	cout << que.top().x << " " << que.top().y << endl;
//	que.pop();
//	cout << que.top().x << " " << que.top().y << endl;
//
//	while (!que.empty()) {
//		cout << que.top().x << " " << que.top().y << endl;
//		que.pop();
//	}
//
//	que.emplace(11);
//	que.emplace(9);
//	cout << que.top().x << " " << que.top().y << endl;*/
//
//}
//int main() {    
//
//	test04();
//	cout << "*********************" << endl;
//	test05();
//
//	return 0;
//}