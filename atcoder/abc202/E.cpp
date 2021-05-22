#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(int u, vector<vector<int>> &adjacency, vector<int> &in, vector<int> &out, int d, int &curr, vector<vector<int>> &distances) { 
    in[u]=curr++;
    distances[d].push_back(in[u]);
    for(auto v : adjacency[u]) {
        go(v, adjacency, in, out, d+1, curr, distances);
    }
    out[u]=curr++;
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacency(n);
    for(int u=2; u<=n; u++) {
        int p;
        cin>>p;
        adjacency[p-1].push_back(u-1);
    }
    vector<int> in(n), out(n);
    vector<vector<int>> distances(n);
    int curr=0;
    go(0, adjacency, in, out, 0, curr, distances);
    int q;
    cin>>q;
    while(q--) {
        int u, d;
        cin>>u>>d;
        u--;
        int ans=lower_bound(distances[d].begin(), distances[d].end(), out[u])-lower_bound(distances[d].begin(), distances[d].end(), in[u]);
        cout<<ans<<endl;
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
    auto start=clock();
    int t = 1;
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}
