#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(int u, vector<vector<int>> &adjacency, bool &possible, vector<int> &val) {
    for(auto v : adjacency[u]) {
        if(val[u]<=val[v]) {
            val[v]-=adjacency.size()-1;
            if(val[v]<=0) {
                possible=false;
            } else {
                go(v, adjacency, possible, val);
            }
        }
        if(!possible) {
            return;
        }
    }
    return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> words(n);
    for(auto &i : words) {
        int l;
        cin>>l;
        while(l--) {
            int s;
            cin>>s;
            i.push_back(s);
        }
    }
    vector<vector<int>> adjacency(m+1);
    vector<int> val(m+1);
    for(int i=1; i<=m; i++) {
        val[i]=m+i;
    }
    for(int i=0; i<n-1; i++) {
        bool found=false;
        for(int j=0; j<(int)min(words[i].size(), words[i+1].size()) && !found; j++) {
            if(words[i][j]!=words[i+1][j]) {
                adjacency[words[i+1][j]].push_back(words[i][j]);
                found=true;
            }
        }
        if(!found && words[i].size()>words[i+1].size()) {
            cout<<"No"<<endl;
            return;
        }
    }
    bool possible=true;
    for(int i=1; i<=m && possible; i++) {
        go(i, adjacency, possible, val);
    }
    for(int u=1; u<=m && possible; u++) {
        for(auto v : adjacency[u]) {
            if(val[v]>=val[u]) {
                possible=false;
                break;
            }
        }
    }
    if(!possible) {
        cout<<"No"<<endl;
        return;
    }
    vector<int> ans;
    for(int i=1; i<=m; i++) {
        if(val[i]!=m+i) {
            ans.push_back(i);
        }
    }
    int k=ans.size();
    cout<<"Yes"<<endl<<k<<endl;
    for(auto i : ans) {
        cout<<i<<" ";
    }
    if(k) {
        cout<<endl;
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
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

