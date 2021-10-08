#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll mod=1e9+7;

void solve() {
    ll n, k;
    cin>>n>>k;
    ll ans=0, p=1;
    while(k) {
        if(k&1) {
            ans=(ans+p)%mod;
        }
        p=(p*n)%mod;
        k>>=1;
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

