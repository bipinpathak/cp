#include <bits/stdc++.h>
using namespace std;
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
    int n, m, i, j;
    cin>>n>>m;
    vector<string> grid(n);
    for(i=0; i<n; i++) {
        cin>>grid[i];
    }
    unordered_map<int, int> idToCount;
    vector<vector<int>> id(n, vector<int> (m, 0)), visited(n, vector<int> (m, 0));
    int idCount=1;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if(grid[i][j]=='.' && !visited[i][j]) {
                int s=0;
                build(i, j, idCount, s, visited, id, grid);
                idToCount[idCount]=s;
                idCount++;
            }
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if(grid[i][j]=='.') {
                grid[i][j]='.';
            } else {
                int s=1;
                set<int> temp;
                if(i+1<n && temp.find(id[i+1][j])==temp.end()) {
                    s+=idToCount[id[i+1][j]];
                    temp.insert(id[i+1][j]);
                }if(i-1>=0 && temp.find(id[i-1][j])==temp.end()) {
                    s+=idToCount[id[i-1][j]];
                    temp.insert(id[i-1][j]);
                }if(j+1<m && temp.find(id[i][j+1])==temp.end()) {
                    s+=idToCount[id[i][j+1]];
                    temp.insert(id[i][j+1]);
                }if(j-1>=0 && temp.find(id[i][j-1])==temp.end()) {
                    s+=idToCount[id[i][j-1]];
                    temp.insert(id[i][j-1]);
                }
                grid[i][j]='0'+s%10;
            }       
        }
    }
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
