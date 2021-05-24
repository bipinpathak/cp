#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fetch(int p, int u, int c, vector<vector<int>> &adjacency, vector<vector<ll>> &dp, vector<vector<ll>> &range) {
    if(dp[u][c]==-1) {
        dp[u][c]=0;
        for(auto v : adjacency[u]) {
            if(v==p) {
                continue;
            }
            ll offer=0;
            for(int vc=0; vc<2; vc++) {
                offer=max(offer, abs(range[u][c]-range[v][vc])+fetch(u, v, vc, adjacency, dp, range));
            }
            dp[u][c]+=offer;
        }
    }
    return dp[u][c];
}       

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacency(n);
    vector<vector<ll>> range(n, vector<ll> (2)), dp(n, vector<ll> (2, -1));
    for(auto &i : range) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }
    ll ans=max(fetch(-1, 0, 0, adjacency, dp, range), fetch(-1, 0, 1, adjacency, dp, range));
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

