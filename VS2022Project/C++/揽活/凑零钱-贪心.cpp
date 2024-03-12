//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <map>
//using namespace std;
//
//map<int, int> mp;
//void dfs(int lq[], int n, int cnt, int idx, int& ans, map<int, int> mmp) {
//    if (n == 0) {
//        if (ans > cnt) {
//            ans = cnt;
//            mp = mmp;
//        }
//        return;
//    }
//    if (idx == 4) return;
//    for (int k = n / lq[idx]; k >= 0 && k + cnt < ans; k--) {
//        mmp[lq[idx]] += k;
//        dfs(lq, n - k * lq[idx], cnt + k, idx + 1, ans, mmp);
//        mmp[lq[idx]] -= k;
//    }
//}
//
//int main() {
//    int lq[4] = { 1,2,5,10 };
//    sort(lq, lq + 4, [](int a, int b) {return a > b; });
//
//
//    for (int i = 23; i <= 107; i += 15) {
//        mp.clear();
//        int n;
//        n = i;
//        int ans = n + 1;
//        map<int, int> mmp;
//        dfs(lq, n, 0, 0, ans, mmp);
//        cout << "凑出金额为：" << n << "的钱," << "最少需要：" << ans << "张钞票" << endl;
//        cout << "需要的钞票情况如下：" << endl;
//        for (auto [x, y] : mp) {
//            if (y)
//                cout << "需要金额为" << x << "的钞票，" << y << "张" << endl;
//        }
//        cout << endl;
//    }
//    return 0;
//}