#include <bits/stdc++.h>
using namespace std;
void fill(int x, int y, vector<string>&grid) {
    grid[x][y]='!';
    int n=grid.size(), m=grid[0].size();
    if(x+1<n && grid[x+1][y]=='.') fill(x+1, y, grid);
    if(x-1>=0 && grid[x-1][y]=='.') fill(x-1, y, grid);
    if(y+1<m && grid[x][y+1]=='.') fill(x, y+1, grid);
    if(y-1>=0 && grid[x][y-1]=='.') fill(x, y-1, grid);
}
void build(int i, int j, int idCount, int&s,  vector<vector<int>>&visited, vector<vector<int>>&id, vector<string>&grid) {
    visited[i][j]=1;
    s+=1;
    id[i][j]=idCount;
    int n=grid.size(), m=grid[0].size();
    if(i+1<n && !visited[i+1][j] && grid[i+1][j]=='.') build(i+1, j, idCount, s, visited, id, grid);
    if(i-1>=0 && !visited[i-1][j] && grid[i-1][j]=='.') build(i-1, j, idCount, s, visited, id, grid);
    if(j+1<m && !visited[i][j+1] && grid[i][j+1]=='.') build(i, j+1, idCount, s, visited, id, grid);
    if(j-1>=0 && !visited[i][j-1] && grid[i][j-1]=='.') build(i, j-1, idCount, s, visited, id, grid);
    return;
}
void solve() {
    int n, m, i, j, k;
    cin>>n>>m>>k;
    vector<string> grid(n);
    for(i=0; i<n; i++) {
        cin>>grid[i];
    }
    vector<pair<int, int>> lakes; 
    vector<vector<int>> id(n, vector<int> (m, 0)), visited(n, vector<int> (m, 0));
    for(i=0; i<n; i++) {
        if(grid[i][0]=='.') {
            fill(i, 0, grid);
        }
        if(grid[i][m-1]=='.') {
            fill(i, m-1, grid);
        }
    }
    for(i=0; i<m; i++) {
        if(grid[0][i]=='.') {
            fill(0, i, grid);
        }
        if(grid[n-1][i]=='.') {
            fill(n-1, i, grid);
        }
    }
    int idCount=1;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if(grid[i][j]=='.' && !visited[i][j]) {
                int s=0;
                build(i, j, idCount, s, visited, id, grid);
                lakes.push_back(make_pair(s, idCount)); 
                idCount++;
            }
        }
    }
    sort(lakes.begin(), lakes.end());
    reverse(lakes.begin(), lakes.end());
    unordered_set<int> markedForFilling;
    int ans=0;
    for(i=lakes.size()-1; i>=k; i--) {
        markedForFilling.insert(lakes[i].second);
        ans+=lakes[i].first;
    }
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if(grid[i][j]=='!') {
                grid[i][j]='.';
            } else if(markedForFilling.find(id[i][j])!=markedForFilling.end()) {
                grid[i][j]='*';
            }
        }
    }
    cout<<ans<<endl;
    for(i=0; i<n; i++) {
        cout<<grid[i]<<endl;
    }
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
   // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
