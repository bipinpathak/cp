#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void build(int p, int u, vector<vector<int>> &adjacency, vector<vector<int>> &store, vector<int> &a) {
    set<vector<int>> options;
    for(auto &v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        build(u, v, adjacency, store, a);
        options.insert({-store[v][0], v, 0});
    }
    for(int i=0; i<20 && !options.empty(); i++) {
        auto best=*options.begin();
        if(best[0]==0) {
            break;
        }
        options.erase(options.begin());
        store[u][i]=-best[0];
        if(best[2]+1<20) {
            best[2]++;
            best[0]=-store[best[1]][best[2]];
            options.insert(best);
        }
    }
    for(int i=19; i>=0 && a[u]>store[u][i]; i--) {
        if(i+1<20) {
            swap(store[u][i], store[u][i+1]);
        } else {
            store[u][i]=a[u];
        }
    }
    return;
}

void solve() {
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    for(auto &i: a) {
        cin>>i;
    }
    vector<vector<int>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }
    vector<vector<int>> store(n, vector<int> (20));
    build(-1, 0, adjacency, store, a);
    while(q--) {
        int v, k;
        cin>>v>>k;
        v--, k--;
        cout<<store[v][k]<<endl;
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

