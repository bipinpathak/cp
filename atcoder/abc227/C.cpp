#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll n, ans=0;
    cin>>n;
    for(ll a=1; a*a*a<=n; a++) {
        for(ll b=a; a*b*b<=n; b++) {
            ll high=n/(a*b);
            ans+=high-b+1;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

