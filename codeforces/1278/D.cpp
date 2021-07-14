#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int p, int u, vector<int> &visited, vector<vector<int>> &adjacency, string &ans) {
    visited[u]=1;
    for(auto v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        if(visited[v]) {
            ans="NO";
        } else {
            dfs(u, v, visited, adjacency, ans);
        }
        if(ans=="NO") {
            break;
        }
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int> (2));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    sort(a.begin(), a.end());
    string ans="YES";
    map<int, int> active;
    vector<vector<int>> adjacency(n);
    int total=0;
    for(int i=0; i<n; i++) {
        while(!active.empty() && active.begin()->first<a[i][0]) {
            active.erase(active.begin());
        }
        for(auto j : active) {
            if(j.first>a[i][1]) {
                break;
            }
            adjacency[i].push_back(j.second);
            adjacency[j.second].push_back(i);
            total+=2;
        }
        active[a[i][1]]=i;
        if(total>2*(n-1)) {
            ans="NO";
            break;
        }
    }
    vector<int> visited(n);
    dfs(-1, 0, visited, adjacency, ans);
    for(auto i : visited) {
        if(!i) {
            ans="NO";
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

