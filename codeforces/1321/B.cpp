#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> b(n);
    map<int, ll> sum;
    for(int i=0; i<n; i++) {
        cin>>b[i];
        sum[b[i]-i]+=b[i];
    }
    ll ans=0;
    for(auto &[key, val] : sum) {
        ans=max(ans, val);
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

