#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void go(int p, int u, vector<vector<int>> &adjacency, vector<ll> &dp) {
    for(auto v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        go(u, v, adjacency, dp);
        if(dp[v]>0) {
            dp[u]+=dp[v];
        }
    }
    return;
}

void calc(int p, int u, vector<vector<int>> &adjacency, vector<ll> &dp, ll &ans, ll &count) {
    for(auto v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        calc(u, v, adjacency, dp, ans, count);
        if(dp[v]>0) {
            dp[u]+=dp[v];
        }
    }
    if(dp[u]==ans) {
        dp[u]=0;
        count++;
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(auto &i : a) {
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
    auto dp = a;
    go(-1, 0, adjacency, dp);
    ll ans=-1e9, count=0;
    for(auto &i : dp) {
        ans=max(ans, i);
    }
    dp=a;
    calc(-1, 0, adjacency, dp, ans, count);
    cout<<ans*count<<" "<<count<<endl;
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

