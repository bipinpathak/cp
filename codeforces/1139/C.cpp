#include <bits/stdc++.h>
using namespace std;
void visit(int node, vector<vector<int>>& adjacency, vector<int>&visited, int &count) {
    visited[node]=1;
    count++;
    for(int next : adjacency[node]) {
        if(!visited[next]) visit(next, adjacency, visited, count);
    }
}
int calc(int n, int k) {
    long long ans=1, p=1e9+7;
    while(k>0) {
        ans=(ans*n)%p;
        k--;
    }
    return ans;
}
void solve() {
    int n, k, i, u, v, type, ans, p=1e9+7;
    cin>>n>>k;
    ans=calc(n, k);
    vector<vector<int>> adjacency(n);
    vector<int> visited(n, 0);
    for(i=1; i<n; i++) {
        cin>>u>>v>>type;
        if(!type) {
            u--, v--;
            adjacency[u].push_back(v);
            adjacency[v].push_back(u);
        }
    }
    for(i=0; i<n; i++) {
        if(!visited[i]) {
            int count=0;
            visit(i, adjacency, visited, count);
            ans=(ans-calc(count, k))%p;
            ans=(ans+p)%p;
        }
    }
    cout<<ans<<endl;
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

