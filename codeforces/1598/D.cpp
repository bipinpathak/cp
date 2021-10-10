#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> difficulty(n), topic(n);
    for(int i=0; i<n; i++) {
        ll a, b;
        cin>>a>>b;
        a--, b--;
        difficulty[b].push_back(a);
    }
    ll ans=0, one=0, two=0, total=0;
    for(auto i : difficulty) {
        if(i.empty()) {
            continue;
        }
        ll curr=(int)i.size();
        ans+=two*curr;
        two+=one*curr;
        one+=curr;
        if(curr>=3) {
            ans+=(curr*(curr-1)*(curr-2))/6;
        }
        if(curr>=2) {
            total+=(curr*(curr-1))/2;
        }
        for(auto j : i) {
            topic[j].push_back(curr);
        }
    }
    for(auto i : topic) {
        if(i.empty()) {
            continue;
        }
        ll x=0;
        for(auto j : i) {
            x+=j-1;
        }
        for(auto j : i) {
            ll s=j;
            ll offer=total-x-((s-1)*(s-2))/2;
            ans+=offer;
        }
    }
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

