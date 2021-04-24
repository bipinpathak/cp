#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool go(int u, vector<vector<int>> &adjacency, vector<int> &color) {
    bool ans=true; 
    for(auto v : adjacency[u]) {
        if(color[v]==2) {
            continue;
        }
        if(color[v]==-1) {
            color[v]=!color[u];
            ans=ans&go(v, adjacency, color);
        } else if(color[v]==color[u]) {
            ans=false;
        }
        if(ans==false) {
            break;
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adjacency(n);
    while(m--) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }
    vector<set<int>> red(1);
    for(int u=0; u<n; u++) {
        m=(int) red.size();
        for(int j=0; j<m; j++) {
            bool good=true;
            for(auto v : adjacency[u]) {
                if(red[j].count(v)) {
                    good=false;
                    break;
                }
            }
            if(good) {
                red.push_back(red[j]);
                red.back().insert(u);
            }
        }
    }
    ll ans=0;
    for(auto k : red) {
        vector<int> color(n, -1);
        for(auto u : k) {
            color[u]=2;
        }
        bool bipartile=true;
        int components=0;
        for(int u=0; u<n && bipartile; u++) {
            if(color[u]==-1) {
                color[u]=0;
                bipartile=go(u, adjacency, color); 
                components++;
            }
        }
        if(bipartile) {
            ll add=1;
            while(components--) {
                add*=2;
            }
            ans+=add;
        }
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

