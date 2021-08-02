#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge{
    int v, w;
    edge(int vi, int wi) : v(vi), w(wi) {}
};

void dijkstra(int s, vector<vector<edge>> &adjacency, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> active;
    dist[s]=0;
    active.push({0, s});
    while(!active.empty()) {
        auto [curr, u] = active.top();
        active.pop();
        if(dist[u]<curr) {
            continue;
        }
        for(auto [v, w] : adjacency[u]) {
            if(dist[v]>curr+w) {
                dist[v]=curr+w;
                active.push({dist[v], v});
            }       
        }
    }
    return;
}
void solve() {
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> antennas(n);
    for(auto &i : antennas) {
        cin>>i.first>>i.second;
    }
    vector<vector<edge>> adjacency(m+1);
    for(int i=1; i<=m; i++) {
        edge add(i-1, 0);
        adjacency[i].push_back(add);
    }
    for(auto [x, s] : antennas) {
        for(int i=0; x-i>=1 || x+i<=m; i++) {
            int low=max(x-i, 1), high=min(x+i, m), cost=max(0, i-s); 
            edge add(high, cost);
            adjacency[low-1].push_back(add);
        }
    }
    vector<int> dist(m+1, m);
    dijkstra(0, adjacency, dist);
    cout<<dist[m]<<endl;
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

