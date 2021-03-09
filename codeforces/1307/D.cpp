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
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> special(k, vector<int> (2));
    for(auto &i : special) {
        cin>>i[1];
        i[1]--;
    }
    vector<vector<edge>> adjacency(n);
    while(m--) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        edge add(v, 1);
        adjacency[u].push_back(add);
        add.v=u;
        adjacency[v].push_back(add);
    }
    vector<int> start(n, n), end(n, n);
    dijkstra(0, adjacency, start);
    dijkstra(n-1, adjacency, end);
    for(auto &i : special) {
        i[0]=start[i[1]];
    }
    sort(special.rbegin(), special.rend());
    int ans=start[n-1], largest=0, add=0;
    bool first=true;
    for(auto i : special) {
        int option=start[i[1]]+1+largest;
        largest=max(largest, end[i[1]]);
        if(first) {
            first=false;
            continue;
        }
        if(option>=ans) {
            add=0;
            break;
        } 
        add=max(add, option);
    }
    if(add) {
        ans=add;
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
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}

