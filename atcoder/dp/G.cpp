#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(int u, vector<vector<int>> &adjacency, vector<int> &visited, int &ans) {
    visited[u]=1;
    for(auto v : adjacency[u]) {
        if(!visited[v]) {
            go(v, adjacency, visited, ans);
        }
        visited[u]=max(visited[u], 1+visited[v]);
    }
    ans=max(ans, visited[u]);
    return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adjacency(n);
    while(m--) {
        int x, y;
        cin>>x>>y;
        x--, y--;
        adjacency[x].push_back(y);
    }
    vector<int> visited(n);
    int ans=0;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            go(i, adjacency, visited, ans);
        }
    }
    ans--;
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
    //cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

