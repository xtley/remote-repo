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
//        cout << "�ճ����Ϊ��" << n << "��Ǯ," << "������Ҫ��" << ans << "�ų�Ʊ" << endl;
//        cout << "��Ҫ�ĳ�Ʊ������£�" << endl;
//        for (auto [x, y] : mp) {
//            if (y)
//                cout << "��Ҫ���Ϊ" << x << "�ĳ�Ʊ��" << y << "��" << endl;
//        }
//        cout << endl;
//    }
//    return 0;
//}