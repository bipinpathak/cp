#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll mod=998244353;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<vector<ll>> count(n+5, vector<ll> (2, 0));
    for(auto &i : a) {
        cin>>i;
        if(i-1>=0) {
            count[i-1][1]=(count[i-1][1]+count[i-1][1]+count[i-1][0])%mod;
        }
        count[i+1][0]=(count[i+1][0]+count[i+1][0]+count[i][0])%mod;
        count[i+1][1]=(count[i+1][1]+count[i+1][1])%mod;
        if(i<=1) {
            count[!i][i]++;
            count[!i][i]%=mod;
        }
    }
    ll ans=0;
    for(int i=0; i<=n+1; i++) {
        for(int j=0; j<2; j++) {
            ans=(ans+count[i][j])%mod;
        }
    }
    if(ans<0) {
        ans+=mod;
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

