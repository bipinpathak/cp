#include <bits/stdc++.h>
using namespace std;
void visit(int node, vector<int>&visited, vector<vector<int>>&adjacency, vector<int>&ans, vector<int>&path, int count, int k) {
   visited[node]=count;
   count++;
   path.push_back(node);
   if(ans.size()==0) {
        for(int next : adjacency[node]) {
            if(!visited[next]) visit(next, visited, adjacency, ans, path, count, k);
            else if(visited[next] && visited[node]-visited[next]+1>k) {
                while(path.back()!=next) {
                    ans.push_back(path.back());
                    path.pop_back();
                }
                ans.push_back(path.back());
            }
            if(ans.size()) return;
        }
   }
   path.pop_back();
   return;
}
void solve() {
    int n, m, k, i, x, y;
    cin>>n>>m>>k;
    vector<vector<int>> adjacency(n);
    vector<int> visited(n, 0), ans;
    for(i=0; i<m; i++) {
        cin>>x>>y;
        x--;
        y--;
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }
    for(i=0; i<n; i++) {
        if(!visited[i]) {
            vector<int> path;
            visit(i, visited, adjacency, ans, path, 1, k);
        }
        if(ans.size()) break;
    }
    cout<<ans.size()<<endl;
    for(int i : ans) cout<<i+1<<" ";
    cout<<endl;
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

