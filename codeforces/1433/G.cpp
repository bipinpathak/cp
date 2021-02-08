#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge{
    int v, w;
    edge(int vi, int wi) : v{vi}, w{wi} {}
};

void dijkstra(int &s, vector<vector<edge>> &adjacency, vector<int> &dist) {
    set<pair<int, int>> active;
    dist[s]=0;
    active.insert({0, s});
    while(!active.empty()) {
        auto [curr, u] = *active.begin();
        active.erase(active.begin());
        if(dist[u]<curr) {
            continue;
        }
        for(auto [v, w] : adjacency[u]) {
            if(dist[v]>curr+w) {
                dist[v]=curr+w;
                active.insert({dist[v], v});
            }       
        }
    }
    return;
}

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<edge>> adjacency(n);
    vector<pair<int, int>> routes(k), roads(m);
    for(auto &i : roads) {
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        edge add(v, w);
        adjacency[u].emplace_back(add);
        add.v=u;
        adjacency[v].emplace_back(add);
        i={u, v};
    }
    for(auto &i : routes) {
        cin>>i.first>>i.second;
        i.first--,i.second--;
    }
    vector<vector<int>> dist(n, vector<int> (n, 1e9));
    for(int s=0; s<n; s++) {
        dijkstra(s, adjacency, dist[s]);
    }   
    int ans=1e9;
    for(auto [a, b] : roads) {
        int offer=0;
        for(auto [u, v] : routes) {
            int option=dist[u][v];
            option=min(option, dist[u][a]+dist[b][v]);
            option=min(option, dist[u][b]+dist[a][v]);
            offer+=option;
            }
        ans=min(ans, offer);
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
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

