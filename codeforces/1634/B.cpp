#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll n, x, y;
    cin>>n>>x>>y;
    x&=1;
    y&=1;
    while(n--) {
        ll a;
        cin>>a;
        x^=(a&1);
    }
    string ans=(x==y)?"Alice":"Bob";
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

