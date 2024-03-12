#include <cstdio>
#include <cmath>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define buff                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long 
#define pll pair<ll,ll>
#define p_b push_back
#define endl "\n"
#define rep(i,l,r) for(auto i= (l); i<= (r); i++)
#define per(i,r,l) for(auto i= (r); i>= (l); i--)
#define len(l,r)  (r-l+1LL)
#define sum(l,r) (sum[r]-sum[l-1])
#define sum1(l,r) (sum1[r]-sum1[l-1])
#define sum2(l,r) (sum2[r]-sum2[l-1])
#define suml(l,r) (suml[r]-suml[l-1])
#define sumr(l,r) (sumr[r]-sumr[l-1])
#define suma(l,r) (suma[r]-suma[l-1])
#define sumb(l,r) (sumb[r]-sumb[l-1])
#define prc(c) cout<<#c<<":"<<c<<"\n";
#define pr(ve)  cout<<#ve<<'\n';for(auto x:ve)cout<<x<<" ";cout<<'\n'<<#ve<<" end\n"; 
#define prp(ve) cout<<#ve<<'\n';for(auto x:ve)cout<<"["<<x.first<<","<<x.second<<"]\n";cout<<#ve<<" end\n"; 
using namespace std;
const ll N=1e6+10;
const ll mod=1e9+7;
ll ksm(ll n,ll p,int mod){
    int ans=1; 
    while(p){ 
        if(p&1) ans=(ans*n)%mod; 
        n=(n*n)%mod;
        p>>=1;
    }
    return ans;
}
ll inv(ll b,ll c=mod) {
	return ksm(b,c-2,c);
}
class Num{
public:
	ll num;
	Num(ll x) {
		num=x%mod;
	}
	Num operator+(Num p) {
		return Num((num+p.num)%mod);
	}
	Num operator-(Num p) {
		return Num((num-p.num+mod)%mod);
	}
	Num operator*(Num p) {
		return Num((num*p.num)%mod);
	}
	Num operator/(Num p) {
		return Num((num*inv(p.num))%mod);
	}
	Num operator=(Num p) {
		this->num=p.num;
		return *this;
	}
	friend ll get(Num p) {
		return p.num;
	}
};
void init_solve() {
	
}
void solve() {
	
	
	
	
	



	
	
	
	
	
}
int main() {
	buff
	ll T=1;
	cin>>T;
	while(T--) {
		
        init_solve();
		solve();
	}
	        
	return 0;
}