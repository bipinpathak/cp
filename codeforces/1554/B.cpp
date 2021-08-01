#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    int start=n-1-2*k;
    start=max(start, 1);
    ll ans=-1e18;
    for(int i=start; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            ans=max(ans, (ll)i*j-(ll)k*(a[i]|a[j]));
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
    auto start=clock();
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

