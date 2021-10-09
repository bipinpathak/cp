#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct edge{
    int v;
    ll w;
    edge(int vi, ll wi) : v(vi), w(wi) {}
};

void dfs(int p, int u, vector<vector<edge>> &adjacency, vector<ll> &d, vector<ll> &down) {
    for(auto [v, w] : adjacency[u]) {
        if(v==p) {
            continue;
        }
        dfs(u, v, adjacency, d, down);
        down[u]=max(down[u], w+max(down[v], d[v]));
    }
    return;
}

void go(int p, int u, vector<vector<edge>> &adjacency, vector<ll> &d, vector<ll> &down, ll top) {
    down[u]=max(down[u], top);
    vector<vector<ll>> options={{top, p}};
    options.push_back({d[u], u});
    for(auto [v, w] : adjacency[u]) {
        if(v==p) {
            continue;
        }
        options.push_back({w+max(down[v], d[v]), v});
    }
    sort(options.rbegin(), options.rend());
    for(auto [v, w] : adjacency[u]) {
        if(v==p) {
            continue;
        }
        top=options[0][0];
        if(v==options[0][1]) {
            top=options[1][0];
        }
        top+=w;
        go(u, v, adjacency, d, down, top);
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<edge>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        edge add(b, c);
        adjacency[a].push_back(add);
        add.v=a;
        adjacency[b].push_back(add);
    }
    vector<ll> d(n);
    for(auto &i : d) {
        cin>>i;
    }
    vector<ll> down(n);
    dfs(-1, 0, adjacency, d, down);
    go(-1, 0, adjacency, d, down, 0);
    for(auto &i : down) {
        cout<<i<<endl;
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

