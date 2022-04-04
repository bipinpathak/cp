#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll ask(vector<ll> &a) {
    cout<<'?';
    for(auto &i : a) {
        cout<<" "<<i;
    }
    cout<<endl;
    ll res=0;
    cin>>res;
    return res;
}

void solve() {
    int n=100;
    vector<ll> a;
    for(int i=1; i<=n; i++) {
        a.push_back(i);
    }
    ll res=ask(a);
    ll ans=(res>>7)<<7;
    for(auto &i : a) {
        i<<=7;
    }
    res=ask(a);
    res&=(1<<7)-1;
    ans+=res;
    cout<<"! "<<ans<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    //(void)!freopen("input.txt", "r", stdin);
    //(void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

