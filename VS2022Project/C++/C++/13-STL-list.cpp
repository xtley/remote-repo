//#include <iostream>
//#include <list>
//#include <string.h>
//#include <algorithm>
//using namespace std;
//
////list 双向循环链表
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
////list构造函数
//void test01() {
//	//构造函数
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
////list赋值和交换
//void test02() {
//	//assign(beg,end);
//	//assign(n,elem);
//	//list& operator=(const list &lst);  //重载等号操作符
//	//swap(lst);  //将lst与本身的元素互换
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
////list大小操作
//void test03() {
//	//size(); //返回容器中元素的个数
//	//empty(); //判断容器是否为空
//	//resize(num); //重新指定size 默认为0
//	//resize(num,elem); //重新指定,可 以elem填充
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
////list插入和删除
//void test04() {
//	//对list容器进行数据的插入和删除
//	//push_back(elem);   //在容器尾部加入一个元素
//	//pop_back();    //删除容器中最后一个元素
//	//push_front(elem);  //在容器开头插入一个元素
//	//pop_front();    //从容器开头移除一个元素
//	//insert(pos,elem);  //在pos位置插入elem元素的拷贝，返回新数据的位置
//	//insert(pos,n,elem); //在pos位置插入n个elem数据，无返回值
//	//insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值
//	//clear(); //移除容器的所有数据
//	//erase(beg,end);  //删除[beg,end)区间的数据，返回下一个数据的位置
//	//erase(pos);  //删除pos位置的数据，返回下一个数据的位置
//	///remove(elem); //删除容器中所有与elem值匹配的元素
//
//	list<int> lst;
//	//it += 5; 只能++ 不是随机访问迭代器
//	lst.push_back(11);
//	Print(lst);
//	lst.pop_back();
//	Print(lst);
//	lst.push_front(5);
//	auto it = lst.begin(); //=lst.begin() 和it++要写在一起 不然会越界
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
////list 数据存取
//void test05() {
//	//front(); 返回第一个元素引用
//	//back(); 返回最后一个元素引用
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
////list 反转和排序
//void test06() {
//	//reverse(); //反转链表
//	//sort()  //不支持随机访问的迭代器的容器不可以使用标准算法 但是内部会有补充
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
//	//sort(lst.begin(), lst.end()); //不支持随机访问 所以无法这样排序
//	lst.sort([](int a, int b) {return a > b; });
//	Print(lst);
//	lst.sort(less());
//	Print(lst);
//	lst.sort(greater());
//	Print(lst);
//}
////补充
//void test07() {
//	//splice 连接
//	//merage 合并
//	//cbegin() cbegin和cend是不管是对象本身是不是常量，换回值都是const_iterator. 保证常量化
//	//remove_if(cmp); 
//	// C++ 函数std::list::remove_if()从列表中删除满足条件的元素。它删除所有元素。 cmp 条件判断器
//	// 此函数返回一个指向被修剪的序列的最后一个元素迭代器
//	// 记住, remove_if()并不会实际移除序列[start, end)中的元素; 如果在一个容器上应用remove_if(), 容器的长度并不会改变(remove_if()不可能仅通过迭代器改变容器的属性), 所有的元素都还在容器里面. 实际做法是, remove_if()将所有应该移除的元素都移动到了容器尾部并返回一个分界的迭代器. 移除的所有元素仍然可以通过返回的迭代器访问到.
//	//  为了实际移除元素, 你必须对容器自行调用erase()以擦除需要移除的元素. 这也是erase-remove idiom名称的由来:
//	//container.erase(remove_if(container.begin(), container.end(), pred), container.end());
//	// 
//	// 关于 remove：
//	// 删除自定元素或者区间元素，后面元素向前移动，但是容器的大小并不变化，这样就会导致空出来位置被默认填充。覆盖
//	// 
//	//unique(cmp)是C++ STL中的Inbulit函数，该函数从列表中删除所有重复的连续元素。  cmp判等器
//	//get_allocator 获取分配器
//
//	//splice
//	//list1.splice(iterator position, list2)
//	//list1.splice(iterator position, list2, iterator i)
//	//list1.splice(iterator position, list2, iterator first, iterator last)
//	//splice有以上三种函数签名，其中
//	//list1表示被拼接的列表，操作以后其结构会发生改变(如果有改变的话)
//	//iterator position表示操作开始时list1的迭代器位置
//	//list2为将其元素拼接到list1的列表。
//	//iterator i是list2中要拼接的迭代器元素。
//	//iterator first, iterator last则是list2中要拼接元素的第一个与最后一个。
//
//	list<int> l1 = { 1, 2, 3 };
//	list<int> l2 = { 4, 5 };
//	list<int> l3 = { 6, 7, 8 };
//
//	// 将l2全部加入l1，插入的位置为l1的开头
//	l1.splice(l1.begin(), l2);
//
//	cout << "list l1 after splice operation" << endl;
//	for (auto ele : l1) cout << ele << " ";
//	cout << endl;
//	cout << "list l2 after splice operation" << endl;
//	cout << "l2.size is: " << l2.size() << endl;
//
//	// 将l1全部加入l3的末尾 
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