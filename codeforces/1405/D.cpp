#include <bits/stdc++.h>
using namespace std;
int depth(int node, vector<vector<int>>& adjacency, vector<int>& visited, int& diameter) {
  int a = 0, b = 0, c;
  visited[node] = 1;
  for (int next : adjacency[node]) {
    if (!visited[next]) {
      c = 1 + depth(next, adjacency, visited, diameter);
      if (c > b) {
        swap(b, c);
      }
      if (b > a) {
        swap(a, b);
      }
      diameter = max(diameter, a + b);
    }
  }
  return a;
}
void solve() {
    int n, a, b, da, db, i, diameter=0, distance=0;
    cin>>n>>a>>b>>da>>db;
    vector<vector<int>> adjacency(n);
    vector<int> visited(n, 0);
    string ans="Alice";
    for(i=0; i<n-1; i++) {
        int x, y;
        cin>>x>>y;
        x--;
        y--;
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }
    diameter = max(diameter, depth(0, adjacency, visited, diameter));
    for(int &i : visited) i=0;
    queue<int>level;
    a--;
    b--;
    level.push(a);
    visited[a]=1;
    bool flag=true;
    while(flag) {
        n=level.size();
        distance++;
        while(flag && n--) {
            int node=level.front();
            level.pop();
            for(int i : adjacency[node]) {
                if(i==b) {
                    flag=false;
                    break;
                }
                if(!visited[i]) {
                    visited[i]=1;
                    level.push(i);
                }
            }
        }
    }
    if(distance>da && min(2*da+1, diameter+1)<=min(db, diameter)) ans="Bob";
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

