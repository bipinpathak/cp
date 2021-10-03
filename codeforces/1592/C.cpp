#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int go(int p, int u, vector<vector<int>> &adjacency, vector<int> &val, int &total, string &ans) {
    int count=0;
    for(auto v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        count+=go(u, v, adjacency, val, total, ans);
        val[u]^=val[v];
        if(ans=="Yes") {
            break;
        }
    }
    if(count+(val[u]==0)>=2) {
        ans="Yes";
    }
    count+=val[u]==total;
    return count;
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> val(n);
    int total=0;
    for(auto &i : val) {
        cin>>i;
        total^=i;
    }
    vector<vector<int>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }
    string ans="No";
    if(total==0) {
        ans="Yes";
    } else if(k>=3) {
        go(-1, 0, adjacency, val, total, ans);
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

