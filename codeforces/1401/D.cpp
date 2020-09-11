#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &visited, vector<vector<int>> &adjacency, vector<int>&weight, vector<long long> &count) {
    visited[node]=1;
    for(int next : adjacency[node]) {
        if(!visited[next]) {
            dfs(next, visited, adjacency, weight, count);
            weight[node]+=weight[next]+1;
            count.push_back(weight[next]+1);
        }
    }
}
void solve() {
    int n, i, m, p=1e9+7, ans=0;
    cin>>n;
    vector<vector<int>> adjacency(n);
    for(i=1; i<n; i++) {
        int x, y;
        cin>>x>>y;
        x--;
        y--;
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }
    cin>>m;
    vector<long long> factors(m);
    for(auto &i : factors) cin>>i;
    vector<int> visited(n, 0), weight(n, 0);
    vector<long long> count;
    dfs(0, visited, adjacency, weight, count);
    for(auto &i : count) i=i*(n-i);
    while((int)factors.size()<n-1) factors.push_back(1);
    sort(factors.begin(), factors.end());
    sort(count.begin(), count.end());
    while((int)factors.size()>n-1) {
        m=factors.size();
        factors[m-2]=(factors[m-2]*factors[m-1])%p;
        factors.pop_back();
    }
    ans=0;
    for(i=0; i<n-1; i++) {
        ans=(ans+(factors[i]*count[i])%p)%p;
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

