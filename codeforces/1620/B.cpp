#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll w, h, ans=0;
    cin>>w>>h;
    int k;
    cin>>k;
    vector<ll> a(k);
    for(auto &i : a) {
        cin>>i;
    }
    ans=max(ans, h*(a.back()-a.front()));
    cin>>k;
    a.resize(k);
    for(auto &i : a) {
        cin>>i;
    }
    ans=max(ans, h*(a.back()-a.front()));
    cin>>k;
    a.resize(k);
    for(auto &i : a) {
        cin>>i;
    }
    ans=max(ans, w*(a.back()-a.front()));
    cin>>k;
    a.resize(k);
    for(auto &i : a) {
        cin>>i;
    }
    ans=max(ans, w*(a.back()-a.front()));
    cout<<ans<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

