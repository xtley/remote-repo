//#include <iostream>
//#include <string>
//using namespace std;
//
////string 容器 是c++风格字符串 本质是一个类
//
////string和 char* 区别
////char 是一个指针
////string是一个类 类内部封装了char* 管理这个字符串 是一个char*型的容器
////特点
////string内部封装了很多成员方法
////例如 查找find 拷贝copy 删除delete 替换replace 插入insert 
////string管理char*所分配的内存 不用担心复制越界和取值越界等 由内部进行负责
//
////string构造函数
//void test01() {
//	//构造函数原型 
//	//string()    //创建一个空字符串 例如 string str;
//	//string(const char* s); //使用字符串s初始化
//	//string(const string& str);//使用一个string对象初始化另一个string对象
//	//string(int a,char c);   //使用n个字符c初始化
//
//	const char* str = "hello world";
//	char s[] = "hello world";
//	string s1;  //默认构造
//	string s2("666"); //利用char* 拷贝构造
//	string s21(str); //利用char* 拷贝构造
//	string s22(s); //利用char* 拷贝构造
//	string s3(s2); //利用string拷贝构造
//	string s4(6, '6'); //n个字符c初始化构造
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s21 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//
//
//}
////string赋值操作
//void test02() {
//	//string& operator=(const char* s);   //char*类型字符串 赋值给当前的字符串
//	//string& operator=(const string &s); //把字符串s赋给当前的字符串
//	//string& operator=(char c);          //字符赋值给当前的字符串
//	//string& assign(const char *s);      //把字符s赋给当前的字符串
//	//string& assign(const char *s,int n); //把字符串s的前n个字符赋给当前的字符串
//	//string& assign(const string &s);     //把字符串s赋给当前字符串
//	//string& assign(int n,char c);        //用n个字符c赋给当前字符串
//
//	char c = '4';
//	char cs[5] = "666";
//	string s = "777";
//
//	string s1 = cs;
//	string s2 = "555";
//	string s3 = s2;
//	//string s4 = '4'; //不可以定义时赋值 string& operator=(char c);
//	string s4;   //先定义再赋值
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
////string字符串拼接
//void test03() {
//	//string& operator+=(const char* str);    //重载+=操作符
//	//string& operator+=(const char c);      //重载+=操作符
//	//string& operator+=(const string& str); //重载+=操作符
//	//string& append(const char *s);         //把字符串s连接到当前字符串结尾
//	//截取...之前的*****//string& append(const char *s,int n);  //把字符串s的前n个字符连接到当前字符串结尾
//	//string& append(const char *s,intpos,int n); //字符串s中从pos开始的n个字符连接到字符串结尾
//	//string& append(const string &s);      //同operator+=(const string &str);
//	//截取..以后的*****//string& append(const string &s,int n);  //把字符串s从第n个字符开始连接到当前字符串结尾
//	//string& append(const string &s,int pos,int n); //字符串s中从pos开始的n个字符连接到字符串结尾
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
////string查找和替换
//void test04() {
//    //找不到返回极大值
//	//int find(const string& str,int pos=0) const;  //查找str第一次出现位置,从pos开始查找
//	//int find(const char* s,int pos=0) const;      //查找s第一次出现位置，从pos开始查找
//	//int find(const char*s,int pos,int n) const;   //从pos位置查找s的前n个字符第一次位置
//	//int find(const char c,int pos=0) const;      //查找字符c第一次出现位置
//	//int rfind(const string& str,int pos = npos) const;  //查找str最后一次出现位置，从pos开始查找
//	//int rfind(const char*s,int pos=npos) const;        //查找s最后一次出现位置,从pos开始查找
//	//int rfind(const char* s,int pos,int n) const;     //从pos查找s的前n个字符最后一次位置
//	//int rfind(const char c,int pos=0) const;         //查找字符c最后一次出现位置
//	//string& replace(int pos,int n,const string& str);  //替换从pos开始n个字符为字符串str
//	//string& replace(int pos,int n,const char* s);      //替换从pos开始的n个字符为字符串s
//
//	string s = "apapenpenda";
//	string ss = "pen";
//	char cs[] = "appe";
//	char cs1[] = "pen";
//	cout << s.find(ss) << endl;
//	cout << s.find(ss,3) << endl;
//
//	cout << s.find(cs,1,2) << endl; //三个参数只能第一个是char*
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
//	cout << s << endl;  //s也被替换了 通知又可以返回替换过的string
//	char cts[] = "22";
//	string str1 = s.replace(2, 4, cts);
//	cout << str1 << endl;
//
//}
////字符串比较
//void test05() {
//	//字符串比较是按字符的ASCLL码进行对比 一个一个进行比较 与长度无关
//	// = 返回 0
//	// > 返回 1
//	// < 返回 -1
//	//int compare(const string &s) const; //与字符串s比较
//	//int compare(const char *s) const;   //与字符串s比较
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
////字符存取
//void test06() {
//	//string 中单个字符采取方式有两种
//	//char& operator[](int n) //通过[方式取字符] 返回引用
//	//char& at(int n);    //通过at方法回去字符  返回引用
//
//	string s = "aaaaa";
//	s[0] = 'b';
//	s.at(1) = 'b';
//	cout << s << endl;
//
//}
////string插入和删除
//void test07() {
//	//对string字符串进行插入和删除字符操作
//	//string& insert(int pos,const char* s);    //插入字符串
//	//string& insert(int pos,const string& str);  //插入字符串
//	//string& insert(int pos,int n,char c);      //在指定位置插入n个字符c
//	//string& erase(int pos,int n=npos);       //删除从pos开始的n个字符
//	//int empty(); 为空返回1 非空返回0 
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
//	//s.insert(2, 5, "666"); //不可以这样使用
//
//	s.erase(0, 2);
//	cout << s << endl;
//	s.erase(0);
//	cout << s << endl;  //看来默认的npos为size
//	cout << s.empty() << endl;  //判空
//}
////string子串获取
//void test08() {
//
//	//函数原型
//	//string substr(int pos=0,int n= npos) const; //返回由pos开始的n个字符组成的字符串
//	//可以利用find 截取首尾有要求的子字符串
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