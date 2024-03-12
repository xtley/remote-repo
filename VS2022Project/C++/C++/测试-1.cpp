#include <iostream>
using namespace std;
#define ll long long
const int N = 1000000 + 5;
const ll mod = 998244353;
ll jc[2000000];
int inv[N];
void init()
{
    inv[1] = 1;
    for (int i = 2; i < N; i++)
        inv[i] = (mod - mod / i) * 1ll * inv[mod % i] % mod;
}
int main() {
    ll n;
    cin >> n;
    jc[0] = 1;
    for (ll i = 1; i <= n; i++) {
        jc[i - 1] %= mod;
        jc[i] = (jc[i - 1] * i) % mod;
    }
    init();
    ll ans = 0;
    for (ll len = 3; len <= n; len++) {
        ans +=(n - len + 1) * jc[n - 2] / jc[n - len] * (len - 1) * len;
    }
    ans = (ans % mod) * 2;
    cout << ans;

    return 0;
}