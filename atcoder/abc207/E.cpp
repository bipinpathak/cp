#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=1e9+7;

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<ll> prev(n, 1);
    ll ans=1;
    for(int k=2; k<=n; k++) {
        vector<ll> seen(n), update(n);
        ll sum=0;
        for(int i=0; i<n; i++) {
            sum+=a[i];
            ll rem=sum%k;
            update[i]=(update[i]+seen[rem])%mod;
            seen[rem]=(seen[rem]+prev[i])%mod;
        }
        ans=(ans+update[n-1])%mod;
        prev=update;
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
    auto start=clock();
    int t = 1;
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

