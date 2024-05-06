# 逆元

## 1 满足条件
设b在模c意义下的逆元为$inv(b)$则有:

(1) $ gcd(b,c)=1$  $ 逆元存在的条件 $
    
(2) $ (a/b) \bmod c=a*inv(b)\bmod c $

(3) $ b*inv(b)\bmod c =1$

## 2 求解方法

(1)当c为质数时

由费马小定理: $a^{b-1} \bmod b=1$ (b为质数，且a,b互质)

则 $inv(b)=PowMod(b,c-2,c)$

### 代码

```c++
typedef long long ll;
ll ksm(ll n,ll p,ll mod){
    ll ans=1; 
    while(p){ 
        if(p&1) ans=((ans%mod)*(n%mod))%mod; 
        n=((n%mod)*(n%mod))%mod;
        p>>=1;
    }
    return (ans%mod+mod)%mod;
}
ll inv(ll b,ll c){
   return ksm(b,c-2,c);
}
```

### (2)任意情况下

由扩展欧几里得算法:
$ 则 a*x+b*y=gcd(a,b) 及 $b*inv(b)\bmod c=1$

$ a*b+b*y=1 $,

$ b*inv(b)-k*c=1 $,

$ b*inv(b)+c*(-k)=1 $,

$ a*x+b*y=1 $,

设 $ a=b$,$inv(b)=x$,$b=c$,$y=-k $
### 代码

```c++
typedef long long ll;
ll exgcd(ll a,ll b,ll& x,ll& y){
    if(!b) {x=1,y=0;return a;}
    ll d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}
ll inv(ll b,ll c){
   ll x,y;
   exgcd(b,c,x,y);
   return x;
}
```

## 3 递归/递推求逆元

## 4 离线求逆元
