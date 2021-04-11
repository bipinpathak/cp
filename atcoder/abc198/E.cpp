#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(int u, vector<vector<int>> &adjacency, vector<int> &good, map<int, int> &seen, vector<int> &color) {
    good[u]=1;
    if(seen[color[u]]) {
        good[u]=0;
    }
    seen[color[u]]++;
    for(auto v : adjacency[u]) {
        if(good[v]==-1) {
            go(v, adjacency, good, seen, color);
        }
    }
    seen[color[u]]--;
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<int> color(n);
    for(auto &i : color) {
        cin>>i;
    }
    vector<vector<int>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int x, y;
        cin>>x>>y;
        x--, y--;
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }
    vector<int> good(n, -1);
    map<int, int> seen;
    go(0, adjacency, good, seen, color);
    for(int i=0; i<n; i++) {
        if(good[i]) {
            cout<<i+1<<endl;
        }
    }
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

