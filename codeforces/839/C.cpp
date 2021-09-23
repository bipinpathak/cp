#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;

void go(int p, int u, vector<vector<int>> &adjacency, ld curr, int d, vector<int> &len, vector<ld> &prob) {
    bool last=true;
    ld options=adjacency[u].size();
    if(u) {
        options--;
    }
    for(auto v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        last=false;
        go(u, v, adjacency, curr/options, d+1, len, prob);
    }
    if(last) {
        prob[u]=curr;
        len[u]=d;
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }
    vector<ld> prob(n);
    vector<int> len(n);
    go(-1, 0, adjacency, 1, 0, len, prob);
    ld ans=0;
    for(int i=0; i<n; i++) {
        if(len[i]) {
            ans+=(ld)len[i]*prob[i];
        }
    }
    cout<<fixed<<setprecision(10);
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

