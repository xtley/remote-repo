//#include <iostream>
//#include <list>
//#include <string.h>
//#include <algorithm>
//using namespace std;
//
////list ˫��ѭ������
//
//
//void Print(const list<int> &lst) {
//	for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++) {
//		cout << *it << " ";
//	}
//	/*for (auto x:lst) {
//		cout << x << " ";
//	}*/
//	cout << endl;
//}
////list���캯��
//void test01() {
//	//���캯��
//	// list<T> lst;
//	// list<beg,end>;
//	// list(n,elem);
//	// list(const list &lst);
//
//	list<int> lst1;
//	Print(lst1);
//	list<int> lst2(10, 8);
//	Print(lst2);
//	list<int> lst3(lst2.begin(), lst2.end());
//	Print(lst3);
//	list<int> lst4(lst3);
//	Print(lst4);
//	
//}
////list��ֵ�ͽ���
//void test02() {
//	//assign(beg,end);
//	//assign(n,elem);
//	//list& operator=(const list &lst);  //���صȺŲ�����
//	//swap(lst);  //��lst�뱾���Ԫ�ػ���
//	list<int> lst1;
//	Print(lst1);
//	list<int> lst2(10, 8);
//	Print(lst2);
//	list<int> lst3(lst2.begin(), lst2.end());
//	Print(lst3);
//	list<int> lst4(lst3);
//	Print(lst4);
//
//	list<int> lst5;
//	lst5.assign(lst2.begin(), lst2.end());
//	Print(lst5);
//	lst5.swap(lst4);
//	Print(lst5);
//
//	list<int> lst6;
//	lst6.assign(7, 9);
//	Print(lst6);
//	list<int> lst7 = lst6;
//	Print(lst7);
//}
////list��С����
//void test03() {
//	//size(); //����������Ԫ�صĸ���
//	//empty(); //�ж������Ƿ�Ϊ��
//	//resize(num); //����ָ��size Ĭ��Ϊ0
//	//resize(num,elem); //����ָ��,�� ��elem���
//	list<int> lst1;
//	Print(lst1);
//	list<int> lst2(10, 8);
//	Print(lst2);
//	list<int> lst3(lst2.begin(), lst2.end());
//	Print(lst3);
//	list<int> lst4(lst3);
//	Print(lst4);
//
//	cout << lst4.size() << endl;
//	cout << lst4.empty() << endl;
//
//	lst4.resize(18);
//	Print(lst4);
//	lst4.resize(25, 5);
//	Print(lst4);
//}
////list�����ɾ��
//void test04() {
//	//��list�����������ݵĲ����ɾ��
//	//push_back(elem);   //������β������һ��Ԫ��
//	//pop_back();    //ɾ�����������һ��Ԫ��
//	//push_front(elem);  //��������ͷ����һ��Ԫ��
//	//pop_front();    //��������ͷ�Ƴ�һ��Ԫ��
//	//insert(pos,elem);  //��posλ�ò���elemԪ�صĿ��������������ݵ�λ��
//	//insert(pos,n,elem); //��posλ�ò���n��elem���ݣ��޷���ֵ
//	//insert(pos,beg,end); //��posλ�ò���[beg,end)��������ݣ��޷���ֵ
//	//clear(); //�Ƴ���������������
//	//erase(beg,end);  //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ��
//	//erase(pos);  //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
//	///remove(elem); //ɾ��������������elemֵƥ���Ԫ��
//
//	list<int> lst;
//	//it += 5; ֻ��++ ����������ʵ�����
//	lst.push_back(11);
//	Print(lst);
//	lst.pop_back();
//	Print(lst);
//	lst.push_front(5);
//	auto it = lst.begin(); //=lst.begin() ��it++Ҫд��һ�� ��Ȼ��Խ��
//	it++; //
//	lst.push_front(14);
//	Print(lst);
//	lst.pop_back();
//	Print(lst);
//
//	lst.insert(lst.begin(), 33);
//	Print(lst);
//	lst.insert(lst.begin(), 6, 39);
//	Print(lst);
//	lst.insert(lst.begin(), lst.begin(), lst.end());
//    Print(lst);
//	//
//	list<int> lst1(lst);
//	lst1.erase(lst1.begin(), lst1.end());
//	Print(lst1);
//	lst.push_back(11);
//	lst.erase(lst.begin());
//	Print(lst);
//
//	lst.remove(33); //*****
//    Print(lst);
//
//	lst.clear();
//	Print(lst);
//
//
//}
////list ���ݴ�ȡ
//void test05() {
//	//front(); ���ص�һ��Ԫ������
//	//back(); �������һ��Ԫ������
//	list<int> lst;
//	lst.push_back(55);
//	lst.push_back(33);
//
//	cout << lst.front() << endl;
//	cout << lst.back() << endl;
//
//	lst.front() = 77;
//	lst.back() = 66;
//
//	cout << lst.front() << endl;
//	cout << lst.back() << endl;
//}
////list ��ת������
//void test06() {
//	//reverse(); //��ת����
//	//sort()  //��֧��������ʵĵ�����������������ʹ�ñ�׼�㷨 �����ڲ����в���
//
//	list<int> lst;
//	lst.push_back(1);
//	lst.push_back(3);
//	lst.push_back(7);
//	lst.push_back(5);
//	lst.push_back(2);
//	Print(lst);
//	lst.reverse();
//	Print(lst);
//	//sort(lst.begin(), lst.end()); //��֧��������� �����޷���������
//	lst.sort([](int a, int b) {return a > b; });
//	Print(lst);
//	lst.sort(less());
//	Print(lst);
//	lst.sort(greater());
//	Print(lst);
//}
////����
//void test07() {
//	//splice ����
//	//merage �ϲ�
//	//cbegin() cbegin��cend�ǲ����Ƕ������ǲ��ǳ���������ֵ����const_iterator. ��֤������
//	//remove_if(cmp); 
//	// C++ ����std::list::remove_if()���б���ɾ������������Ԫ�ء���ɾ������Ԫ�ء� cmp �����ж���
//	// �˺�������һ��ָ���޼������е����һ��Ԫ�ص�����
//	// ��ס, remove_if()������ʵ���Ƴ�����[start, end)�е�Ԫ��; �����һ��������Ӧ��remove_if(), �����ĳ��Ȳ�����ı�(remove_if()�����ܽ�ͨ���������ı�����������), ���е�Ԫ�ض�������������. ʵ��������, remove_if()������Ӧ���Ƴ���Ԫ�ض��ƶ���������β��������һ���ֽ�ĵ�����. �Ƴ�������Ԫ����Ȼ����ͨ�����صĵ��������ʵ�.
//	//  Ϊ��ʵ���Ƴ�Ԫ��, �������������е���erase()�Բ�����Ҫ�Ƴ���Ԫ��. ��Ҳ��erase-remove idiom���Ƶ�����:
//	//container.erase(remove_if(container.begin(), container.end(), pred), container.end());
//	// 
//	// ���� remove��
//	// ɾ���Զ�Ԫ�ػ�������Ԫ�أ�����Ԫ����ǰ�ƶ������������Ĵ�С�����仯�������ͻᵼ�¿ճ���λ�ñ�Ĭ����䡣����
//	// 
//	//unique(cmp)��C++ STL�е�Inbulit�������ú������б���ɾ�������ظ�������Ԫ�ء�  cmp�е���
//	//get_allocator ��ȡ������
//
//	//splice
//	//list1.splice(iterator position, list2)
//	//list1.splice(iterator position, list2, iterator i)
//	//list1.splice(iterator position, list2, iterator first, iterator last)
//	//splice���������ֺ���ǩ��������
//	//list1��ʾ��ƴ�ӵ��б������Ժ���ṹ�ᷢ���ı�(����иı�Ļ�)
//	//iterator position��ʾ������ʼʱlist1�ĵ�����λ��
//	//list2Ϊ����Ԫ��ƴ�ӵ�list1���б�
//	//iterator i��list2��Ҫƴ�ӵĵ�����Ԫ�ء�
//	//iterator first, iterator last����list2��Ҫƴ��Ԫ�صĵ�һ�������һ����
//
//	list<int> l1 = { 1, 2, 3 };
//	list<int> l2 = { 4, 5 };
//	list<int> l3 = { 6, 7, 8 };
//
//	// ��l2ȫ������l1�������λ��Ϊl1�Ŀ�ͷ
//	l1.splice(l1.begin(), l2);
//
//	cout << "list l1 after splice operation" << endl;
//	for (auto ele : l1) cout << ele << " ";
//	cout << endl;
//	cout << "list l2 after splice operation" << endl;
//	cout << "l2.size is: " << l2.size() << endl;
//
//	// ��l1ȫ������l3��ĩβ 
//	l3.splice(l3.end(), l1);
//
//	// at the end of l3 
//	cout << "list l3 after splice operation" << endl;
//	for (auto ele : l3) cout << ele << " ";
//	cout << endl;
//	//merage
//
//	list<int> list1 = { 10, 20, 30 };
//	list<int> list2 = { 40, 50, 60 };
//
//	// merge operation 
//	list2.merge(list1);
//
//	cout << "List:  ";
//
//	for (auto it = list2.begin(); it != list2.end(); ++it)
//		cout << *it << " ";
//
//	
//}
//int main() {
//	//test07();
//
//	return 0;
//}