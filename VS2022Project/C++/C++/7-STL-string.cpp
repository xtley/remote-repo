//#include <iostream>
//#include <string>
//using namespace std;
//
////string ���� ��c++����ַ��� ������һ����
//
////string�� char* ����
////char ��һ��ָ��
////string��һ���� ���ڲ���װ��char* ��������ַ��� ��һ��char*�͵�����
////�ص�
////string�ڲ���װ�˺ܶ��Ա����
////���� ����find ����copy ɾ��delete �滻replace ����insert 
////string����char*��������ڴ� ���õ��ĸ���Խ���ȡֵԽ��� ���ڲ����и���
//
////string���캯��
//void test01() {
//	//���캯��ԭ�� 
//	//string()    //����һ�����ַ��� ���� string str;
//	//string(const char* s); //ʹ���ַ���s��ʼ��
//	//string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
//	//string(int a,char c);   //ʹ��n���ַ�c��ʼ��
//
//	const char* str = "hello world";
//	char s[] = "hello world";
//	string s1;  //Ĭ�Ϲ���
//	string s2("666"); //����char* ��������
//	string s21(str); //����char* ��������
//	string s22(s); //����char* ��������
//	string s3(s2); //����string��������
//	string s4(6, '6'); //n���ַ�c��ʼ������
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s21 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//
//
//}
////string��ֵ����
//void test02() {
//	//string& operator=(const char* s);   //char*�����ַ��� ��ֵ����ǰ���ַ���
//	//string& operator=(const string &s); //���ַ���s������ǰ���ַ���
//	//string& operator=(char c);          //�ַ���ֵ����ǰ���ַ���
//	//string& assign(const char *s);      //���ַ�s������ǰ���ַ���
//	//string& assign(const char *s,int n); //���ַ���s��ǰn���ַ�������ǰ���ַ���
//	//string& assign(const string &s);     //���ַ���s������ǰ�ַ���
//	//string& assign(int n,char c);        //��n���ַ�c������ǰ�ַ���
//
//	char c = '4';
//	char cs[5] = "666";
//	string s = "777";
//
//	string s1 = cs;
//	string s2 = "555";
//	string s3 = s2;
//	//string s4 = '4'; //�����Զ���ʱ��ֵ string& operator=(char c);
//	string s4;   //�ȶ����ٸ�ֵ
//	s4= '4'; //operator =
//	s4 = c;
//
//	string s5;
//	s5.assign(cs);
//	string s6;
//	s6.assign(cs, 2);
//	string s7;
//	s7.assign(s);
//	string s8;
//	s8.assign(8, '8');
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//	cout << s6 << endl;
//	cout << s7 << endl;
//	cout << s8 << endl;
//}
////string�ַ���ƴ��
//void test03() {
//	//string& operator+=(const char* str);    //����+=������
//	//string& operator+=(const char c);      //����+=������
//	//string& operator+=(const string& str); //����+=������
//	//string& append(const char *s);         //���ַ���s���ӵ���ǰ�ַ�����β
//	//��ȡ...֮ǰ��*****//string& append(const char *s,int n);  //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
//	//string& append(const char *s,intpos,int n); //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
//	//string& append(const string &s);      //ͬoperator+=(const string &str);
//	//��ȡ..�Ժ��*****//string& append(const string &s,int n);  //���ַ���s�ӵ�n���ַ���ʼ���ӵ���ǰ�ַ�����β
//	//string& append(const string &s,int pos,int n); //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
//
//	char cs[4] = "678";
//	char c = '7';
//	string s="005299";
//
//	string s1="00";
//	s1 += cs;
//	string s2 = "00";
//	s2 += c;
//	string s3 = "00";
//	s3 += s;
//	string s4;
//	s4.append(cs);
//	string s5;
//	s5.append(cs, 2);
//	string s6;
//	s6.append(cs, 1,3);
//	string s7;
//	s7.append(s);
//	string s8;
//	s8.append(s,2);
//	string s9;
//	s9.append(s,1,3);
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//	cout << s6 << endl;
//	cout << s7 << endl;
//	cout << s8 << endl;
//	cout << s9 << endl;
//
//
//}
////string���Һ��滻
//void test04() {
//    //�Ҳ������ؼ���ֵ
//	//int find(const string& str,int pos=0) const;  //����str��һ�γ���λ��,��pos��ʼ����
//	//int find(const char* s,int pos=0) const;      //����s��һ�γ���λ�ã���pos��ʼ����
//	//int find(const char*s,int pos,int n) const;   //��posλ�ò���s��ǰn���ַ���һ��λ��
//	//int find(const char c,int pos=0) const;      //�����ַ�c��һ�γ���λ��
//	//int rfind(const string& str,int pos = npos) const;  //����str���һ�γ���λ�ã���pos��ʼ����
//	//int rfind(const char*s,int pos=npos) const;        //����s���һ�γ���λ��,��pos��ʼ����
//	//int rfind(const char* s,int pos,int n) const;     //��pos����s��ǰn���ַ����һ��λ��
//	//int rfind(const char c,int pos=0) const;         //�����ַ�c���һ�γ���λ��
//	//string& replace(int pos,int n,const string& str);  //�滻��pos��ʼn���ַ�Ϊ�ַ���str
//	//string& replace(int pos,int n,const char* s);      //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
//
//	string s = "apapenpenda";
//	string ss = "pen";
//	char cs[] = "appe";
//	char cs1[] = "pen";
//	cout << s.find(ss) << endl;
//	cout << s.find(ss,3) << endl;
//
//	cout << s.find(cs,1,2) << endl; //��������ֻ�ܵ�һ����char*
//	cout << s.find('p') << endl;
//
//	cout << s.rfind(ss) << endl;
//	cout << s.rfind(ss, 7) << endl;
//
//	cout << s.rfind(cs, 1, 2) << endl; 
//	cout << s.rfind('p') << endl;
//
//	string ts = "11";
//	string str=s.replace(2,4,ts);
//	cout << str << endl;
//	cout << s << endl;  //sҲ���滻�� ֪ͨ�ֿ��Է����滻����string
//	char cts[] = "22";
//	string str1 = s.replace(2, 4, cts);
//	cout << str1 << endl;
//
//}
////�ַ����Ƚ�
//void test05() {
//	//�ַ����Ƚ��ǰ��ַ���ASCLL����жԱ� һ��һ�����бȽ� �볤���޹�
//	// = ���� 0
//	// > ���� 1
//	// < ���� -1
//	//int compare(const string &s) const; //���ַ���s�Ƚ�
//	//int compare(const char *s) const;   //���ַ���s�Ƚ�
//
//	string s1 = "abca";
//	string s2 = "ABC";
//	string s3 = "bbc";
//
//	char cs1[] = "afg";
//
//	cout << s1.compare(s2) << endl; //A 65 a97
//	cout << s1.compare("ABCA") << endl;
//	cout << s1.compare(s3) << endl;
//	cout << s1.compare(cs1) << endl;
//
//	cout << (s1 > s2) << endl;
//	cout << (s1 > "ABCA") << endl;
//	cout << (s1 > s3) << endl;
//	cout << (s1 > cs1) << endl;
//}
////�ַ���ȡ
//void test06() {
//	//string �е����ַ���ȡ��ʽ������
//	//char& operator[](int n) //ͨ��[��ʽȡ�ַ�] ��������
//	//char& at(int n);    //ͨ��at������ȥ�ַ�  ��������
//
//	string s = "aaaaa";
//	s[0] = 'b';
//	s.at(1) = 'b';
//	cout << s << endl;
//
//}
////string�����ɾ��
//void test07() {
//	//��string�ַ������в����ɾ���ַ�����
//	//string& insert(int pos,const char* s);    //�����ַ���
//	//string& insert(int pos,const string& str);  //�����ַ���
//	//string& insert(int pos,int n,char c);      //��ָ��λ�ò���n���ַ�c
//	//string& erase(int pos,int n=npos);       //ɾ����pos��ʼ��n���ַ�
//	//int empty(); Ϊ�շ���1 �ǿշ���0 
//	string s = "aaaaa";
//	string s1 = "555";
//	char cs1[] = "555";
//	s.insert(2, "555");
//	cout << s << endl;
//	s.insert(2, cs1);
//	cout << s << endl;
//	s.insert(2, s1);
//	cout << s << endl;
//	s.insert(2, 5, 'c');
//	cout << s << endl;
//	
//	//s.insert(2, 5, "666"); //����������ʹ��
//
//	s.erase(0, 2);
//	cout << s << endl;
//	s.erase(0);
//	cout << s << endl;  //����Ĭ�ϵ�nposΪsize
//	cout << s.empty() << endl;  //�п�
//}
////string�Ӵ���ȡ
//void test08() {
//
//	//����ԭ��
//	//string substr(int pos=0,int n= npos) const; //������pos��ʼ��n���ַ���ɵ��ַ���
//	//��������find ��ȡ��β��Ҫ������ַ���
//	string s = "555566";
//	cout << s.substr(0) << endl;
//	cout << s.substr(1,5) << endl;
//}
//int main() {
//	//test08();
//	
//	
//
//	return 0;
//}