//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <map>
//using namespace std;
//
//map<int,int> dtgh(int n,int &ans) {
//    int lq[4] = { 1,2,5,10 };
//    int dp[30000];
//    vector<map<int, int> >ve(n+1);
//    for (int i = 0; i < n + 1; i++) dp[i] = n + 1;
//    dp[0] = 0;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            if (lq[j] <= i&&dp[i]>=dp[i-lq[j]]+1) {
//                dp[i] = dp[i - lq[j]] + 1;
//                map<int, int> mp = ve[i - lq[j]];
//                mp[lq[j]]++;
//                ve[i] = mp;
//            }
//        }
//    }
//    ans = dp[n];
//    return ve[n];
//}
//
//int main() {
//
//
//    for (int i = 23; i <= 107; i+=15) {
//        int n, ans;
//        n = i;
//        map<int, int> mp = dtgh(n, ans);
//        cout << "�ճ����Ϊ��" << n << "��Ǯ," << "������Ҫ��" << ans << "�ų�Ʊ" << endl;
//        cout << "��Ҫ�ĳ�Ʊ������£�" << endl;
//        for (auto [x, y] : mp) {
//            cout <<"��Ҫ���Ϊ" <<x<<"�ĳ�Ʊ��" <<y<<"��"<< endl;
//        }
//        cout << endl;
//    }
//    
//    return 0;
//}