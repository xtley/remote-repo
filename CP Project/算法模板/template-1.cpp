#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
const int N=2e5+10;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
// 原则 不使用 endl 使用 "\n"
ll ksm(ll n,ll p,int mod){
	ll ans=1;
	while(p){	
		if(p&1) ans=(ans*n)%mod;
		n=(n*n)%mod;p>>=1;
	}
	return ans;
}
ll inv(ll b,ll c=mod) {return ksm(b,c-2,c);}
class Num{
public:
	ll num;
	Num(ll x) {num=(x%mod+mod)%mod;}
	Num operator+(Num p) {return Num(num+p.num);}
	Num operator-(Num p) {return Num(num-p.num);}
	Num operator*(Num p) {return Num(num*p.num);}
	Num operator/(Num p) {return Num(num*inv(p.num));}
	Num operator=(Num p) {this->num=p.num;return *this;}
	friend ll get(Num p) {return p.num;}
};
void solve() {
	
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);std::cout.tie(nullptr);
    int T=1;
    //cin>>T;
    while(T--) {
    	solve();
    }
    return 0;
}