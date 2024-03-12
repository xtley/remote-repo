#include <bits/stdc++.h>
using namespace std;

int main()
{
    array<int,10> a1{};
    for(int i=1;i<=10;i++) a1[i-1]=i;
    for(auto x:a1) cout<<x<<endl;
    cout<<*max_element(a1.begin(),a1.end(),[](auto p1,auto p2){
        return p1>p2;
    })<<endl;
    return 0;
}
