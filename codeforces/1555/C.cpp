#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int m;
    cin>>m;
    vector<vector<int>> a(2, vector<int> (m));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    int ans=1e9, low=0, high=0;
    for(int i=0; i<m; i++) {
        high+=a[0][i];
    }
    for(int i=0; i<m; i++) {
        high-=a[0][i];
        ans=min(ans, max(low, high));
        low+=a[1][i];
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

