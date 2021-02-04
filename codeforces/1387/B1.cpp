#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n=1e5;
vector<vector<int>> adjacency(n+1);
vector<int> ans(n+1), connected(n+1);
queue<int> nodes;
int dist=0;

void go(int u) {
    dist+=2;
    for(auto v : adjacency[u]) {
        if(ans[v]==v) {
            swap(ans[u], ans[v]);
            for(auto next : adjacency[v]) {
                connected[v]--;
                connected[next]--;
                if(connected[next]==1 && ans[next]==next) {
                    nodes.push(next);
                }
            }
            return;
        }
    }
    int v=adjacency[u].front();
    swap(ans[u], ans[v]);
    return;
}

void solve() {
    cin>>n;
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
        connected[u]++;
        connected[v]++;
    }
    for(int i=1; i<=n; i++) {
        ans[i]=i;
        if(connected[i]==1) {
            nodes.push(i);
        }
    }
    while(!nodes.empty()) {
        int u=nodes.front();
        nodes.pop();
        if(ans[u]==u) {
            go(u);
        }
    }
    for(int i=1; i<=n; i++) {

    }
    cout<<dist<<endl;
    for(int i=1; i<=n; i++) {
        cout<<ans[i]<<" ";
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


