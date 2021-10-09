#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void pre(int p, int u, vector<vector<int>> &adjacency, vector<int> &height) {
    for(auto v : adjacency[u]) {
        if(v!=p) {
            height[v]=height[u]+1;
            pre(u, v, adjacency, height);
        }
    }
    return;
}

void go(int p, int u, int target, vector<vector<int>> &adjacency, vector<int> &count, bool &done, vector<int> &height) {
    if(u==target) {
        done=true;
        return;
    }
    for(auto v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        if(height[v]>height[u]) {
            count[v]++;
        } else {
            count[u]++;
        }
        go(u, v, target, adjacency, count, done, height);
        if(done) {
            return;
        }
        if(height[v]>height[u]) {
            count[v]--;
        } else {
            count[u]--;
        }
    }
    return;
}   

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> order(m);
    for(auto &i : order) {
        cin>>i;
        i--;
    }
    vector<vector<int>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }
    vector<int> height(n), count(n);
    pre(-1, 0, adjacency, height);
    for(int i=0; i+1<m; i++) {
        bool done=false; 
        go(-1, order[i], order[i+1], adjacency, count, done, height);
    }
    reverse(count.begin(), count.end());
    count.pop_back();
    int total=0;
    for(auto i : count) {
        total+=i;
    }
    int ans=0, mod=998244353;
    if(total%2==abs(k)%2 && total>=k) {
        int target=(total-k)/2;
        vector<int> dp(target+1);
        dp[0]=1;
        for(auto i : count) {
            for(int j=target; j>=i; j--) {
                dp[j]=(dp[j]+dp[j-i])%mod;
            }
        }
        ans=dp[target];
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

