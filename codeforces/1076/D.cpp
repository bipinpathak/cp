#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge{
    ll v, w;
    edge(ll vi, ll wi) : v(vi), w(wi) {}
};

void dijkstra(ll s, vector<vector<edge>> &adjacency, vector<ll> &dist) {
    for(auto &i : dist) {
        i=1e18;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> active;
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

void dfs(ll u, vector<ll> &visited, vector<vector<edge>> &adjacency, vector<ll> &dist, set<vector<ll>> &useful) {
    visited[u]=1;
    for(auto v : adjacency[u]) {
        if(!visited[v.v] && dist[u]+v.w==dist[v.v]) {
            useful.insert({u, v.v});
            dfs(v.v, visited, adjacency, dist, useful);
        }
    }
    return;
}

void bfs(vector<vector<edge>> &adjacency, vector<vector<ll>> &levels, set<vector<ll>> &useful) {
    queue<ll> curr;
    curr.push(0);
    while(!curr.empty()) {
        ll u=curr.front();
        curr.pop();
        for(auto v : adjacency[u]) {
            if(useful.count({u, v.v})) {
                curr.push(v.v);
                levels.push_back({u, v.v});
            }
        }
    }
    return;
}

void solve() {
    ll n, m, k;
    cin>>n>>m>>k;
    vector<vector<edge>> adjacency(n);
    vector<vector<ll>> order;
    for(ll i=0; i<m; i++) {
        ll x, y, w;
        cin>>x>>y>>w;
        x--, y--;
        order.push_back({x, y});
        edge add(y, w);
        adjacency[x].push_back(add);
        add.v=x;
        adjacency[y].push_back(add);
    }
    vector<ll> dist(n), visited(n);
    set<vector<ll>> useful;
    vector<vector<ll>> levels;
    dijkstra(0, adjacency, dist);
    dfs(0, visited, adjacency, dist, useful);
    bfs(adjacency, levels, useful);
    while((ll)useful.size()>k) {
        useful.erase(levels.back());
        levels.pop_back();
    }
    cout<<useful.size()<<endl;
    for(ll i=0; i<m; i++) {
        if(useful.count({order[i][0], order[i][1]}) || useful.count({order[i][1], order[i][0]})) {
            cout<<i+1<<" ";
        }
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

