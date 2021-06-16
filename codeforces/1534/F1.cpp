#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(int u, vector<int> &visited, vector<vector<int>> &adjacency, vector<int> &order) {
    visited[u]=1;
    for(auto v : adjacency[u]) {
        if(!visited[v]) {
            go(v, visited, adjacency, order);
        }
    }
    order.push_back(u);
    return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char> (m));
    for(auto &i : grid) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    vector<int> a(m);
    for(auto &i : a) {
        cin>>i;
    } 
    vector<vector<int>> id(n, vector<int> (m, -1));
    int total=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j]=='#') {
                id[i][j]=total;
                total++;
            }       
        }
    }
    vector<vector<int>> adjacency(total), rev(total);
    for(int j=0; j<m; j++) {
        int curr=-1;
        for(int i=0; i<n; i++) {
            if(curr!=-1 && id[i][j]!=-1) {
                adjacency[curr].push_back(id[i][j]);
                if(i-1>=0 && id[i-1][j]!=-1) {
                    adjacency[id[i][j]].push_back(curr); 
                }
            }
            if(id[i][j]!=-1) {
                curr=id[i][j];
            }
            if(curr!=-1) {
                if(j+1<m && id[i][j+1]!=-1) {
                        adjacency[curr].push_back(id[i][j+1]);
                }
                if(j-1>=0 && id[i][j-1]!=-1) {
                    adjacency[curr].push_back(id[i][j-1]);
                }
            }
        }
    }
    for(int u=0; u<total; u++) {
        for(auto v : adjacency[u]) {
            rev[v].push_back(u);
        }
    }
    vector<int> visited(total), order;
    for(int u=0; u<total; u++) {
        if(!visited[u]) {
            go(u, visited, adjacency, order);
        }
    }
    reverse(order.begin(), order.end());
    vector<int> sccID(total);
    visited.assign(total, 0);
    int counter=0;
    for(auto u : order) {
        if(!visited[u]) {
            vector<int> scc;
            go(u, visited, rev, scc);
            for(auto v : scc) {
                sccID[v]=counter;
            }
            counter++;
        }
    }
    vector<int> incoming(counter);
    for(int u=0; u<total; u++) {
        for(auto v : adjacency[u]) {
            if(sccID[v]!=sccID[u]) {
                incoming[sccID[v]]++;
            }
        }
    }
    int ans=0;
    for(auto i : incoming) {
        ans+=!i;
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

