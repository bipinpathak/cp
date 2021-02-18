#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge{
    int v, w;
    edge(int v, int w) : v(v), w(w) {}
};

void dijkstra(int s, vector<vector<edge>> &adjacency, vector<int> &dist) {
    set<pair<int, int>> active;
    dist[s]=0;
    active.insert({0, s});
    while(!active.empty()) {
        auto [curr, u] = *active.begin();
        active.erase(active.begin());
        if(dist[u]<curr) {
            continue;
        }
        for(auto [v1, w1] : adjacency[u]) {
            for(auto [v2, w2] : adjacency[v1]) {
                if(dist[v2]>curr+pow((w1+w2), 2)) {
                    dist[v2]=curr+pow((w1+w2), 2);
                    active.insert({dist[v2], v2});
                }       
            }
        }
    }
    return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<edge>> adjacency(n);
    while(m--) {
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        edge add(v, w);
        adjacency[u].push_back(add);
        add.v=u;
        adjacency[v].push_back(add);
    }
    vector<int> dist(n, INT_MAX);
    dijkstra(0, adjacency, dist);
    for(auto i : dist) {
        if(i==INT_MAX) {
            i=-1;
        }
        cout<<i<<" ";
    }
    cout<<endl;
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

