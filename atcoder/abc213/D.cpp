#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int p, int u, vector<vector<int>> &adjacency, vector<int> &ans) {
    ans.push_back(u);
    for(auto v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        dfs(u, v, adjacency, ans);
        ans.push_back(u);
    }   
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }
    for(auto &i : adjacency) {
        sort(i.begin(), i.end());
    }
    vector<int> ans;
    dfs(-1, 0, adjacency, ans);
    for(auto i : ans) {
        cout<<i+1<<" ";
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

