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
    vector<vector<edge>> given(n);
    while(m--) {
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        edge add(v, w);
        given[u].push_back(add);
        add.v=u;
        given[v].push_back(add);
    }
    vector<vector<edge>> adjacency(101*n);
    for(int u=0; u<n; u++) {
        vector<int> have(51);
        for(auto [v, w] : given[u]) {
            have[w]=1;
        }
        for(int i=1; i<=50; i++) {
            for(int j=1; j<=50 && have[i]; j++) {
                if(have[j]) {
                    edge add(101*u+50+j, 2*i*j);
                    adjacency[101*u+i].push_back(add);
                }
            }
        } 
        for(auto [v, w] : given[u]) {
            edge add(101*u+w, w*w);
            adjacency[101*v].push_back(add);
            add.v=101*v;
            adjacency[101*u+50+w].push_back(add);
        }
    }
    vector<int> ans(101*n, 1e9);
    dijkstra(0, adjacency, ans);
    for(int i=0; i<n; i++) {
        if(ans[101*i]==(int)1e9) {
            ans[101*i]=-1;
        }
        cout<<ans[101*i]<<" ";
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

