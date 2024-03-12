//#include<iostream>
//#include<cstring>
//#include<queue>
//#include <map>
//#include <list>
//using namespace std;
//
//typedef pair<int, int> PII;
//
//const int N = 200010;
//
//int h[N], e[N], ne[N], idx;
//int w[N];
//int dist[N];
//bool st[N];
//
//int n, m;
//
//void add(int x, int y, int c)
//{
//    w[idx] = c;
//    e[idx] = y;
//    ne[idx] = h[x];
//    h[x] = idx++;
//}
//map<int, list<pair<int, int>>> mp;
//
//int dijkstra()
//{
//    memset(dist, 0x3f, sizeof(dist));
//    dist[1] = 0;
//    priority_queue<PII, vector<PII>, greater<PII>> heap;
//    heap.push({ 0, 1 });
//    while (heap.size())
//    {
//        PII k = heap.top();
//        heap.pop();
//        int ver = k.second, distance = k.first;
//
//        if (st[ver]) continue;
//        st[ver] = true;
//
//        // for(int i = h[ver]; i != -1; i = ne[i])
//        // {
//        //     int j = e[i];
//        //     if(dist[j] > distance + w[i])
//        //     {
//        //         dist[j] = distance + w[i];
//        //         heap.push({ dist[j], j });
//        //     }
//        // }
//
//            for (auto [j, w] : mp[ver]){
//                if (dist[j] > distance + w) {
//                    dist[j] = distance + w;
//                    heap.push({ dist[j], j });
//                }
//            }
//        
//    }
//    if (dist[n] == 0x3f3f3f3f) return -1;
//    return dist[n];
//}
//
//int main()
//{
//    //memset(h, -1, sizeof(h));
//    //scanf("%d%d", &n, &m);
//
//    //while (m--)
//    //{
//    //    int x, y, c;
//    //    scanf("%d%d%d", &x, &y, &c);
//    //    //add(x, y, c);
//    //    mp[x].push_back({ y,c });
//    //}
//
//    //cout << dijkstra() << endl;
//    list<pair<int, int>> lst(5, { 2,2 });
//    for (auto [x, y] : lst) {
//        cout << x << " " << y << endl;
//    }
//    mp[2] = lst;
//    for (auto [x, y] : mp[2]) {
//        cout << x << " " << y << endl;
//    }
//    return 0;
//}
