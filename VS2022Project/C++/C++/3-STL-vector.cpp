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
//// �����洢int
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
//	//STL��߱����㷨  ���ûص��ļ���
//	cout << endl;
//	for_each(v.begin(), v.end(), Print);
//
//	//���auto���ķ���
//	cout << endl;
//	for (auto x : v) {
//		cout << x << endl;
//	}
//}
////�����洢�Զ�����������
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
////�����洢�Զ�����������
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
////����Ƕ������
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
////vector ���캯��
////vector ��̬��չ
////��������ԭ�������¿ռ� ����Ѱ�Ҹ�����ڴ�ռ� Ȼ��ԭ���ݿ����¿ռ� �ͷ�ԭ�ռ�
//void test05() {
//	//vector<T> v; �޲�Ĭ�Ϲ��캯��
//	//vector(v.begin(),v.end()>); ��v[begin(),end()]֮��Ԫ�ؿ���������
//	//vector(n,elem); ���캯����n��elem����������
//	//vector<const vector &vec>; //�������캯��
//
//	vector<int> v1; //Ĭ�Ϲ��� �޲ι���
//
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//
//	for (auto x : v1) cout << x << " ";
//	cout << endl;
//	//ͨ�����䷽ʽ���й���
//	vector<int> v2(v1.begin(), v1.end());
//	for (auto x : v2) cout << x << " ";
//	cout << endl;
//
//	//ͨ��n��elem����
//	vector<int> v3(10,100);
//	for (auto x : v3) cout << x << " ";
//	cout << endl;
//
//	//ͨ���������캯������
//	vector<int> v4(v3);
//	for (auto x : v4) cout << x << " ";
//	cout << endl;
//}
////vector ��ֵ����
//void test06() {
//    //vector ��ֵ����
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	for (auto x : v1) cout << x << " ";
//	cout << endl;
//
//	//��ֵ operator=
//	vector<int> v2;
//	v2 = v1;
//	for (auto x : v2) cout << x << " ";
//	cout << endl;
//
//	//��ֵ aggign
//	vector<int> v3;
//	v3.assign(v1.begin(), v1.end());
//	for (auto x : v2) cout << x << " ";
//	cout << endl;
//
//	//��ֵ aggign n����ʽ
//	vector<int> v4;
//	v4.assign(10, 100);
//	for (auto x : v4) cout << x << " ";
//	cout << endl;
//
//	//��ֵ aggign n����ʽ {}
//	vector<int> v5;
//	v5.assign({1,2,3,4});
//	for (auto x : v5) cout << x << " ";
//	cout << endl;
//
//	cout << v1.capacity() << endl;
//	cout << v1.size() << endl;
//	//ʹ�� aggignΪԭvector��ֵ ��ֱ�Ӹ��ǵ�ԭ��������Ԫ�� �������·���ռ� ���Ǵ�Сcapacity����ı�size��ı�
//	v1.assign({ 1 });
//	for (auto x : v1) cout << x << " ";
//	cout << endl;
//	cout << v1.capacity() << endl;
//	cout << v1.size ()<< endl;
//
//}
////vector�����ʹ�С
//void test07() {
//	//vector�����ʹ�С
//
//	//empty(); �Ƿ�Ϊ�� Ϊ�շ���true
//	//capacity(); ����������
//	//size();  ����������Ԫ�صĸ���
//	//resize(int num); ����ָ�������ĳ���Ϊnum ��������䳤����Ĭ��ֵ�����λ��
//	                   //���������� ��ĩβ�����������ȵ�Ԫ�ر�ɾ��
//	//resize(int num,elem)  ����ָ�������ĳ���Ϊnum ��������䳤����elem�����λ��
//	                   //���������� ��ĩβ�����������ȵ�Ԫ�ر�ɾ��
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	for (auto x:v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	if (v1.empty()) cout << "v1Ϊ��" << endl;
//	else {
//		cout << "v1��Ϊ��" << endl;
//		cout << "v1������Ϊ��" << v1.capacity() << endl;
//		cout << "v1�Ĵ�СΪ��" << v1.size() << endl;
//	}
//
//	//����ָ����С
//	v1.resize(15,100);
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	if (v1.empty()) cout << "v1Ϊ��" << endl;
//	else {
//		cout << "v1��Ϊ��" << endl;
//		cout << "v1������Ϊ��" << v1.capacity() << endl;
//		cout << "v1�Ĵ�СΪ��" << v1.size() << endl;
//	}
//
//	//����ָ����С
//	v1.resize(5);
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	if (v1.empty()) cout << "v1Ϊ��" << endl;
//	else {
//		cout << "v1��Ϊ��" << endl;
//		cout << "v1������Ϊ��" << v1.capacity() << endl;
//		cout << "v1�Ĵ�СΪ��" << v1.size() << endl;
//	}
//	
//}
////vector�����ɾ��
//void test08() {
//	//vector�����ɾ��
//	
//	//push_back(elem)  //β������Ԫ�� ele
//	//pop_back();     //ɾ�����һ��Ԫ��
//	//insert(const_iterator pos,elem ); ������ָ��λ��pos����Ԫ��elem
//	//insert(const_iterator pos,int count,elem); ������ָ��λ��pos����count��Ԫ��elem
//	//erase(const_iterator pos); ɾ��������ָ���Ԫ��
//	//erase(const_iterator start,const_iterator end); //ɾ����������start��end֮���Ԫ��
//	//clear(); //ɾ������������Ԫ�� size��Ϊ0 ����capacity����ı�
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
//	v1.insert(v1.begin()+1, 5); //���뵽������λ�õ�ǰ��
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v1.insert(v1.begin() + 1, 3,5); //��3����������λ�õ�ǰ��
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v1.erase(v1.begin()); //ɾ��������ָ����Ԫ��
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl;
//
//	v1.erase(v1.begin()+1,v1.end()-3); //ɾ�������������ڵ�Ԫ��
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
////vector ���ݲ�ȡ
//void test09() {
//	//vector ���ݲ�ȡ
//
//	//at(int idx); ��������idx��ָ������ ����
//	//operator[]    
//	//front()   ���������е�һ������Ԫ�� ����
//	//back      ����Ԫ�������һ��Ԫ�� 
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
////vector ��������
//void test10() {
//	//vector ��������
//	//ʵ������������Ԫ�ؽ��л���
//
//	//swap(vec) ��vec�뱾��Ԫ�ػ��� ������Ϣ����
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
//	cout << "����:" << endl;
//	for (auto x : v1) {
//		cout << x << " ";
//	}
//	cout << endl << endl;
//
//	cout << "v2:" << endl;
//	cout << "capacity:" << v2.capacity() << endl;
//	cout << "size:" << v2.size() << endl;
//	cout << "����:" << endl;
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
//	cout << "����:" << endl;
//	for (auto x:v1) {
//		cout << x << " ";
//	}
//	cout << endl<<endl;
//
//	cout << "v2:" << endl;
//	cout << "capacity:" << v2.capacity() << endl;
//	cout << "size:" << v2.size() << endl;
//	cout << "����:" << endl;
//	for (auto x : v2) {
//		cout << x << " ";
//	}
//	cout << endl<<endl;
//
//
//	//ʵ����; ����swap���������ڴ�ռ�
//
//	vector<int> v;
//	for (int i = 0; i < 100000; i++) {
//		v.push_back(i);
//	}
//	cout << "v������:" << v.capacity() << endl;
//	cout << "v�Ĵ�С:" << v.size() << endl;
//
//	v.resize(3); //����ָ����С
//	cout << "v������:" << v.capacity() << endl; //����û�б仯 �˷���
//	cout << "v�Ĵ�С:" << v.size() << endl << endl;
//
//	//����swap�����ڴ�
//	vector<int>(v).swap(v);  
//	//vector<int>(v); ���ÿ������캯��������������
//	//���������󻥻� Ȼ��ԭ����������Ϊ�����������н���֮��ԭ����ռ�þ���ʧ��
//	cout << "v������:" << v.capacity() << endl; //�����仯 �ڴ濪������
//	cout << "v�Ĵ�С:" << v.size() << endl;
//}
////vectorԤ���ռ�
//void test11() {
//	//vectorԤ���ռ�
//	//����vector�ڶ�̬��չ�ǵ���չ���� ���һ��ʼ֪����ֱ��Ԥ�� ����Ҫ�����ȥ����
//
//	//����ԭ��
//	//reserve(int len);  //����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���
//	//����ı� size len��������ص�capacityС�Ļ�������չ ����capacity��չ��len
//
//	//ͳ�ƿ��ٹ�������չ�˶��ٴ��ڴ�
//
//	vector<int> v;
//	int num = 0;
//	int* p = NULL;
//
//	int num2 = 0;
//	int p2 = 0;
//	for (int i = 0; i < 100000; i++) { //�ռ���չ�׵�ַ��ı�
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
////���� reverse ��ת����
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