#include <bits/stdc++.h>
using namespace std;
int visit(int node, vector<vector<int>>&adjacency, vector<int>&visited) {
    int ans=1;
    visited[node]=1;
    for(int next : adjacency[node]) {
        if(!visited[next]) {
        ans+=visit(next, adjacency, visited);
        }
    }
    return ans;
}
void solve() {
    int n, m, k, i;
    cin>>n>>m>>k;
    vector<int> government(k);
    for(i=0; i<k; i++) {
        cin>>government[i];
        government[i]--;
    }
    vector<vector<int>>adjacency(n);
    for(i=0; i<m; i++) {
        int x, y;
        cin>>x>>y;
        x--;
        y--;
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }
    vector<int> visited(n, 0);
    for(i=0; i<k; i++) {
       government[i]=visit(government[i], adjacency, visited); 
    }
    sort(government.begin(), government.end());
    int left=n;
    for(i=0; i<k; i++) {
        left-=government[i];
    }
    government[k-1]+=left;
    long long ans=-m;
    for(int i : government) {
        ans+=(i*(i-1))/2;
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

