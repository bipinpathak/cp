#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(int u, vector<int> &visited, vector<vector<int>> &adjacency, int &ans) {
    ans++;
    visited[u]=1;
    for(auto v : adjacency[u]) {
        if(!visited[v]) {
            go(v, visited, adjacency, ans);
        }
    }
    return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adjacency(n);
    while(m--) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adjacency[u].push_back(v);
    }
    int ans=0;
    for(int i=0; i<n; i++) {
        vector<int> visited(n);
        go(i, visited, adjacency, ans);
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

