#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void dijkstra(int s, vector<vector<int>> &adjacency, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> active;
    dist[s]=0;
    active.push({0, s});
    while(!active.empty()) {
        auto [curr, u] = active.top();
        active.pop();
        if(dist[u]<curr) {
            continue;
        }
        for(auto v : adjacency[u]) {
            if(dist[v]>curr+1) {
                dist[v]=curr+1;
                active.push({dist[v], v});
            }       
        }
    }
    return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adjacency(n), rAdjacency(n);
    while(m--) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adjacency[u].push_back(v);
        rAdjacency[v].push_back(u);
    }
    int k;
    cin>>k;
    vector<int> path(k);
    for(auto &i : path) {
        cin>>i;
        i--;
    }
    vector<int> dist(n, 1e6);
    dijkstra(path.back(), rAdjacency, dist);
    int low=0, high=0;
    for(int i=0; i+1<k; i++) {
        int u=path[i], v=path[i+1];
        if(dist[u]!=dist[v]+1) {
            low++;
            high++;
        } else for(auto z : adjacency[u]) {
            if(dist[u]==dist[z]+1 && z!=v) {
                high++;
                break;
            }
        }
    }
    cout<<low<<" "<<high<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

