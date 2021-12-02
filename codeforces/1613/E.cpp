#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<pair<int,int>> d={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int options(int x, int y, vector<string> &grid) {
    int ans=0, n=(int)grid.size(), m=(int)grid[0].size();
    for(auto &[dx, dy] : d) {
        int xi=x+dx, yi=y+dy;
        if(0<=xi && xi<n && 0<=yi && yi<m && grid[xi][yi]=='.') {
            ans++; 
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin>>n>>m;
    queue<pair<int, int>> active;
    vector<string> grid(n);
    for(int i=0; i<n; i++) {
        cin>>grid[i];
        for(int j=0; j<m; j++) {
            if(grid[i][j]=='L') {
                    active.push({i, j});
            }
        }
    }
    while(!active.empty()) {
        auto [x, y]=active.front();
        active.pop();
        for(auto &[dx, dy] : d) {
            int xi=x+dx, yi=y+dy;
            if(0<=xi && xi<n && 0<=yi && yi<m && grid[xi][yi]=='.' && options(xi, yi, grid)<=1) {
                grid[xi][yi]='+';
                active.push({xi, yi});
            }
        }
    }
    for(auto &i : grid) {
        cout<<i<<'\n';
    }
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

