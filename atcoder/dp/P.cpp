#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=1e9+7;

vector<ll> fetch(int p, int u, vector<vector<int>> &adjacency) {
    vector<ll> ans(2, 1);
    for(auto v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        auto add = fetch(u, v, adjacency);
        ans[0]=(ans[0]*(add[0]+add[1]))%mod;
        ans[1]=(ans[1]*add[0])%mod;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }
    auto color=fetch(-1, 0, adjacency);
    ll ans=0;
    for(auto i :color) {
        ans=(ans+i)%mod;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

