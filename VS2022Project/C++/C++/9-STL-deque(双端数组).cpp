//#include <iostream>
//#include <algorithm>
//#include <deque>
//
//using namespace std;
//
////deque����
////deque������������
////˫�����飬���Զ�ͷ�˽��в���ɾ������
////deque��vector����
//// 
//// vector����ͷ���Ĳ���ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
//// deque��Զ��� ��ͷ���Ĳ���ɾ���ٶȱ�vector��
//// vector����Ԫ��ʱ���ٶȻᱻdeque�� ������ߵ��ڲ�ʵ���й�
//// 
//// deque�ڲ�����ԭ��:
//// deque�ڲ��и��п�����ά��ÿ�λ������е����ݣ��������д����ʵ����
//// �п���ά������ÿ���������ĵ�ַ.ʹ��ʹ��dequeʱ��һƬ�������ڴ�ռ�
//// 
//// deque�����ĵ�����Ҳ��֧��������ʵ�
//// 
//
//void Print(const deque<int> &d) {
//	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////deque���캯��
//void test01() {
//	//deque<T> deq T;  //Ĭ�Ϲ�����ʽ
//	//deque(beg,end);  //���캯����[beg,end]�����е�Ԫ�ؿ���������
//	//deque(n,elem);   //���캯����n��elem����������
//	//deque(const deque &dep); //�������캯��
//
//	deque<int> d1(10,6);
//	Print(d1);
//	deque<int> d2(d1.begin()+3,d1.end()-2);
//	Print(d2);
//	deque<int> d3(d2);
//	Print(d3);
//
//}
////deque��ֵ����
//void test02() {
//	//deque& operator=(const deque &deq);  //���صȺŲ�����
//	//assign(beg,end);    //��[beg,end]�����е����ݿ�����ֵ������
//	//assign(n,elem);    //��n��elem������ֵ������
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
////deque��С����
//void test03() {
//	//deque.empty(); //�ж������Ƿ�Ϊ��
//	//deque.size();  //����������Ԫ�صĸ���
//	//deque.resize(num); //����ָ�������ĳ���Ϊnum,��������䳤������Ĭ�������λ��
//	//                   //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
//	//deque.resize(num,elem);  //����ָ�������ĳ���Ϊnum����������䳤������elemֵ�����λ��
//	//                         //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
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
//	if (d1.empty()) cout << "deque����Ϊ��" << endl;
//}
////deque�����ɾ��
//void test04() {
//	// ���˲������
//	// push_back(elem);  //������β�����һ������
//	// push_front(elem); //������ͷ������һ������
//	// pop_back();       //ɾ���������һ��Ԫ��
//	// pop_front();      //ɾ��������һ��Ԫ��
//	// 
//	// ָ��λ�ò���:
//	// ע�������pos�ǵ�����
//	// insert(pos,elem); //��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ��  ����һ��������ʵ���������ָ�����ɾ��Ԫ�ص�λ�á�
//	// insert(pos,n,elem); //��posλ�ò���n��elem���ݣ��޷���ֵ
//	// insert(pos,beg,end); //��posλ�ò���[beg,end) ��������ݣ��޷���ֵ
//	// clear();   //�����������������
//	// erase(beg,end); //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�� ����һ��������ʵ���������ָ�����ɾ��Ԫ�ص�λ�á�
//	// erase(pos);     //ɾ��posλ�õ����� ������һ�����ݵ�λ�� ����һ��������ʵ���������ָ�����ɾ��Ԫ�ص�λ�á�
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
//	d1.insert(d1.begin()+3, d1.begin(), d1.end()); //**** �����������ǵ�����
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
////deque���ݴ�ȡ
//void test05() {
//	//at(int idx);  //��������idx��������
//	//operator[];   //��������idx��������
//	//front();    //���������е�һ��Ԫ�ص�����
//	//back();    //����Ԫ�������һ��Ԫ�ص�����
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
////deque�������� ����֧��������ʵĵ�����������ʹ��sort��������
//void test06() {
//	deque<int> d1;
//	for (int i = 15; i > 0; i--) {
//		d1.push_back(i);
//	}
//	Print(d1);
//	sort(d1.begin(), d1.end());
//	Print(d1);
//}
//// ����  emplace() ����
//void test07() {
//    //emplace  c++11 ԭλ����Ԫ��
//	//iterator emplace(const_iterator position, value_type val);
//	// position:��������Ҫ������Ԫ�ص�λ�á�
//    // val:Ҫ�������ֵ��
//	// ����ֵ���������������ص��¹����Ԫ�ء�
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