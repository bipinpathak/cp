#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void go(int p, int u, vector<vector<int>> &adjacency, vector<int> &low, vector<int> &high, int &count) {
    for(auto &v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        go(u, v, adjacency, low, high, count);
        low[u]=min(low[u], low[v]);
        high[u]=max(high[u], high[v]);
    }
    if(low[u]>high[u]) {
        low[u]=high[u]=count;
        count++;
    }
    return;
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
    vector<int> low(n, n), high(n, 0);
    int count=1;
    go(-1, 0, adjacency, low, high, count);
    for(int i=0; i<n; i++) {
        cout<<low[i]<<" "<<high[i]<<endl;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

