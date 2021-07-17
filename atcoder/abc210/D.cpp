#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int h, w;
    ll c;
    cin>>h>>w>>c;
    vector<vector<ll>> a(h, vector<ll> (w));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    vector<ll> up(w, 1e18);
    ll ans=1e18;
    for(int i=0; i<h; i++) {
        ll left=1e18;
        for(int j=0; j<w; j++) {
            up[j]+=c;
            left+=c;
            ans=min(ans, left+up[j]);
            ans=min(ans, a[i][j]+min(up[j], left));
            up[j]=min(up[j], a[i][j]);
            left=min(left, up[j]);
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
