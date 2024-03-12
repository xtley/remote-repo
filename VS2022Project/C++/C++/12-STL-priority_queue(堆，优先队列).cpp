//#include <iostream>
//#include <queue>
//
//using namespace std;
//
////优先队列  priority_queue
////在C++的容器库<queue>中已经实现好了优先队列这种结构
//// priority_queue<int> que; 定义一个存储整数类型的优先队列 数值越大，优先级越高(大根堆)
//// 
//// 优先队列像普通队列一样，可以任意插入元素
//// 每个元素拥有特定的优先级，出队时按照优先级从大到小出队
//// 在优先队列非空时，可以(只能)获取优先级最高的元素
//// 优先队列一般使用堆来实现
//// 
//// 优先队列que的操作
//// que.size();   //返回优先队列中元素数量 常数复杂度
//// que.push(x);  //将元素x插入优先队列 对数复杂度
//// que.pop();    //将优先级最高的元素出队 对数复杂度
//// que.top();    //返回优先级最高的元素 常数复杂度
//// que.empty();  //判断优先队列是否为空 常数复杂度
//// que.emplace(elem); //原位构造函数
//// 优先队列定义
//// priority_queue<int> que;
//// priority_queue <T,vector<T>,(排序方式)<T>/比较函数(重载/仿函数)> que;
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
////排序 重载运算符
//struct node {
//	int x, y;
//	bool operator<(const node &b) const {
//		return this->x > b.x;
//	} //没有指定第一个元素相等的情况 不会自动对y排序 而是按原来进入的顺序
//};
//void test04() {
//	priority_queue<node, vector<node>, less<node>> que; //其实不写第二个和第三个也可以运行
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
////排序 仿函数
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
////排序 比较函数/lambda函数 cmp//不可以用 第三个参数必须是类型名
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